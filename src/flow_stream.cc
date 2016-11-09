#include "flow_stream.h"

namespace flow {

void FlowStream::read_cb(uv_stream_t* handle, void* user_data) {
	FlowStream* stream = (FlowStream*)user_data;
	stream->OnRead(handle);
}	

void FlowStream::write_cb(uv_stream_t* handle, void* user_data) {
	FlowStream* stream = (FlowStream*)user_data;
	stream->OnWrite(handle);
}

int FlowStream::SetNooDelay(uv_stream_t* handle, int enable) {
	uv_tcp_t* tcp_handle = dynamic_cast<uv_tcp_t*>(handle);
	if (handle != NULL)
	    return uv_tcp_nodelay(tcp_handle, enable);
	return -1;
}

int FlowStream::SetKeepAlive(uv_stream_t* handle, int enable, unsigned int delay) {
	uv_tcp_t* tcp_handle = dynamic_cast<uv_tcp_t*>(handle);
	if (handle != NULL)
	     return uv_tcp_keepalive(tcp_handle, enable, delay);
	return -1;
}

int FlowStream::SetSimultaneousAccepts(uv_stream_t* handle, int enable) {
	uv_tcp_t* tcp_handle = dynamic_cast<uv_tcp_t*>(handle);
	if (handle != NULL)
	     return uv_tcp_simultaneous_accepts((uv_tcp_t*)handle, enable);
	return -1;
}

FlowStream::FlowStream() {
    
}

FlowStream::~FlowStream() {

}

void FlowStream::OnRead(uv_stream_t* handle) {
	LOG(trace) << "FlowStream::OnRead";
    int ret = uv_read_start(handle, echo_alloc, after_read);
    ASSERT(ret == 0);

    OnMessage()
    return;
}
}