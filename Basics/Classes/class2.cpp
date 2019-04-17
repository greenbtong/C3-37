#include<iostream>
using namespace std;

// adding some methods (functions for the objects) to the class
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

int main()
{
	Student one, two;  // constructor is called once for each object instantiated
	cout << "student one data is" << endl;
	one.printData();
	two.setData(10, 15, 30);
	cout << endl << "student two data is"  <<endl;
	two.printData();
	return 0;
}

/*
student one data is
test 1 is 1
test 2 is 1
test 3 is 1
the average is 1

student two data is
test 1 is 10
test 2 is 15
test 3 is 30
the average is 18.3333
Press any key to continue . . .
*/
