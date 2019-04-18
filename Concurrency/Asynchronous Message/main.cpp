//asynchronous message (concurrency) hello world
#include <iostream>
#include <future>
using namespace std;

void Hi(promise<string> promise_) {
	promise_.set_value("Hi - Concurrency");
}

int main()
{
	promise<string> promiseObj;

	future<string> futureObj = promiseObj.get_future(); 
	async(launch::async, Hi, move(promiseObj));
	cout << futureObj.get() << endl;
	return 0;
   
}

