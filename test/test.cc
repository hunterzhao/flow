#include "flow_message.h"
#include "flow_session.h"
#include "uv.h"
#include "gtest/gtest.h"

using namespace flow;


/*************************
*
* Test FlowMessage
*
**************************/
//test addoption string val
TEST(flow_message_test, AddOptionStrTest) {
   FlowMessage msg;
   const char* s = "hello world";
   const char* key="hello";
   msg.AddOption(key,s);
   EXPECT_EQ(0, strcmp(msg.GetOptionStr(key), s));
   EXPECT_EQ(strlen(msg.GetOptionStr(key)),strlen(s));
} 

//test addoption int val
TEST(flow_message_test, AddOptionIntTest) {
   FlowMessage msg;
   int val = 8868;
   const char* key="hello";
   msg.AddOption(key,val);
   EXPECT_EQ(msg.GetOptionInt(key), val);
} 

//test encode decode 
TEST(flow_message_test, EncodeAndDecodeTest) {
   FlowMessage msg;
   const char* json = "{\"key1\":\"val1\",\"key2\":\"val2\"}";
   msg.Encode(json);
   EXPECT_EQ(0, strcmp(msg.Decode().c_str(), json));
}

/*************************
*
* Test FlowSession
*
**************************/
uv_stream_t* tcp = (uv_stream_t*)malloc(sizeof(uv_tcp_t));;
TEST(flow_session_test, AddNewSessionTest){
   session_t id = SessionMgr::Instance().AddNewSession(tcp);
   EXPECT_EQ(SessionMgr::Instance().GetSession(id), tcp);
}


