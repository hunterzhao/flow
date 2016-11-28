#include "flow_stage.h"

namespace flow {
FlowStage::FlowStage(FlowQueuePtr queue) : queue_(queue) {

}

FlowStage::~FlowStage() {

}

void FlowStage::Run() {
	int ret = 0;
	ret = OnStart();
	if (ret < 0) {

	}

	while(queue_) {
		if (queue_->IsEmpty())
			continue;
       FlowMessage msg = queue_->PopOne();
       if (OnEvent(msg) < 0)
       	   break;
	}
	
	ret = OnStop();
	if (ret < 0) {

	}
}

int FlowStage::OnEvent(FlowMessage msg) {
   
}

int FlowStage::OnStart() {
   
}

int FlowStage::OnStop() {

}

}