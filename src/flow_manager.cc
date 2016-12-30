#include <memory>
#include "flow_manager.h"
#include "flow_client.h"
#include "flow_publisher.h"
#include "flow_log.h"

namespace flow {
FlowManager::FlowManager() {

}	

FlowManager::~FlowManager() {

}

int FlowManager::AddStage(int stageid, FlowStagePtr stage) {
    stageMap_[stageid] = stage;
    return 0;
}

FlowStagePtr FlowManager::GetStage(int stageid) {
	return stageMap_[stageid];
}

int FlowManager::AddConn(std::string conn, FlowClient* client) {
    auto it = connMap_.find(conn);
    if(it == connMap_.end())
        connMap_[conn] = client;
    return 0;
}

FlowClient* FlowManager::GetConn(std::string conn) {
	auto it = connMap_.find(conn);
	if(it == connMap_.end()) {
		LOG->warn("no connection name {}", conn);
		return nullptr;
	}
    return connMap_[conn];
}

int FlowManager::actor2stage(const std::string& id) {
	for(auto it = stageMap_.begin(); it != stageMap_.end(); it++) {
		FlowStagePtr stage = it->second;
		if(stage->GetActor(id) != nullptr) {
			return stage->Getid();
		}
		return -1;
	}
}

int FlowManager::SetPublisher(FlowPublisherPtr publisher) {
   publisher_ = publisher;
}

FlowPublisherPtr FlowManager::GetPublisher() {
   return publisher_;
}

int FlowManager::StartStage(const std::string& id) {}
int FlowManager::StopStage(const std::string& id) {}


}