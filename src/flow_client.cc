#include <stdio.h>
#include <stdlib.h>
#include "flow_client.h"
#include "flow_tcp_handle.h"
#include "flow_message.h"

namespace flow {

void FlowClient::OnWrite(uv_write_t* req) {
	printf("wrote.\n");
}

void FlowClient::on_connect(uv_connect_t* connection, int status) {
	printf("connected.\n");
	uv_stream_t* stream = connection->handle;
	FlowClient* client= ((FlowClient*)connection->data);
	stream->data = client;
	uv_read_start(stream, TcpHandle::alloc_cb, TcpHandle::read_cb); //lead to invalid read
	char* data = "hello world";
	//FlowMessagePtr msg(new FlowMessage());// why?
    //msg->SetData(data, strlen(data));
	client->SendData(data, strlen(data));
	//client->SendData("hello", 6);
	//uv_read_start(stream, TcpHandle::alloc_cb, TcpHandle::read_cb); //???
	//client->SendData("hello", 6);
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
    if (connect_ != nullptr) {
        free(connect_);
        connect_ = nullptr;
        std::cout << "socket free in destructor." <<std::endl;
    }
    else {
    	std::cout << "socket already free." <<std::endl;
    }
}

int FlowClient::Connect(const struct sockaddr_in* addr){
	connect_->data = this;
    return uv_tcp_connect(connect_, &tcpClient_,  (const struct sockaddr*)addr, on_connect);
}

int FlowClient::SendData(char* data, size_t data_len) {
	
    return connect_ == nullptr ? -1 : TcpHandle::SendData(connect_->handle, data, data_len);
} 

void FlowClient::Close(uv_stream_t* handle) {
    uv_shutdown_t* sreq;
    sreq = (uv_shutdown_t*)malloc(sizeof* sreq);
    ASSERT(0 == uv_shutdown(sreq, handle, after_shutdown));
}

void FlowClient::OnMessage(FlowMessagePtr msg) {
    
}

void FlowClient::OnConnected() {}//provide the interface for user code
void FlowClient::OnDisConnected() {}
}//namespace flow