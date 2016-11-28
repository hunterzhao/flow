#include <thread>
#include <iostream>
#include "flow_server.h"
#include "flow_loop.h"
#include "flow_stage.h"
#include <uv.h>

using namespace flow;

class TestStage : public FlowStage {
public:
    TestStage(FlowQueuePtr q): FlowStage(q){
    }

    ~TestStage() {}
    
    int OnEvent(FlowMessage msg) {
       std::cout << msg.GetData() << std::endl;
       return 1;
    }

};

int main(int args, char* argv[]) {
  LoopPtr loop (new Loop());
  
  FlowQueuePtr p = FlowQueueMgr::Instance().CreateQueue(123);
  TestStage stageA(p);
  std::thread tha([&stageA]() {stageA.Run();});
  //server:
  FlowServerPtr server (new FlowServer(loop));
  //FlowManager::Instance().AddHandle(server);

  struct sockaddr_in addr;
  int port = 9123;
  ASSERT(0 == uv_ip4_addr("0.0.0.0", port, &addr)); //set bind address
  server->Bind(&addr, 0);
  server->Listen(SOMAXCONN);
  
  loop->loop_run(Loop::RUN_DEFAULT);
  // delete loop;
  // delete server;
  return 0;
}