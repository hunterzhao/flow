#include "flow_session.h"
#include "flow_message.h"
#include "flow_tcp_handle.h"

namespace flow {
 session_t SessionMgr::AddNewSession(uv_stream_t* tcp) {
    int session_id = maxNumber_++;
	  sessionMap_[session_id] = tcp;
    streamMap_[tcp] = session_id;
	  return session_id;
}

uv_stream_t* SessionMgr::GetSession(session_t session_id) {
  auto it = sessionMap_.find(session_id);
  if (it == sessionMap_.end()) {
     std::cout << "connection doesn't exist" << std::endl;
     exit(1);
  }
  return sessionMap_[session_id];
}

session_t SessionMgr::GetSessionID(uv_stream_t* stream) {
  auto it = streamMap_.find(stream);
  if (it == streamMap_.end()) {
     std::cout << "connection doesn't exist" << std::endl;
     exit(1);
  }
  return streamMap_[stream];
}

int SessionMgr::RemoveSession(session_t session_id) {
	  auto it = sessionMap_.find(session_id);
	  if (it == sessionMap_.end())
	  	return -1;
	  sessionMap_.erase(it);
	  return 0;
}

int SessionMgr::SendMessage(session_t session_id, FlowMessagePtr msg) {
    auto it = sessionMap_.find(session_id);
    if (it == sessionMap_.end())
         return -1;
    TcpHandle::SendMessage(it->second, msg);
    return 0;
}
}