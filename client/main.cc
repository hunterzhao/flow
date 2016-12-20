#include <iostream>

#include <uv.h>

#include "flow_client.h"
#include "flow_loop.h"
#include "flow_stage.h"
#include "flow_message.h"


using namespace flow;

class  TestClient : public FlowClient {
public:
    TestClient(LoopPtr loop) : FlowClient(loop) {}
    ~TestClient(){};

    void OnConnected() {
        const char* data = "hello world";
        FlowMessagePtr msg(new FlowMessage());
        msg->AddOption("data", data);
        SendMessage(msg);
    }

    void OnMessage(FlowMessagePtr msg, uv_stream_t* tcp) {
        std::cout << "TestClient:" << msg->GetOptionStr("data") << std::endl;
    }
};
class TestStage : public FlowStage {
public:
    TestStage(FlowQueuePtr q): FlowStage(q) {
       
    }

    ~TestStage() {}
    
    int OnStart() override {
        //iterator execute the actor onstart
       return 1;
    }
    
    int OnEvent(FlowMessagePtr msg) {
       //send msg to specific actor
       return 1;
    }

    int OnEnd(FlowMessagePtr msg) {
       //iterator execute the actor end
       return 1;
    }

};
DEFINE_SHARED_PTR(TestClient);

int main(int args, char* argv[]) {
    LoopPtr loop (new Loop);

    //client:
    TestClientPtr client (new TestClient(loop));
    
    struct sockaddr_in addr;
    ASSERT(0 == uv_ip4_addr("0.0.0.0", 9123, &addr));  //set server target
    client->Connect(&addr);
    loop->loop_run(Loop::RUN_DEFAULT);

    // delete loop;
    // delete server;
    return 0;
}