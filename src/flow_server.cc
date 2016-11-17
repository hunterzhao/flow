#include "flow_server.h"
#include "flow_loop.h"
#include "flow_tcp_handle.h"
#include <stdio.h>
#include <stdlib.h>

namespace flow {

void FlowServer::on_connect(uv_stream_t* server, int status) {
  LoopPtr loop = ((FlowServer*)server->data)->GetLoop();
  printf("accpet connect\n");
  uv_stream_t* stream;
  
  if (status != 0) {
    fprintf(stderr, "Connect error %s\n", uv_err_name(status));
  }
  ASSERT(status == 0);

 
  stream = (uv_stream_t*)malloc(sizeof(uv_tcp_t));
  ASSERT(stream != NULL);
  int r = uv_tcp_init(loop->self(), (uv_tcp_t*)stream);
  ASSERT(r == 0);
  
   r = uv_accept(server, stream);
   ASSERT(r == 0);
   
   stream->data = (FlowServer*)server->data;
   r = uv_read_start(stream, TcpHandle::alloc_cb, TcpHandle::read_cb);
   ASSERT(r == 0);
   printf("wait for data\n");
}

FlowServer::FlowServer(LoopPtr loop) : loop_(loop) {
  int r = uv_tcp_init(loop_->self(), &tcpServer_);
  server_closed_ = 0;
  if (r) {
    /* TODO: Error codes */
    fprintf(stderr, "Socket creation error\n");
  }
}

FlowServer::~FlowServer() {
   
}

int FlowServer::Bind(const struct sockaddr_in* addr, unsigned int flags) {
   int r = uv_tcp_bind(&tcpServer_, (const struct sockaddr*) addr, flags);
   if (r) {
	    /* TODO: Error codes */
	    fprintf(stderr, "Bind error\n");
	    return 1;
   }
   return r;
}

int FlowServer::Listen(int blacklog) {
   tcpServer_.data = this;
   int r = uv_listen((uv_stream_t*)&tcpServer_, blacklog, on_connect);
   if (r) {
     /* TODO: Error codes */
     fprintf(stderr, "Listen error %s\n", uv_err_name(r));
     return 1;
   }
   return r;
}

//close the connect socket
void FlowServer::Close(uv_stream_t* handle) {
   uv_shutdown_t* sreq;
   sreq = (uv_shutdown_t*)malloc(sizeof* sreq);
   ASSERT(0 == uv_shutdown(sreq, handle, TcpHandle::after_shutdown));
   printf("close.\n");
}

LoopPtr FlowServer::GetLoop() {
   return loop_;
}

}