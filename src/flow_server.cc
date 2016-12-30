#include <stdio.h>
#include <stdlib.h>

#include "uv.h"

#include "flow_server.h"
#include "flow_queue.h"
#include "flow_message.h"
#include "flow_session.h"
#include "flow_log.h"  
#include "flow_publisher.h"
#include "flow_manager.h"

namespace flow {

void FlowServer::on_connect(uv_stream_t* server, int status) {
  LoopPtr loop = ((FlowServer*)(server->data) )->GetLoop();
  LOG->info("accpet connect");
  uv_stream_t* stream;
  
  if (status != 0) {
    LOG->error("Connect error {}",uv_err_name(status));
  }
  ASSERT(status == 0) ;

  stream = (uv_stream_t*)malloc(sizeof(uv_tcp_t));
  ASSERT(stream != NULL);
  int r = uv_tcp_init(loop->self(), (uv_tcp_t*)stream);
  ASSERT(r == 0);
  
  r = uv_accept(server, stream);
  ASSERT(r == 0);
  
  SessionMgr::Instance().AddNewSession(stream);
  
  stream->data = (FlowServer*)(server->data);
  r = uv_read_start(stream, TcpHandle::alloc_cb, TcpHandle::read_cb);
  ASSERT(r == 0);
  LOG->info("wait for data");
}

FlowServer::FlowServer(LoopPtr loop, FlowManagerPtr manager): loop_(loop), manager_(manager) {
  int r = uv_tcp_init(loop_->self(), &tcpServer_);
  server_closed_ = 0;
  if (r) {
    /* TODO: Error codes */
    LOG->error("Socket creation error");
  }
}

FlowServer::~FlowServer() {
   
}

int FlowServer::Bind(const struct sockaddr_in* addr, unsigned int flags) {
   int r = uv_tcp_bind(&tcpServer_, (const struct sockaddr*) addr, flags);
   if (r) {
	    /* TODO: Error codes */
      LOG->error("Bind error");
	    return 1;
   }
   return r;
}

int FlowServer::Listen(int blacklog) {
   tcpServer_.data = this;
   int r = uv_listen((uv_stream_t*)&tcpServer_, blacklog, on_connect);
   if (r) {
     /* TODO: Error codes */
     LOG->error("Listen error {}",uv_err_name(r));
     return 1;
   }
   return r;
}

//close the connect socket
void FlowServer::Close(uv_stream_t* handle) {
   uv_shutdown_t* sreq;
   sreq = (uv_shutdown_t*)malloc(sizeof* sreq);
   ASSERT(0 == uv_shutdown(sreq, handle, TcpHandle::after_shutdown));
   LOG->info("close.");
}

void FlowServer::OnMessage(FlowMessagePtr msg, uv_stream_t* tcp) {
  int type = msg->GetOptionInt("type");
  session_t session_id = SessionMgr::Instance().GetSessionID(tcp);
  
  switch(type) {
    case FlowMessage::Subscribe: {
          std::string sender = msg->GetOptionStr("sender");
          FlowPublisherPtr publisher = manager_->GetPublisher();
          publisher->AddSubsribe(msg->GetOptionStr("data"), sender, session_id); //topic store in data
          break;
        }
    case FlowMessage::Publish: {
          std::string receiver = msg->GetOptionStr("receiver");
          int stageid = manager_->actor2stage(receiver);   
          msg->AddOption("session_id", session_id);  //add communication message
          FlowQueueMgr::Instance().SendMessage(stageid, msg);
          break;
        }
    case FlowMessage::Request: {
          std::string receiver = msg->GetOptionStr("receiver");
          int stageid = manager_->actor2stage(receiver);   
          msg->AddOption("session_id", session_id);  //add communication message
          FlowQueueMgr::Instance().SendMessage(stageid, msg);
          break;
        }
  }
 
}

LoopPtr FlowServer::GetLoop() {
   return loop_;
}

}