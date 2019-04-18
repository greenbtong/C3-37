#include "Thread.h"

mutex Thread::locker;


//thread
Thread::Thread(Account* pA, ThreadType typeT) {
	this->pA = pA;
	pT = NULL;
	stopp = false;
	tType = typeT;
}

Thread::~Thread() {
	delete pT;
	pT = NULL;
}

// thread run
void Thread::run() {
	while (1) {
		switch (tType) {
		case DEPO:
			locker.lock();

			cout << "Depositor current balance is: " << pA->getBalance() << endl;
			pA->deposit(2000);
			cout << "Depositor: New Balance: " << pA->getBalance() << endl;

			locker.unlock();
			break;

		case WITH:
			locker.lock();

			cout << "Withdrawer current balance is: " << pA->getBalance() << endl;
			pA->withdraw(1000);
			cout << "Withdrawer: New Balance: " << pA->getBalance() << endl;

			locker.unlock();		
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