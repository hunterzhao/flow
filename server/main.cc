#include <thread>
#include <iostream>
#include <csignal>
#include <memory>
#include <uv.h>

#include "flow_server.h"
#include "flow_loop.h"
#include "flow_stage.h"
#include "flow_actor.h"
#include "flow_session.h"
#include "flow.h"
#include "flow_log.h"
#include "flow_manager.h"
#include "flow_publisher.h"

using namespace flow;

int stop = 0;
void handler(int sigcode) {
   LOG->warn("interrupt {} received",sigcode);
   stop=1;
   exit(sigcode);
   //exit(sigcode);
}

class TestActor : public FlowActor {
public:
  TestActor(std::string id) : FlowActor(id) {}
  ~TestActor() {}
  int OnStart() {
     LOG->trace("TestActor start");
  }

  int OnEvent(Event e) {
     LOG->trace("TestActor onEvent");
     LOG->info("receive data : {}",e.msg);
     Publish("topic", "hello this is topic"); //subscribe "a" topic from x1
     LOG->info("TestActor published");
  }

  int OnStop() {
    LOG->trace("TestActor stop");
  }
};

class TestStage : public FlowStage {
public:
    TestStage(FlowQueuePtr q, int id): FlowStage(q, id) {
       //add actor
       FlowActorPtr actor1(new TestActor("happy"));
       AddActor(actor1);
    }

    ~TestStage() {}
    
    int OnStart() override {
       //iterator execute the actor start
       FlowStage::OnStart();
       return 1;
    }
    
    int OnEvent(FlowMessagePtr msg) {
       //LOG->info("{}",msg->GetOptionStr("data"));
       session_t session_id = msg->GetOptionInt("session_id");
       //session_t session_id = 1;
       std::string receiver = msg->GetOptionStr("receiver");
       Event e;
       e.msg = msg->GetOptionStr("data");
       e.topic = msg->GetOptionStr("topic");

       auto recv = GetActor(receiver);
       if (recv != nullptr)
          recv->OnEvent(e);
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

int main(int args, char* argv[]) {
  FLOWLOG_TRY {
    std::signal(SIGINT, handler);
    LoopPtr loop (new Loop());
    FlowManagerPtr manager(new FlowManager);
    
    int stageid = 0;
    FlowQueuePtr p1 = FlowQueueMgr::Instance().CreateQueue(stageid);
    FlowPublisherPtr publisher(new FlowPublisher(p1, stageid));
    manager->SetPublisher(publisher);
    std::thread tha([&publisher]() {publisher->Run();});
    tha.detach();
    publisher->SetManager(manager);
    manager->AddStage(stageid, publisher);
    
    stageid = 123;
    FlowQueuePtr p = FlowQueueMgr::Instance().CreateQueue(stageid);
    FlowStagePtr stageA(new TestStage(p, stageid));
    std::thread tha2([&stageA]() {stageA->Run();});
    tha2.detach();
    stageA->SetManager(manager);
    manager->AddStage(stageid, stageA);

    FlowLog::SetLevel(FlowLog::Trace);
    
    FlowServerPtr server(new FlowServer(loop, manager));
    //FlowManager::Instance().AddHandle(server);
    
    struct sockaddr_in addr;
    int port = 9123;
    ASSERT(0 == uv_ip4_addr("0.0.0.0", port, &addr)); //set bind address
    server->Bind(&addr, 0);
    server->Listen(SOMAXCONN);
    LOG->info("server on.");
    loop->loop_run(Loop::RUN_DEFAULT);
  } FLOWLOG_CATCH
  // delete loop;
  // delete server;
  return 0;
}