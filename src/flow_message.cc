#include "flow_message.h"

namespace flow {
FlowMessage::FlowMessage() {
      document_.SetObject();
      // data_ = new char[100];
      // ::memset(data_, 0, 100);
   }
   
FlowMessage::~FlowMessage() {

}

const char* FlowMessage::GetOptionStr(const char* key) {
    return document_[key].GetString();
}

int FlowMessage::GetOptionInt(const char* key) {
    return document_[key].GetInt();
}

void FlowMessage::AddOption(const char* key, const char* val) { 
  // rapidjson::Value option;
  // char buffer[10];
  // int len = sprintf(buffer, "%s", key); 
  // option.SetString(val, static_cast<rapidjson::SizeType>(len), document_.GetAllocator());
  document_.AddMember(rapidjson::Value(key, document_.GetAllocator()), rapidjson::Value(val, document_.GetAllocator()), document_.GetAllocator());
}

void FlowMessage::AddOption(const char* key, int val) { 
  document_.AddMember(rapidjson::Value(key, document_.GetAllocator()), rapidjson::Value(val), document_.GetAllocator());
}

void FlowMessage::Encode(const char* json) {
  if (document_.Parse(json).HasParseError()) {
     std::cout << "encode error" << std::endl;
  }
}

const char* FlowMessage::Decode() {
  rapidjson::StringBuffer decode;
  rapidjson::Writer<rapidjson::StringBuffer> writer(decode);
  document_.Accept(writer);
  return decode.GetString();
}

void FlowMessage::SetData(const char* data, size_t data_len) {	 
  data_len_ = data_len + 1;
  if (data_ != nullptr) 
    FreeData();

  data_ = (char*)malloc(data_len_ * sizeof(char));
  ::memset(data_, 0, data_len_);
  ::memcpy(data_, data, data_len_);
}

void FlowMessage::FreeData() {
  free(data_);
  data_ = nullptr;
}
}