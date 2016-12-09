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
       FlowMessagePtr msg = queue_->PopOne();
       if (OnEvent(msg) < 0)
       	   break;
	}
	
	ret = OnStop();
	if (ret < 0) {

	}
	return;
}

int FlowStage::OnEvent(FlowMessagePtr msg) {
   return 1;
}

int FlowStage::OnStart() {
   return 1;
}

int FlowStage::OnStop() {
   return 1;
}

}