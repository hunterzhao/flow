#ifndef FLOW_FRAMEWORK_FLOW_Client_H
#define FLOW_FRAMEWORK_FLOW_Client_H
#include <uv.h>
#include "flow.h"
#include "flow_tcp_handle.h"

namespace flow {

class Loop;
class TcpHandle;
DEFINE_SHARED_PTR(Loop);

class FlowClient : public TcpHandle {
public:
	
	static void on_connect(uv_connect_t* connection, int status);

    void OnWrite(uv_write_t* req);
    
    FlowClient(LoopPtr loop);
    
    virtual ~FlowClient();
    
    int Connect(const struct sockaddr_in* addr);

    int SendData(const void* data, size_t data_len); 
    
    void Close(uv_stream_t* handle);

    virtual void OnConnected();//provide the interface for user code
    virtual void OnDisConnected();

private:
	uv_tcp_t tcpClient_; 
	uv_connect_t* connect_; 
    LoopPtr loop_;         

    int client_closed_;
};
}// namespace flow
#endif //FLOW_FRAMEWORK_FLOW_Client_H