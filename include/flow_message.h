#ifndef FLOW_FRAMEWORK_MESSAGE_H
#define FLOW_FRAMEWORK_MESSAGE_H

#include <string.h>
#include "flow.h"
#include <iostream>
namespace flow {
class FlowMessage {
public:
   FlowMessage() {
      // data_ = new char[100];
      // ::memset(data_, 0, 100);
   }

   ~FlowMessage() {
      // delete[] data_;
      // data_ = nullptr;
   }
   char * GetData() { return data_; }
   size_t GetDataLen() { return data_len_; }
   
   void SetData(char* data, size_t data_len) {	 
      data_len_ = data_len + 1;
      if (data_ == nullptr) {
        data_ = (char*)malloc(data_len_ * sizeof(char));
        ::memset(data_, 0, data_len_);
      } else {
        //FreeData();
      }
      ::memcpy(data_, data, data_len_);
      
   }

   void FreeData() {
      free(data_);
      data_ = nullptr;
   }
private:
   char * data_ = nullptr;
   size_t data_len_ = 0;
};
DEFINE_SHARED_PTR(FlowMessage);
}
#endif //FLOW_FRAMEWORK_MESSAGE_H