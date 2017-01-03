#include "flow_stage.h"
#include "flow_actor.h"
#include "flow_log.h"
#include "flow_manager.h"
#include "flow_publisher.h"
#include "flow_client.h"
namespace flow {
FlowStage::FlowStage(int id) : stageid_(id) {

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
    return 1;
}

int FlowStage::RemoveActor(std::string actorid) {
    actorMap_.erase(actorid);
    return 1;
}

FlowActorPtr FlowStage::GetActor(std::string actorid) {
    auto it = actorMap_.find(actorid);
    if(it == actorMap_.end()) return nullptr;
    else return it->second;
}

FlowManager* FlowStage::GetManager() {
    return manager_;
}
int FlowStage::SetManager(FlowManager* manager) {
    manager_=manager;
    return 1;
}

int FlowStage::SetQueue(FlowQueuePtr q) {
    queue_ = q;
    return 1;
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
  return 1;
}

int FlowStage::Request(std::string conn_id, FlowMessagePtr msg) {
  FlowClient* client = manager_->GetConn(conn_id);
  if(client == nullptr) {
     LOG->error("{} connection doesn't exist", conn_id);
  	 return -1;
  }
  LOG->info("{} connection prepare to send Request", conn_id);
  client->SendMessage(msg);
  return 1;
}

int FlowStage::Subscribe(std::string conn_id, FlowMessagePtr msg) {
  FlowClient* client = manager_->GetConn(conn_id);
   if(client == nullptr) {
     LOG->error("{} connection doesn't exist", conn_id);
  	 return -1;
  }
  LOG->info("{} connection prepare to send Subscribe", conn_id);
  client->SendMessage(msg);
  return 1;
}
}