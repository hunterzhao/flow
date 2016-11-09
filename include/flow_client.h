#ifndef FLOW_FRAMEWORK_FLOW_Client_H
#define FLOW_FRAMEWORK_FLOW_Client_H
#include <uv.h>
#include "flow.h"

namespace flow {

class Loop;
DEFINE_SHARED_PTR(Loop);

class FlowClient {
public:
	static void on_close(uv_handle_t* handle);
	static void alloc_cb(uv_handle_t* handle, size_t size, uv_buf_t* buf);
	static void on_read(uv_stream_t* tcp, ssize_t nread, const uv_buf_t* buf);
	static void on_write(uv_write_t* req, int status);
	static void on_connect(uv_connect_t* connection, int status);
    
    FlowClient(LoopPtr loop);
    
    ~FlowClient();
    
    int Connect(const struct sockaddr_in* addr);
    
private:
	uv_tcp_t tcpClient_; 
	uv_connect_t* connect_; 
    LoopPtr loop_;         

    int client_closed_;
};
}// namespace flow
#endif //FLOW_FRAMEWORK_FLOW_Client_H