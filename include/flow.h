#ifndef FLOW_H
#define FLOW_H

#include <memory>
namespace flow {
#define FLOW_VERSION 0.0

// micro
#define DEFINE_SHARED_PTR(TypeName) \
	typedef std::shared_ptr<TypeName> TypeName##Ptr
 
#define ASSERT(expr)                                      \
 do {                                                     \
  if (!(expr)) {                                          \
    fprintf(stderr,                                       \
            "Assertion failed in %s on line %d: %s\n",    \
            __FILE__,                                     \
            __LINE__,                                     \
            #expr);                                       \
    abort();                                              \
  }                                                       \
 } while (0)


} //namespace flow
#endif //FLOW_H