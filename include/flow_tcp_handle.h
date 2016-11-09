#ifndef FLOW_FRAMEWORK_FLOW_TCP_HANDLE_H
#define FLOW_FRAMEWORK_FLOW_TCP_HANDLE_H

namespace flow {
class TcpHandle {
public:
	//socket create
	TcpHandle();
    
    //release socket
	~TcpHandle();

    //Enable TCP_NODELAY, which disables Nagle’s algorithm.
    int SetNooDelay(int enable);

    //Enable / disable TCP keep-alive. delay is the initial delay in seconds, ignored when enable is zero.
    int SetKeepAlive(int enable, unsigned int delay);
    
    //Enable / disable simultaneous asynchronous accept requests that are queued by the operating system when listening for new TCP connections.
    int SetSimultaneousAccepts(int enable);
    
    //Bind the handle to an address and port. addr should point to an initialized struct sockaddr_in or struct sockaddr_in6.
    int Bind(const struct sockaddr* addr, unsigned int flags);
    
    //Get the current address to which the handle is bound. 
    int GetSockName(struct sockaddr* name, int* namelen);

    //Get the address of the peer connected to the handle. 
    int GetPeerName(struct sockaddr* name, int* namelen);

    //Establish an IPv4 or IPv6 TCP connection. Provide an initialized TCP handle and an uninitialized uv_connect_t
    int Connect(uv_connect_t* req, const struct sockaddr* addr, uv_connect_cb cb);

private:
	uv_tcp_t* handle_;
	uv_os_sock_t socket_;
};
}
#endif //FLOW_FRAMEWORK_FLOW_TCP_HANDLE_H