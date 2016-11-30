#ifndef FLOW_FRAMEWORK_QUEUE_H
#define FLOW_FRAMEWORK_QUEUE_H

#include <mutex>
#include <queue>

namespace flow {
template<typename T>
class Queue {
public:
    Queue() {}

	T PopOne() {
        if (IsEmpty()) return T();
        T res = queue_.front();
        mtx.lock();
        queue_.pop();
        mtx.unlock();
        return res;
	}

	int PushOne(const T& val) {
		mtx.lock();
        queue_.push(val);
        mtx.unlock();
        return 0;
	}

	size_t GetSize() {
		mtx.lock();
		size_t n = queue_.size();
		mtx.unlock();
		return n;
	}

	bool IsEmpty() {
		mtx.lock();
		bool flag = queue_.empty();
		mtx.unlock();
		return flag;
	}
private:
	size_t size_;
	size_t capacity_;
	std::mutex mtx;
	std::queue<T> queue_;
};
}
#endif //FLOW_FRAMEWORK_QUEUE_H