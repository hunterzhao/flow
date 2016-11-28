#include "flow_manager.h"

namespace flow {
FlowManager::FlowManager() {

}	

FlowManager::~FlowManager() {

}

void FlowManager::Init() {

}

void FlowManager::AddHandle(TcpHandlePtr handler) {
    handlers_.insert(handler);
}

void FlowManager::start() {

}

void FlowManager::stop() {

}
}