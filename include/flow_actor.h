#ifndef FLOW_FRAMEWORK_FLOW_ACTOR_H
#define FLOW_FRAMEWORK_FLOW_ACTOR_H

#include <string>
#include "flow.h"
#include "event.h"

namespace flow {
class FlowActor {
public:
	FlowActor(int id);
	virtual ~FlowActor();
	// virtual int OnStart();
	// virtual int OnEvent(Event& e);
	// virtual int OnStop();
    
    void Subscribe(std::string conn_id, std::string topic);
    void Request(std::string conn_id, std::string topic, std::string data);

private:
    int id_;
};// end of FlowActor
DEFINE_SHARED_PTR(FlowActor);
}
#endif //end of FLOW_FRAMEWORK_FLOW_ACTOR_H 