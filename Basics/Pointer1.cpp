#include<iostream>
using namespace std;

class Student{
public:
	Student();				//default constructor
	void getData(int, int, int);
	void printData();

private:
	int test1, test2, test3;
	float avg;
};

Student::Student()
	{ test1 = test2 = test3 = 1;
	  avg = (test1 + test2 + test3) / (float)3;	}

void Student::getData(int a, int b, int c)
{
	test1 = a;
	test2 = b;
	test3 = c;
	avg = (test1 + test2 + test3) / (float)3;
}

void Student::printData()
{
	cout << "test 1 is " << this->test1 << endl;
	cout << "test 2 is " << this->test2 << endl;
	cout << "test 3 is " << this->test3 << endl;
	cout << "the average is " << this->avg << endl;
}

// Every object has access to its own address through the this pointer.
// can reference both the data members and member functions of an object.
// Will be used later to prevent an object from being assigned to itself
// in operator overloading.  Also, this enables cascading member function calls.
// eg two.setData(50,60,70).printData();

int main()
{
	Student one, two;
	cout << "student one data is" << endl;
	one.printData();
	two.getData(10, 15, 30);
	cout <<endl << "student two data is"  <<endl;
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
Press any key to continue
*/