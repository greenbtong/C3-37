//hello world using concurrrency 
#include <iostream>
#include <future>
using namespace std;

void Hi() {
	cout << endl << "Hello - Concurrency" << endl;
}

//simple case
int main() {
	future<void> futureObj = async(launch::async, Hi);
	futureObj.wait();
	return 0;
}

