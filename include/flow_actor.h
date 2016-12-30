#ifndef FLOW_FRAMEWORK_FLOW_ACTOR_H
#define FLOW_FRAMEWORK_FLOW_ACTOR_H

#include <string>
#include "flow.h"
#include "event.h"

namespace flow {

class FlowStage;
class FlowActor {
public:
	FlowActor(std::string id);
	virtual ~FlowActor();
	virtual int OnStart() {};
	virtual int OnEvent(Event e) {};
	virtual int OnStop() {};
    
    void Subscribe(std::string conn_id, std::string topic);
    void Publish(std::string topic, std::string data);
    void Request(std::string conn_id, std::string receiver, std::string topic, std::string data);
    
    void SetStage(FlowStage* stage);
    FlowStage* GetStage();

    std::string Getid();
protected:
    FlowStage* stage_;
    std::string id_;
};// end of FlowActor
DEFINE_SHARED_PTR(FlowActor);
}
#endif //end of FLOW_FRAMEWORK_FLOW_ACTOR_H 