#include<iostream>
using namespace std;

class Student{
public:
	Student();				//default constructor
	~Student();				// destructor
	// destructor is automatically called when an object goes out of scope
	// destructor MUST have the same name as the class with a tilde ~ in front
	void setData(int, int, int);
	void printData();

private:
	int test1, test2, test3;
};

Student::Student()
	{ test1 = test2 = test3 = 1;}

Student::~Student()  
{	
	cout << "a student has been destructed" <<endl;
	cout << "first test score for the student is " << test1 <<endl;
}

void Student::setData(int a, int b, int c)
{
	test1 = a;
	test2 = b;
	test3 = c;
}

void Student::printData()
{
	cout << "test 1 is " << test1 << endl;
	cout << "test 2 is " << test2 << endl;
	cout << "test 3 is " << test3 << endl;
}

int main()
{
	Student one, two;
	cout << "student one data is" << endl;
	one.printData();
	two.setData(10, 20, 30);
	cout <<endl << "student two data is"  <<endl;
	two.printData();
	cout <<endl <<endl;
	return 0;
}

/*
student one data is
test 1 is 1
test 2 is 1
test 3 is 1

student two data is
test 1 is 10
test 2 is 20
test 3 is 30


a student has been destructed
first test score for the student is 10
a student has been destructed
first test score for the student is 1
Press any key to continue


Note destructor calls are made in the reverse order of the constructor calls.
*/