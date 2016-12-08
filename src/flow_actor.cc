#include "flow_actor.h"

namespace flow {

FlowActor::FlowActor(int id) : id_(id) {}

FlowActor::~FlowActor() {}

void FlowActor::Subscribe(std::string conn_id, std::string topic) {

}

void FlowActor::Request(std::string conn_id, std::string topic, std::string data) {
	
}

}