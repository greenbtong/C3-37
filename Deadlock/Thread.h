#ifndef __THREAD_H
#define __THREAD_H

#include <iostream>
#include <thread>
#include <mutex>
#include <string>
using namespace std;

// threadtype
enum ThreadType {
	READER,
	WRITER
};

class Thread {
private:
	string name;
	thread *pT;	
	ThreadType tType;
	static mutex cLock;
	static int count;
	bool stopp;
	void run();
public:
	Thread(ThreadType typeT);
	~Thread();
	void start();
	void stop();
	void join();
	void detach();
	int getCount();
	int updateCount();
};

#endif