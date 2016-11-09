#ifndef FLOW_FRAMEWORK_FLOW_STREAM_H
#define FLOW_FRAMEWORK_FLOW_STREAM_H

namespace flow {

class FlowStream {
public:
	static void read_cb(uv_stream_t* handle, void* user_data);
	static void write_cb(uv_stream_t* handle, void* user_data);
    
    static int SetNooDelay(uv_stream_t* handle, int enable);
    static int SetKeepAlive(uv_stream_t* handle, int enable, unsigned int delay);
    static int SetSimultaneousAccepts(uv_stream_t* handle, int enable);

    FlowStream();

    virtual ~FlowStream();

    virtual int Init();

    virtual void OnRead(uv_stream_t* handle);

    virtual void OnWrite(uv_stream_t* handle);

    //virtual void OnTimeout() override;

//private:
    //FlowManager *manager_;

};
}
#endif //FLOW_FRAMEWORK_FLOW_STREAM_H