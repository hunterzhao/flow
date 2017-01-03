#include <iostream>
#include "flow_log.h"
#include "flow_queue.h"

namespace flow {
FlowQueueMgr::~FlowQueueMgr() {}

FlowQueuePtr FlowQueueMgr::CreateQueue(int id) {
    if (queues_.find(id) != queues_.end())
    	return nullptr;

    FlowQueuePtr newQueue (new FlowQueue());
    if(newQueue) queues_[id] = newQueue;
    return newQueue;
}

FlowQueuePtr FlowQueueMgr::GetQueue(int id) {
    auto it = queues_.find(id);
	if (it == queues_.end())
		return nullptr;
	return it->second;
}

int FlowQueueMgr::RemoveQueue(int id) {
	auto it = queues_.find(id);
	if (it == queues_.end())
		return -1;
    queues_.erase(it);
    return 0;
}

int FlowQueueMgr::SendMessage(int id, FlowMessagePtr msg) {
	auto it = queues_.find(id);
	if (it == queues_.end()) {
		LOG->error("queue for {} is not exist", id);
		return -1;
	}
	return it->second->PushOne(msg);
}
} //end of namespace