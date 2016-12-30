#include "flow_actor.h"
#include "flow_stage.h"
#include "flow_message.h"
namespace flow {

FlowActor::FlowActor(std::string id) : id_(id) {}

FlowActor::~FlowActor() {}

void FlowActor::Subscribe(std::string conn_id, std::string topic) {
    FlowMessagePtr msg(new FlowMessage());
    msg->AddOption("type", FlowMessage::Subscribe);
    msg->AddOption("sender", id_.c_str());
    msg->AddOption("topic", "0");
    msg->AddOption("data", topic.c_str());
    stage_->Subscribe(conn_id, msg);
}

void FlowActor::Publish(std::string topic, std::string data) {
    FlowMessagePtr msg(new FlowMessage());
    msg->AddOption("type", FlowMessage::Publish);
    msg->AddOption("topic", topic.c_str());
    msg->AddOption("data", data.c_str());
    stage_->Publish(msg);
}

void FlowActor::Request(std::string conn_id, std::string receiver, std::string topic, std::string data) {
	FlowMessagePtr msg(new FlowMessage());
    msg->AddOption("type", FlowMessage::Request);
    msg->AddOption("receiver", receiver.c_str());
    msg->AddOption("topic", topic.c_str());
    msg->AddOption("data", data.c_str());
    stage_->Request(conn_id, msg);
}

std::string FlowActor::Getid() {
    return id_;
}

void FlowActor::SetStage(FlowStage* stage) {
    stage_ = stage;
}
FlowStage* FlowActor::GetStage() {
    return stage_;
}


}