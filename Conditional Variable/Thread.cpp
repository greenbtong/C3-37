#include "Thread.h"

mutex Thread::cLock;
condition_variable Thread::uReady;
bool Thread::ready = false;
queue<int> Thread::appQ;

//thread
Thread::Thread(ThreadType typeT) {
	pT = NULL;
	stopp = false;
	tType = typeT;
	(tType == CONSUMER) ? name = "CONSUMER" : name = "PRODUCER";
}

Thread::~Thread() {
	delete pT;
	pT = NULL;
}

// thread run
void Thread::run() {
	int count = 0;
	int data = 0;
	while (1) {
		switch (tType) {
		case CONSUMER:
		{
			cout << name << " acquiring mutex " << endl;
			unique_lock<mutex> uniqueLocker(cLock);
			cout << name << " acquired mutex" << endl;

			cout << name << " waiting for conditional variable signal" << endl;
			uReady.wait(uniqueLocker, [] {return ready; });
			cout << name << " recieved conditional signal" << endl;


			data = appQ.front();
			cout << name << " data:" << data << endl;

			appQ.pop();
			ready = false;
		}
		cout << name << " released mutex" << endl;
		case PRODUCER:
		{
			cout << name << " acquiring mutex " << endl;
			unique_lock<mutex> uniqueLocker(cLock);
			cout << name << " acquired mutex" << endl;

			if (count == 32000) count = 0;
			appQ.push(++count);

			ready = true;

			uniqueLocker.unlock();
			cout << name << "released mutex" << endl;
			uReady.notify_one();
			cout << name << "notified condtional signal" << endl;
		}
			break;

		
		}

	}
}

// thread start
void Thread::start() {
	pT = new thread(&Thread::run, this);
}

// thread stop
void Thread::stop() {
	stopp = true;
}

// thread join
void Thread::join() {
	pT->join();
}

// thread detach
void Thread::detach() {
	pT->detach();
}