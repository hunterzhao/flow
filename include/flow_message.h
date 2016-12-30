#ifndef FLOW_FRAMEWORK_MESSAGE_H
#define FLOW_FRAMEWORK_MESSAGE_H

#include <string.h>
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "flow.h"

namespace flow {
class FlowMessage {
public:
   enum {
      Subscribe,
      Publish,
      Request
   };
   FlowMessage();

   ~FlowMessage();

   const char* GetOptionStr(const char* key);
   int GetOptionInt(const char* key);

   void AddOption(const char* key, const char* val);
   void AddOption(const char* key, int val);
   
   void Encode(const char* json);

   std::string Decode();

   void SetData(const char* data, size_t data_len);

   void FreeData();

private: //??
   FlowMessage(FlowMessage const & other) {  //???
      // this.document_ = other.document_;
   }
   char * data_ = nullptr;
   size_t data_len_ = 0;
   rapidjson::Document document_;
};
DEFINE_SHARED_PTR(FlowMessage);
}
#endif //FLOW_FRAMEWORK_MESSAGE_H