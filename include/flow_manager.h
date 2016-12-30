#ifndef FLOW_FRAMEWORK_FLOW_MANAGER_H
#define FLOW_FRAMEWORK_FLOW_MANAGER_H

#include <unordered_map>
#include <string>
#include "flow.h"

namespace flow {
class FlowStage;
class FlowClient;
class FlowPublisher;
DEFINE_SHARED_PTR(FlowStage);
DEFINE_SHARED_PTR(FlowClient);
DEFINE_SHARED_PTR(FlowPublisher);
class FlowManager {
public:
    FlowManager();
	~FlowManager();
    
    int AddStage(int stageid, FlowStagePtr stage);
    FlowStagePtr GetStage(int stageid);

    int AddConn(std::string conn, FlowClient* client);
    FlowClient* GetConn(std::string conn);
    
    int StartStage(const std::string& id);
    int StopStage(const std::string& id);
    
    //iterator stages to find actor
    int actor2stage(const std::string& id);
    
    int SetPublisher(FlowPublisherPtr publisher); 

    FlowPublisherPtr GetPublisher();

private:
    std::unordered_map<int, FlowStagePtr> stageMap_; // for client and server to manager stages
    std::unordered_map<std::string, FlowClient*> connMap_;  //for client to manage connections more than one
    FlowPublisherPtr publisher_; //for server to publish
};
}
#endif