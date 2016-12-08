#ifndef FLOW_FRAMEWORK_EVENT_H
#define FLOW_FRAMEWORK_EVENT_H

#include <string>

class Event
{
public:
	Event() {};
	~Event() {};
public:
    std::string data;
    int sender;
};
#endif //FLOW_FRAMEWORK_EVENT_H