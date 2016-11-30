#ifndef FLOW_FRAMEWORK_QUEUE_H
#define FLOW_FRAMEWORK_QUEUE_H

#include <mutex>
#include <condition_variable>
#include <queue>

namespace flow {
template<typename T>
class Queue {
public:
    Queue() {}

	T PopOne() {
		std::unique_lock<std::mutex> lck(mtx_);
        cv.wait(lck, [this] { return !queue_.empty();});
        T res = queue_.front();
        queue_.pop();
        return res;
	}

	int PushOne(const T& val) {
		std::unique_lock<std::mutex> lck(mtx_);
        queue_.push(val);
        cv.notify_one(); 
        return 0;
	}

	size_t GetSize() {
		std::lock_guard<std::mutex> lck(mtx_);
		size_t n = queue_.size();
		return n;
	}

	bool IsEmpty() {
		std::lock_guard<std::mutex> lck(mtx_);
		return queue_.empty();
	}
private:
	size_t size_;
	size_t capacity_;
	std::mutex mtx_;
	std::condition_variable cv;
	std::queue<T> queue_;
};
}
#endif //FLOW_FRAMEWORK_QUEUE_H