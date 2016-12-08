#include <iostream>

#include <uv.h>

#include "flow_client.h"
#include "flow_loop.h"
#include "flow_stage.h"
#include "flow_message.h"


using namespace flow;

class TestStage : public FlowStage {
public:
    TestStage(FlowQueuePtr q): FlowStage(q) {
       
    }

    ~TestStage() {}
    
    int OnStart() override {
       return 1;
    }
    
    int OnEvent(FlowMessagePtr msg) {
       std::cout << msg->GetOptionStr("data") << std::endl;
       return 1;
    }

};

int main(int args, char* argv[]) {
    LoopPtr loop (new Loop);

    //client:
    FlowClientPtr client (new FlowClient(loop));
    //FlowManager::Instance().AddHandle(client);
    
    struct sockaddr_in addr;
    ASSERT(0 == uv_ip4_addr("0.0.0.0", 9123, &addr));  //set server target
    client->Connect(&addr);
    loop->loop_run(Loop::RUN_DEFAULT);

    // delete loop;
    // delete server;
    return 0;
}