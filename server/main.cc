#include "flow_server.h"
#include "flow_loop.h"
#include <uv.h>

using namespace flow;

int main(int args, char* argv[]) {
  LoopPtr loop (new Loop);

  //server:
  FlowServer* server =new FlowServer(loop);
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