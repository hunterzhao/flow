#include <iostream>
#include <mutex>
#include <condition_variable>
#include <memory>
#include <uv.h>

#include "flow_client.h"
#include "flow_loop.h"
#include "flow_stage.h"
#include "flow_message.h"
#include "flow_log.h"
#include "flow_manager.h"

using namespace flow;
static int connects = 1; //number of connects
static std::condition_variable cv;
static std::mutex mtx_;
class TestActor : public FlowActor {
public:
    TestActor(std::string id) : FlowActor(id) {}
    ~TestActor() {};
    int OnStart() {
        LOG->trace("hello, i am actor, start");
        Subscribe("x1","topic");
              // conn receiver data
        Request("x1","happy", "topic", "happy new year");
    }
    int OnEvent(Event e) {
        LOG->trace("TestActor topic: {}", e.topic);
        LOG->trace("TestActor msg: {}", e.msg);
    }
    int OnStop() {
        LOG->trace("hello, i am actor, over");
    }

};

class  TestClient : public FlowClient {
public:
    TestClient(LoopPtr loop, FlowManagerPtr manager) : FlowClient(loop, manager) {}
    ~TestClient(){};

    void OnConnected() {
        LOG->info("one connect have been set");
        std::unique_lock<std::mutex> lck(mtx_);
        manager_->AddConn("x1", this);  //only add to env ,can only the stage send message
        connects--;
        cv.notify_one(); 
    }

    void OnMessage(FlowMessagePtr msg, uv_stream_t* tcp) {
        LOG->info("TestClient: {}", msg->GetOptionStr("data"));
    }
};
class TestStage : public FlowStage {
public:
    TestStage(FlowQueuePtr q, int id): FlowStage(q, id)  {
       //add actors
        FlowActorPtr actor1(new TestActor("test"));
        AddActor(actor1);
    }

    ~TestStage() {}
    
    int OnStart() {
        FlowStage::OnStart();
        return 1;
    }
    
    int OnEvent(FlowMessagePtr msg) {
       //send msg to specific actor
       std::string receiver = msg->GetOptionStr("receiver");
       Event e;
       e.msg = msg->GetOptionStr("data");
       e.topic = msg->GetOptionStr("topic");

       auto it = actorMap_.find(receiver);
       if (it != actorMap_.end())
          it->second->OnEvent(e);
        else
          LOG->error("the receiver {} doesn't exist", receiver); 
       return 1;
    }

    int OnStop(FlowMessagePtr msg) {
       //iterator execute the actor end
        FlowStage::OnStop();
       return 1;
    }

};

void make_stage(FlowManagerPtr manager) {
   std::unique_lock<std::mutex> lck(mtx_);
   cv.wait(lck, [&connects] { return connects==0;});  // all the connects have been set
   LOG->info("all connects have been set, start to make stage"); //slow the speed, one stage won't use all connects
   int stageid = 321;
   FlowQueuePtr p = FlowQueueMgr::Instance().CreateQueue(stageid);
   FlowStagePtr stageA(new TestStage(p, stageid));
   stageA->SetManager(manager);
   manager->AddStage(stageid, stageA);
   std::thread tha([&stageA]() {stageA->Run();});
   tha.join();
}

DEFINE_SHARED_PTR(TestClient);

int main(int args, char* argv[]) {
    FLOWLOG_TRY {
        LoopPtr loop (new Loop);
        FlowManagerPtr manager(new FlowManager);
        FlowLog::SetLevel(FlowLog::Trace);
        //client:
        //TestClientPtr client(new TestClient(loop, manager));
        TestClient* client = new TestClient(loop, manager);
        
        struct sockaddr_in addr;
        ASSERT(0 == uv_ip4_addr("0.0.0.0", 9123, &addr));  //set server target
        client->Connect(&addr);
        
        std::thread startStages(make_stage, manager);
        startStages.detach();
        

        //continue add stage

        loop->loop_run(Loop::RUN_DEFAULT);
    }FLOWLOG_CATCH
    // delete loop;
    // delete server;
    return 0;
}