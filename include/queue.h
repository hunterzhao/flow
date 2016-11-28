#ifndef FLOW_FRAMEWORK_QUEUE_H
#define FLOW_FRAMEWORK_QUEUE_H

#include <queue>

namespace flow {
template<typename T>
class Queue {
public:
    Queue() {}

	T PopOne() {
        if (IsEmpty()) return T();
        T res = queue_.front();
        queue_.pop();
        return res;
	}

	int PushOne(const T& val) {
        queue_.push(val);
        return 0;
	}

	size_t GetSize() {
		return queue_.size();
	}

	bool IsEmpty() {
		return queue_.empty();
	}
private:
	size_t size_;
	size_t capacity_;
	std::queue<T> queue_;
};
}
#endif //FLOW_FRAMEWORK_QUEUE_H