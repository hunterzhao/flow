#ifndef FLOW_FRAMEWORK_FLOW_STAGE_H
#define FLOW_FRAMEWORK_FLOW_STAGE_H

#include "flow.h"
#include "flow_queue.h"
namespace flow {

class FlowStage {
public:
	FlowStage(FlowQueuePtr queue);
	virtual ~FlowStage();
	virtual void Run(); // for thread
    virtual int OnEvent(FlowMessage msg);
    virtual int OnStart();
    virtual int OnStop();

private:
	int stageid_;
	FlowQueuePtr queue_;
};
DEFINE_SHARED_PTR(FlowStage);
} // end of namespace flow
#endif //FLOW_FRAMEWORK_FLOW_STAGE_H