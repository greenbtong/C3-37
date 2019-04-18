#ifndef __THREAD_H
#define __THREAD_H

#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <condition_variable>
#include <queue>
using namespace std;

// threadtype
enum ThreadType {
	PRODUCER,
	CONSUMER
};

class Thread {
private:
	string name;
	thread *pT;
	ThreadType tType;
	static mutex cLock;
	static condition_variable uReady;
	static bool ready;
	static queue<int> appQ;
	bool stopp;
	void run();
public:
	Thread(ThreadType typeT);
	~Thread();
	void start();
	void stop();
	void join();
	void detach();
};

#endif