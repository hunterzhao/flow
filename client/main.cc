#include "flow_client.h"
#include "flow_loop.h"
#include <uv.h>

using namespace flow;

int main(int args, char* argv[]) {
  LoopPtr loop (new Loop);
  
  //client:
  FlowClient* client =new FlowClient(loop);
  struct sockaddr_in addr;
  ASSERT(0 == uv_ip4_addr("0.0.0.0", 9123, &addr));  //set server target
  client->Connect(&addr);
  loop->loop_run(Loop::RUN_DEFAULT);

  // delete loop;
  // delete server;
  return 0;
}