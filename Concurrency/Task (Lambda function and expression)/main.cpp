// concurrency - task - work that happens concurrently across threads
#include <iostream>
#include <future> 
#include <functional>
#include <climits>
#include <exception>
using namespace std;

//// basic case
//int main() {
//	packaged_task <int(int, int)>
//		addTask([](int firstIn, int secondIn) {
//		return firstIn + secondIn;
//			});
//	future<int> output = addTask.get_future();
//	addTask(15, 10);
//	cout << " The sum of 15 + 10 is " << output.get() << endl;
//	
//	return 0;
//}

void add(int firstIn, int secondIn, promise<int> output) {
	try {
		if ((INT_MAX == firstIn) || (INT_MAX == secondIn))
			output.set_exception(current_exception());
	}
	catch (...) {}
	output.set_value(firstIn + secondIn);
}

int main() {
	try {
		promise<int> promise_;
		future<int> output = promise_.get_future();
		async(launch::deferred, add, INT_MAX, INT_MAX, move(promise_));
		cout << output.get() << endl;
	}
	catch (exception e) {
		cerr << "Exception occured" << endl;
	}
}