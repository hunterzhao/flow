#ifndef FLOW_FRAMEWORK_FLOW_STAGE_H
#define FLOW_FRAMEWORK_FLOW_STAGE_H

#include "flow.h"
#include "flow_queue.h"
#include "flow_actor.h"

namespace flow {

class FlowActor;
class FlowManager;
DEFINE_SHARED_PTR(FlowActor);
DEFINE_SHARED_PTR(FlowManager);
class FlowStage {
public:
	FlowStage(FlowQueuePtr queue, int id);
	virtual ~FlowStage();
	virtual void Run(); // for thread
    virtual int OnEvent(FlowMessagePtr msg);
    virtual int OnStart();
    virtual int OnStop();
    
    int AddActor(FlowActorPtr actor);
    int RemoveActor(std::string actorid);
    FlowActorPtr GetActor(std::string);
    
    FlowManagerPtr GetManager();
    int SetManager(FlowManagerPtr);

    int Getid();

    int Publish(FlowMessagePtr msg);
    int Request(std::string conn_id, FlowMessagePtr msg);
    int Subscribe(std::string conn_id, FlowMessagePtr msg);

    
private:
	int stageid_;
	FlowManagerPtr manager_;
	FlowQueuePtr queue_;

protected:
	std::unordered_map<std::string, FlowActorPtr> actorMap_;
};
DEFINE_SHARED_PTR(FlowStage);
} // end of namespace flow
#endif //FLOW_FRAMEWORK_FLOW_STAGE_H