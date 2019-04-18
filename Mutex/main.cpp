// mutex using a money balance
#include "Thread.h"" 
#include "Account.h"

int main() {
	Account account(5000.00);

	Thread depositor( &account, ThreadType::DEPO);
	Thread withdrawer( &account, ThreadType::WITH);

	depositor.start();
	withdrawer.start();

	depositor.join();
	withdrawer.join();

	return 0;
}