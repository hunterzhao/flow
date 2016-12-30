#include <stdio.h>
#include <stdlib.h>

#include "flow_client.h"
#include "flow_tcp_handle.h"
#include "flow_message.h"
#include "flow_log.h"
#include "flow_manager.h"
namespace flow {

void FlowClient::OnWrite(uv_write_t* req) {
	LOG->info("wrote.");
}

void FlowClient::connect_cb(uv_connect_t* connection, int status) {
	LOG->info("connected.");
	uv_stream_t* stream = connection->handle;
	FlowClient* client= ((FlowClient*)connection->data);
	stream->data = client;
	uv_read_start(stream, TcpHandle::alloc_cb, TcpHandle::read_cb); 
	
	client->OnConnected();
	//msg->FreeData();
}

FlowClient::FlowClient(LoopPtr loop, FlowManagerPtr manager): loop_(loop), manager_(manager) {
	int r = uv_tcp_init(loop_->self(), &tcpClient_);
	client_closed_ = 0;
	if (r) {
	    /* TODO: Error codes */
	    LOG->error("Socket creation error");
	}
	connect_ = (uv_connect_t*)malloc(sizeof(uv_connect_t));
}

FlowClient::~FlowClient() {
    if (connect_ != nullptr) {
        free(connect_);
        connect_ = nullptr;
        LOG->warn("socket free in destructor.");
    }
    else {
    	LOG->warn("socket already free.");
    }
}

int FlowClient::Connect(const struct sockaddr_in* addr){
	connect_->data = this;
    return uv_tcp_connect(connect_, &tcpClient_,  (const struct sockaddr*)addr, connect_cb);
}

int FlowClient::SendMessage(const FlowMessagePtr msg) {
	
    return connect_ == nullptr ? -1 : TcpHandle::SendMessage(connect_->handle, msg);
} 

int FlowClient::SendData(const char* data, size_t datalen) {
	
    return connect_ == nullptr ? -1 : TcpHandle::SendData(connect_->handle, data, datalen);
} 

void FlowClient::Close(uv_stream_t* handle) {
    uv_shutdown_t* sreq;
    sreq = (uv_shutdown_t*)malloc(sizeof* sreq);
    ASSERT(0 == uv_shutdown(sreq, handle, after_shutdown));
}

void FlowClient::OnMessage(FlowMessagePtr msg, uv_stream_t* tcp) {
    
}

void FlowClient::OnConnected() {}//provide the interface for user code
void FlowClient::OnDisConnected() {}
}//namespace flow