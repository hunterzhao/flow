#include "flow_stage.h"
#include "flow_actor.h"
#include "flow_log.h"
#include "flow_manager.h"
#include "flow_publisher.h"
#include "flow_client.h"
namespace flow {
FlowStage::FlowStage(FlowQueuePtr queue, int id) : queue_(queue), stageid_(id) {

}

FlowStage::~FlowStage() {

}

void FlowStage::Run() {
	int ret = 0;
	ret = OnStart();
	if (ret < 0) {

	}

	while(queue_) {
       FlowMessagePtr msg = queue_->PopOne();
       if (OnEvent(msg) < 0)
       	   break;
	}
	
	ret = OnStop();
	if (ret < 0) {

	}
	return;
}

int FlowStage::AddActor(FlowActorPtr actor) {
    actorMap_[actor->Getid()] = actor;
    actor->SetStage(this);
    
}

int FlowStage::RemoveActor(std::string actorid) {
    actorMap_.erase(actorid);
}

FlowActorPtr FlowStage::GetActor(std::string actorid) {
    auto it = actorMap_.find(actorid);
    if(it == actorMap_.end()) return nullptr;
    else return it->second;
}

FlowManagerPtr FlowStage::GetManager() {
    return manager_;
}
int FlowStage::SetManager(FlowManagerPtr manager) {
    manager_=manager;
}

int FlowStage::OnEvent(FlowMessagePtr msg) {
   return 1;
}

int FlowStage::OnStart() {
   for(auto it = actorMap_.begin(); it != actorMap_.end(); it++) {
        it->second->OnStart();
    }
   return 1;
}

int FlowStage::OnStop() {
  for(auto it = actorMap_.begin(); it != actorMap_.end(); it++) {
        it->second->OnStop();
   }
   return 1;
}

int FlowStage::Getid() {
  return stageid_;
}

int FlowStage::Publish(FlowMessagePtr msg) {
  FlowPublisherPtr publisher = manager_->GetPublisher();
  FlowQueueMgr::Instance().SendMessage(publisher->Getid(), msg); 
}
int FlowStage::Request(std::string conn_id, FlowMessagePtr msg) {
  FlowClient* client = manager_->GetConn(conn_id);
  if(client == nullptr) {
     LOG->error("{} connection doesn't exist", conn_id);
  	 return -1;
  }
  LOG->info("{} connection prepare to send Request", conn_id);
  client->SendMessage(msg);
}
int FlowStage::Subscribe(std::string conn_id, FlowMessagePtr msg) {
  FlowClient* client = manager_->GetConn(conn_id);
   if(client == nullptr) {
     LOG->error("{} connection doesn't exist", conn_id);
  	 return -1;
  }
  LOG->info("{} connection prepare to send Subscribe", conn_id);
  client->SendMessage(msg);
}
}