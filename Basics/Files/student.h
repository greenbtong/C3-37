#include <iostream>
using namespace std;

class Student{
public:
	Student();				//default constructor
	// constructor is automatically called when an object is instantiated
	// constructor MUST have the same name as the class
	void setData(int, int, int);
	void printData();

private:
	int test1, test2, test3;
	float avg;
};

Student::Student()
	{ test1 = test2 = test3 = 1;
	  avg = (test1 + test2 + test3) / (float)3;	}

void Student::setData(int a, int b, int c)
{
	test1 = a;
	test2 = b;
	test3 = c;
	avg = (test1 + test2 + test3) / (float)3;
}

void Student::printData()
{
	cout << "test 1 is " << test1 << endl;
	cout << "test 2 is " << test2 << endl;
	cout << "test 3 is " << test3 << endl;
	cout << "the average is " << avg << endl;
}
