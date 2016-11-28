#include "flow.h"
#include "flow_tcp_handle.h"

namespace flow {

void TcpHandle::read_cb(uv_stream_t* tcp, ssize_t nread, const uv_buf_t* buf) {
    TcpHandle* handle = (TcpHandle*)(tcp->data);
    printf("data coming\n");
    if (nread < 0) {
	    /* Error or EOF */
	    ASSERT(nread == UV_EOF);
        printf("end of file \n");
	    free(buf->base);
	    uv_shutdown_t* sreq = (uv_shutdown_t*)malloc(sizeof* sreq);
	    ASSERT(0 == uv_shutdown(sreq, tcp, after_shutdown));
	    return;
    }

    if (nread == 0) {
	    /* Everything OK, but nothing read. */
        printf("nothing read \n");
	    free(buf->base);
	    return;
    }

    handle->OnRead(tcp, nread, buf);
}

void TcpHandle::write_cb(uv_write_t* req, int status) {
    printf("wrote.\n");
    //TcpHandle* handle = (TcpHandle*)(req->data);
  //  handle->OnWrite(req);
}

void TcpHandle::close_cb(uv_handle_t* handle) {
    free(handle);
    printf("closed.\n");
}

void TcpHandle::alloc_cb(uv_handle_t* handle, size_t suggested_size,
                                                uv_buf_t* buf) {
   buf->base = (char*)malloc(suggested_size * sizeof(char));
   if (NULL == buf->base)
      exit(1);
   memset(buf->base, 0, suggested_size * sizeof(char));
   buf->len = suggested_size;
}

void TcpHandle::after_shutdown(uv_shutdown_t* req, int status) {
   uv_close((uv_handle_t*) req->handle, TcpHandle::close_cb);
   free(req);
}

TcpHandle::TcpHandle() {

}

TcpHandle::~TcpHandle() {

}

int TcpHandle::SetNoDelay(int enable) {
	return uv_tcp_nodelay(handle_, enable);
}

int TcpHandle::SetKeepAlive(int enable, unsigned int delay) {
	return uv_tcp_keepalive(handle_, enable, delay);
}

int TcpHandle::SetSimultaneousAccepts(int enable) {
    return uv_tcp_simultaneous_accepts(handle_, enable);
}

int TcpHandle::SendData(uv_stream_t* dest, const void* data, size_t data_len) {
    uv_buf_t buffer[] = {
        {.base = (char*)data, .len = data_len}
    };
    uv_write_t request;
    uv_write(&request, dest, buffer, 1, write_cb);
	return 0;
}

void TcpHandle::OnRead(uv_stream_t* tcp, ssize_t nread, const uv_buf_t* buf) {
    /*
    * receive data and decode
    */
    printf("data is %s \n", buf->base);
    //lock?
    FlowMessagePtr msg(new FlowMessage());
    msg->SetData(buf->base, buf->len);
	OnMessage(msg);
    //lock?
}

void TcpHandle::OnWrite(uv_write_t* req) {
	/**/
	printf("TcpHandle::OnWrite\n");
}

void TcpHandle::OnMessage(FlowMessagePtr msg) {
    
}
}