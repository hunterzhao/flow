#ifndef FLOW_FRAMEWORK_FLOW_QUEUE_H
#define FLOW_FRAMEWORK_FLOW_QUEUE_H

#include "flow.h"
#include "singleton.h"
#include "flow_message.h"
#include "queue.h"
#include <unordered_map>

namespace flow {

typedef Queue<FlowMessage> FlowQueue;
DEFINE_SHARED_PTR(FlowQueue);

class FlowQueueMgr : public Singleton<FlowQueueMgr> {
public:
   friend class Singleton<FlowQueueMgr>;
   ~FlowQueueMgr();
   FlowQueuePtr CreateQueue(int id);
   FlowQueuePtr GetQueue(int id);
   int RemoveQueue(int id);
   int SendMessage(int id, FlowMessagePtr msg); 

private:
   FlowQueueMgr() = default;
   std::unordered_map<int, FlowQueuePtr> queues_;
};

} //namespace flow

#endif //FLOW_FRAMEWORK_FLOW_QUEUE_H