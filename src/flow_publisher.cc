#include "flow_publisher.h"
#include "flow_log.h"

namespace flow {
int FlowPublisher::OnEvent(FlowMessagePtr msg) {
     //get topic and search
	 std::string topic = msg->GetOptionStr("topic");
	 auto it = subscribeMap_.find(topic);
     if (it != subscribeMap_.end()) {
	    std::vector<subscriber> subs = it->second;
	    for(auto sub : subs) {
	    	msg->AddOption("receiver",sub.subscriberid.c_str());
            SessionMgr::Instance().SendMessage(sub.session_id, msg);
            LOG->info("send to subscriber");
	    }
	 } else {
        LOG->info("no such subscriber");
	 	return -1;
	 }
     return 0;
 } 

int FlowPublisher::AddSubsribe(std::string topic, std::string sender, session_t session_id) {
	subscriber sub(session_id, sender);
	auto it = subscribeMap_.find(topic);
	if (it != subscribeMap_.end()) {
	 	it->second.push_back(sub);
	 	LOG->info("add subscriber to old topic");
	} else {
		std::vector<subscriber> tmp = {sub};
        subscribeMap_[topic] = tmp;
        LOG->info("add new topic");
	}
	return 0;
}
}//end of flow