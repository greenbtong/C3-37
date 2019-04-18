#include "Thread.h"

mutex Thread::cLock;

//thread
Thread::Thread(ThreadType typeT) {
	pT = NULL;
	stopp = false;
	tType = typeT;
	(tType == READER) ? name = "READER" : name = "WRITER";
}

Thread::~Thread() {
	delete pT;
	pT = NULL;
}

// thread get count (deadlock)
int Thread::getCount( ) {
	cout << name << " is waiting for lock in the getCount()" << endl;
	lock_guard<mutex> locker(cLock);
	cout << name << " has achieved lock in the getCount()" << endl;
	return count;
}

// thread update count (deadlock)
int Thread::updateCount( ) {
	int value = getCount();
	cout << name << " is waiting for lock in the updateCount()" << endl;
	lock_guard<mutex> locker(cLock);
	cout << name << " has achieved lock in the updateCount()" << endl;
	count = ++value;
	return count;
}

// thread run
void Thread::run() {
	while (1) {
		switch (tType) {
		case READER:
			cout << name << " - getCount(): " << getCount() << endl;
			break;

		case WRITER:
			cout << name << " - updateCount(): " << updateCount() << endl;
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