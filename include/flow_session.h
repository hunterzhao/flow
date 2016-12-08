#ifndef FLOW_FRAMEWORK_SESSION_H
#define FLOW_FRAMEWORK_SESSION_H
#include <unordered_map>
#include <iostream>

#include "flow.h"
#include "singleton.h"
#include "uv.h"

namespace flow {

typedef int session_t;
class FlowMessage;
DEFINE_SHARED_PTR(FlowMessage);
class SessionMgr : public Singleton<SessionMgr> {
public:
   friend class Singleton<SessionMgr>;
   session_t AddNewSession(uv_stream_t* tcp);
   uv_stream_t* GetSession(session_t session_id);
   session_t GetSessionID(uv_stream_t* stream);
   int RemoveSession(session_t session_id);
   int SendMessage(session_t session_id, FlowMessagePtr msg);
private:
   SessionMgr() = default;
   std::unordered_map<session_t, uv_stream_t*> sessionMap_;
   std::unordered_map<uv_stream_t*, session_t> streamMap_;
   session_t maxNumber_ = 1;
};
}
#endif //FLOW_FRAMEWORK_SESSION_H