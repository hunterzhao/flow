#ifndef FLOW_FRAMEWORK_FLOW_SERVER_H
#define FLOW_FRAMEWORK_FLOW_SERVER_H

#include <uv.h>
#include "flow.h"
#include "flow_tcp_handle.h"

namespace flow {

class Loop;
DEFINE_SHARED_PTR(Loop);

class FlowServer : public TcpHandle {
public:
	//static void after_write(uv_write_t* req, int status);
	static void on_connect(uv_stream_t* server, int status);

	FlowServer(LoopPtr loop);

	virtual ~FlowServer();

	int Bind(const struct sockaddr_in* addr, unsigned int flags);

	int Listen(int blacklog);
    
    void Close(uv_stream_t* handle);

    LoopPtr GetLoop();
private:
    uv_tcp_t tcpServer_;
    LoopPtr loop_;

    int server_closed_;
};
}
#endif //FLOW_FRAMEWORK_FLOW_SERVER_H