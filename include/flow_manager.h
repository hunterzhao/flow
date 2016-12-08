#ifndef FLOW_FRAMEWORK_FLOW_MANAGER_H
#define FLOW_FRAMEWORK_FLOW_MANAGER_H

#include <unordered_set>
#include <unordered_map>

#include "singleton.h"


namespace flow {
class TcpHandlerPtr;
class FlowStagePtr;
class FlowManager : public Singleton<FlowManager> {
public:
    int Init();
    int AddHandle(TcpHandlePtr);
    int start();  //create and add stages
    int stop();   //destroy stages

private:
	FlowManager();
	~FlowManager();
    std::unordered_set<TcpHandlePtr> handlers_;  //network manager
    std::unordered_map<int, FlowStagePtr> stages_;  //work manager
};
}
#endif