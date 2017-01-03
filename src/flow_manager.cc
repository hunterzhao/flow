#include <memory>
#include <thread>

#include "flow_manager.h"
#include "flow_client.h"
#include "flow_publisher.h"
#include "flow_log.h"

namespace flow {
FlowManager::FlowManager() {

}	

FlowManager::~FlowManager() {

}

int FlowManager::server_init() {
	//start publisher
	int stageid = 0;
	FlowPublisherPtr publisher(new FlowPublisher(stageid));
    FlowQueuePtr p = FlowQueueMgr::Instance().CreateQueue(stageid);
    publisher->SetQueue(p);
    //AddStage(stageid, publisher);
    SetPublisher(publisher);
    
    publisher->SetManager(this);
    std::thread tha([publisher]() {publisher->Run();});
    tha.detach();

    StartStage();
    
    return 1;
}

int FlowManager::client_init() {
    StartStage();
	return 1;
}

int FlowManager::AddStage(FlowStagePtr stage) {
    stageMap_[stage->Getid()] = stage;
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
	}
	LOG->warn("not found actor {}", id);
	return -1;
}

int FlowManager::SetPublisher(FlowPublisherPtr publisher) {
   publisher_ = publisher;
   return 1;
}

FlowPublisherPtr FlowManager::GetPublisher() {
   return publisher_;
}

int FlowManager::StartStage() { 
     //start stages
    for(auto it = stageMap_.begin(); it != stageMap_.end(); it++) {
         FlowStagePtr stage = it->second;
         FlowQueuePtr p = FlowQueueMgr::Instance().CreateQueue(stage->Getid());
         stage->SetQueue(p);
         stage->SetManager(this);
         std::thread tha([stage]() {stage->Run();});
		 tha.detach();
    }
	return 1;
}
int FlowManager::StopStage(const std::string& id) {return 1;}


}