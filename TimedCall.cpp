#include "TimedCall.h"
TimedCall::TimedCall(std::function<void()> f, uint32_t time) {

	this->f = f;
	time_ = time;
}
void TimedCall::Update() { 
	if (flag) {
		return;
	}
	time_--;
	if (time_ <= 0) {
		flag = true;
		f();
	}
}