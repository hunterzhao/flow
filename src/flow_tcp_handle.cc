#include "flow_tcp_socket.h"

namespace flow {

TcpHandle::TcpHandle(Loop *loop) {
    //Initialize the handle. No socket is created as of yet.
    return uv_tcp_init(loop->self(), handle_);
}

TcpHandle::~TcpHandle() {

}

int TcpHandle::SetNooDelay(int enable) {
	return uv_tcp_nodelay(handle_, enable);
}

int TcpHandle::SetKeepAlive(int enable, unsigned int delay) {
	return uv_tcp_keepalive(handle_, enable, delay);
}

int TcpHandle::SetSimultaneousAccepts(int enable) {
    return uv_tcp_simultaneous_accepts(handle_, enable);
}
    
int TcpHandle::Bind(const struct sockaddr* addr, unsigned int flags) {
    return uv_tcp_bind(handle_, addr, flags);
}

int TcpHandle::GetSockName(struct sockaddr* name, int* namelen) {
    return uv_tcp_getsockname(handle_, name, namelen);
}

int TcpHandle::GetPeerName(struct sockaddr* name, int* namelen) {
    return uv_tcp_getpeername(handle_, name, namelen);
}

int TcpHandle::Connect(uv_connect_t* req, const struct sockaddr* addr, uv_connect_cb cb) {
    return uv_tcp_connect(req, handle_, addr, cb);
}

}