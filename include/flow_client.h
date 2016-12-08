#ifndef FLOW_FRAMEWORK_FLOW_CLIENT_H
#define FLOW_FRAMEWORK_FLOW_CLIENT_H
#include <uv.h>

#include "flow.h"
#include "flow_tcp_handle.h"
#include "flow_loop.h"
#include "flow_message.h"

namespace flow {

class TcpHandle;

class FlowClient : public TcpHandle {
public:
	
	static void on_connect(uv_connect_t* connection, int status);

    void OnWrite(uv_write_t* req);
    
    FlowClient(LoopPtr loop);
    
    virtual ~FlowClient();
    
    int Connect(const struct sockaddr_in* addr);

    int SendMessage(const FlowMessagePtr msg); 

    int SendData(const char* data, size_t datalen);
    
    void Close(uv_stream_t* handle);
     
    virtual void OnMessage(FlowMessagePtr msg);
    virtual void OnConnected();//provide the interface for user code
    virtual void OnDisConnected();

private:
	uv_tcp_t tcpClient_; 
	uv_connect_t* connect_; 
    LoopPtr loop_;         

    int client_closed_;
};
DEFINE_SHARED_PTR(FlowClient);
}// namespace flow
#endif //FLOW_FRAMEWORK_FLOW_Client_H