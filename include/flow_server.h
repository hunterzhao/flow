#ifndef FLOW_FRAMEWORK_FLOW_SERVER_H
#define FLOW_FRAMEWORK_FLOW_SERVER_H

#include <uv.h>

#include "flow.h"
#include "flow_tcp_handle.h"
#include "flow_loop.h"

namespace flow {
class FlowMessage;
DEFINE_SHARED_PTR(FlowMessage);
class FlowServer : public TcpHandle {
public:
	//static void after_write(uv_write_t* req, int status);
	static void on_connect(uv_stream_t* server, int status);

	FlowServer(LoopPtr loop);

	virtual ~FlowServer();

	int Bind(const struct sockaddr_in* addr, unsigned int flags);

	int Listen(int blacklog);
    
    void Close(uv_stream_t* handle);
    
    virtual void OnMessage(FlowMessagePtr msg, uv_stream_t* tcp);

    LoopPtr GetLoop();
private:
    uv_tcp_t tcpServer_;
    LoopPtr loop_;

    int server_closed_;
};
DEFINE_SHARED_PTR(FlowServer);
}
#endif //FLOW_FRAMEWORK_FLOW_SERVER_H