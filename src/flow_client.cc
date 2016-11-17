#include "flow_client.h"
#include "flow_loop.h"
#include "flow_tcp_handle.h"
#include <stdio.h>
#include <stdlib.h>

namespace flow {

void FlowClient::OnWrite(uv_write_t* req) {
	printf("wrote.\n");
}

void FlowClient::on_connect(uv_connect_t* connection, int status) {
	printf("connected.\n");
	uv_stream_t* stream = connection->handle;
	FlowClient* client= ((FlowClient*)connection->data);
	stream->data = client;
	client->SendData("hello",5);
}

FlowClient::FlowClient(LoopPtr loop): loop_(loop) {
	int r = uv_tcp_init(loop_->self(), &tcpClient_);
	client_closed_ = 0;
	if (r) {
	    /* TODO: Error codes */
	    fprintf(stderr, "Socket creation error\n");
	}
	connect_ = (uv_connect_t*)malloc(sizeof(uv_connect_t));
}

FlowClient::~FlowClient() {

}

int FlowClient::Connect(const struct sockaddr_in* addr){
	connect_->data = this;
    return uv_tcp_connect(connect_, &tcpClient_,  (const struct sockaddr*)addr, on_connect);
}

int FlowClient::SendData(const void* data, size_t data_len) {
    return connect_ == nullptr ? -1 : TcpHandle::SendData(connect_->handle, data, data_len);
} 

void FlowClient::Close(uv_stream_t* handle) {
    uv_shutdown_t* sreq;
    sreq = (uv_shutdown_t*)malloc(sizeof* sreq);
    ASSERT(0 == uv_shutdown(sreq, handle, after_shutdown));
    printf("close.\n");
}

void FlowClient::OnConnected() {}//provide the interface for user code
void FlowClient::OnDisConnected() {}
}//namespace flow