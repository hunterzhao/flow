#include "flow_client.h"
#include "flow_loop.h"

#include <stdio.h>
#include <stdlib.h>

namespace flow {
void FlowClient::on_close(uv_handle_t* handle) {
	printf("closed.");
}
void FlowClient::alloc_cb(uv_handle_t* handle,
	                       size_t suggested_size,
	                       uv_buf_t* buf) {
	buf->base = (char*)malloc(suggested_size * sizeof(char));
    buf->len = suggested_size;
}
void FlowClient::on_read(uv_stream_t* tcp, ssize_t nread, const uv_buf_t* buf) {
	if(nread >= 0) {
	    printf("read: %s\n", buf->base);
	}
	else {
	    uv_close((uv_handle_t*)tcp, on_close);
	}
	free(buf->base);
}

void FlowClient::on_write(uv_write_t* req, int status) {
	printf("wrote.\n");
}

void FlowClient::on_connect(uv_connect_t* connection, int status) {
	printf("connected.\n");
	uv_stream_t* stream = connection->handle;
	uv_buf_t buffer[] = {
	    {.base = "hello", .len = 5},
	    {.base = "world", .len = 5}
	};
	uv_write_t request;
	uv_write(&request, stream, buffer, 2, on_write);
	uv_read_start(stream, alloc_cb, on_read);
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
    return uv_tcp_connect(connect_, &tcpClient_,  (const struct sockaddr*)addr, on_connect);
}
}//namespace flow