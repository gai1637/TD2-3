#pragma once
#include<functional>

class TimedCall {
public:
	TimedCall(std::function<void()> f, uint32_t time);
	void Update();
	bool IsFinished() { return flag; }

private:
	std::function<void()> f;
	uint32_t time_;
	bool flag = false;
};
