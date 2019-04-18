#ifndef __THREAD_H
#define __THREAD_H

#include <iostream>
#include <thread>
#include <mutex>
#include "Account.h"
using namespace std;

// threadtype
enum ThreadType {
	DEPO,
	WITH
};

class Thread {
private:
	thread* pT;
	Account* pA;
	static mutex locker;
	ThreadType tType;
	bool stopp;
	void run();
public:
	Thread(Account* pA, ThreadType typeT);
	~Thread();
	void start();
	void stop();
	void join();
	void detach();
};

#endif