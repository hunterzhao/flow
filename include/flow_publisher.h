#ifndef FLOW_FRAMEWORK_FLOW_PUBLISHER_H
#define FLOW_FRAMEWORK_FLOW_PUBLISHER_H
#include <unordered_map>
#include <string>
#include <vector>
#include "flow_session.h"
#include "flow_stage.h"

namespace flow {
struct subscriber {
	session_t session_id;
	std::string subscriberid;
	subscriber(session_t session_id_, std::string subscriberid_) : 
	           session_id(session_id_), subscriberid(subscriberid_) {}
};

class FlowPublisher : public FlowStage {
public:
	//receive message and prepare to publish
	FlowPublisher(int id) : FlowStage(id) {}
	~FlowPublisher() {}
    int OnEvent(FlowMessagePtr msg);
    int AddSubsribe(std::string topic, std::string sender, session_t session_id);
    int OnStart() {return 1;}
    int OnStop() {return 1;}

private:
    std::unordered_map<std::string, std::vector<subscriber> > subscribeMap_;
};
DEFINE_SHARED_PTR(FlowPublisher);
} //end of flow
#endif //end if FLOW_FRAMEWORK_FLOW_PUBLISHER_H