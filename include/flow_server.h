#ifndef FLOW_FRAMEWORK_FLOW_SERVER_H
#define FLOW_FRAMEWORK_FLOW_SERVER_H

#include <uv.h>
#include "flow.h"

namespace flow {

class Loop;
DEFINE_SHARED_PTR(Loop);

class FlowServer {
public:

	static void after_write(uv_write_t* req, int status);
	static void after_read(uv_stream_t*, ssize_t nread, const uv_buf_t* buf);
	static void after_shutdown(uv_shutdown_t* req, int status);
	static void on_close(uv_handle_t* peer);
	static void on_server_close(uv_handle_t* handle);
	static void on_connection(uv_stream_t*, int status);
    static void echo_alloc(uv_handle_t* handle,
				                       size_t suggested_size,
				                       uv_buf_t* buf);

	FlowServer(LoopPtr loop);

	~FlowServer();

	int Bind(const struct sockaddr_in* addr, unsigned int flags);

	int Listen(int blacklog);
    
    LoopPtr GetLoop();
private:
    uv_tcp_t tcpServer_;
    LoopPtr loop_;

    int server_closed_;
};
}
#endif //FLOW_FRAMEWORK_FLOW_SERVER_H