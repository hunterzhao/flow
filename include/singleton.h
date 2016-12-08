#ifndef FLOW_FRAMEWORK_SINGLETON_H
#define FLOW_FRAMEWORK_SINGLETON_H

namespace flow {
template <typename T>
class Singleton {
public:
	static T& Instance() {
		static T t; //static local variable //construct and init happen here destruct when the program end
		return t;
	}

protected: //the child object need this
	Singleton() = default; 
	~Singleton() {}
	
private:
	
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
};
} // end of namespace

#endif //FLOW_FRAMEWORK_SINGLETON_H