// Deadlock concept
#include "Thread.h"

int main() {

	Thread reader(READER);
	Thread writer(WRITER);

	reader.start();
	writer.start();

	reader.join();
	writer.join();

	return 0;
}