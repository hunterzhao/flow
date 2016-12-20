#include <thread>
#include <iostream>
#include <csignal>

#include <uv.h>

#include "flow_server.h"
#include "flow_loop.h"
#include "flow_stage.h"
#include "flow_actor.h"
#include "flow_session.h"
#include "flow.h"
#include "flow_log.h"

using namespace flow;

int stop = 0;
void handler(int sigcode) {
   std::cout << "interrupt" << sigcode << "received" << std::endl;
   stop=1;
   exit(sigcode);
   //exit(sigcode);
}

class TestStage : public FlowStage {
public:
    TestStage(FlowQueuePtr q): FlowStage(q){
    }

    ~TestStage() {}
    
    int OnEvent(FlowMessagePtr msg) {
       std::cout << msg->GetOptionStr("data") << std::endl;
       session_t session_id = msg->GetOptionInt("session_id");
       //session_t session_id = 1;
       SessionMgr::Instance().SendMessage(session_id, msg);
       //msg.FreeData();
       // int receiver = msg->GetReceiver();
       // Event e;
       // e.data = msg->GetData();
       // e.sender = msg->GetSender();
       // e.topic = msg->GetTopic();
       // e.session_id = session_id;
       // auto it = actorMap_.find(receiver);
       // if (it != actorMap)
       //    it->second->OnEvent(e);
       //  else
       //    std::cout << "the receiver doesn't exist" << std::endl;

       return 1;
    }

};

// class TestActor : public FlowActor {
// public:
//   TestActor(int id) : FlowActor(id) {}
//   ~TestActor() {}
//   int onStart() {
//      subscribe("x1","a"); //subscribe "a" topic from x1
//   }

//   int OnEvent(Event e) {
//      std::cout << "sender" << e.sender << std::endl;
//      std::cout << "data:" << e.data << std::endl;
//      SessionMgr::Instance().SendMessage(e.session_id);
//   }

//   int OnStop() {

//   }
// }
int main(int args, char* argv[]) {
  FLOWLOG_TRY {
    std::signal(SIGINT, handler);
    LoopPtr loop (new Loop());
    
    FlowQueuePtr p = FlowQueueMgr::Instance().CreateQueue(123);
    TestStage stageA(p);
    std::thread tha([&stageA]() {stageA.Run();});
    tha.detach();
    FlowLog::SetLevel(FlowLog::Trace);
    LOG->info("server on...{}",1);
    FlowServerPtr server (new FlowServer(loop));
    //FlowManager::Instance().AddHandle(server);

    struct sockaddr_in addr;
    int port = 9123;
    ASSERT(0 == uv_ip4_addr("0.0.0.0", port, &addr)); //set bind address
    server->Bind(&addr, 0);
    server->Listen(SOMAXCONN);
    
    loop->loop_run(Loop::RUN_DEFAULT);
  } FLOWLOG_CATCH
  // delete loop;
  // delete server;
  return 0;
}