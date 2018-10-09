#include<iostream>
#include<iomanip>
using namespace std;

// a static data member is shared by all the objects of the same type
// that is, each object does not have it's own static data member but
// all objects of the same type can access the same static data member

class Student{
public:
	Student(int = 0, int = 0, int = 0);	//default arguments with constructors
	~Student();				// destructor
	void setData(int, int, int);
	void setTest1(int); // set functions
	void setTest2(int);
	void setTest3(int);
	int getTest1(); //get functions
	int getTest2();
	int getTest3();
	void printData();
	static int getCount();  // return # objects instantiated

private:
	int test1, test2, test3;
	static int count;  // one variable for all of the objects
};

// initialize the static data member
int Student:: count = 0;

// static member function to return count
int Student::getCount()
	{
		return count;
	}

Student::Student(int a, int b, int c)
{
	count++ ;
	setData(a,b,c);
}

Student::~Student()         // destructor - called when object is destroyed
{
	cout << setw(10) <<test1 << setw(10) << test2;
	cout << setw(10) << test3 << " destroyed" <<endl;
	count--;
	cout << "destructor - # data is " << Student::getCount() << endl;
}

void Student::setData(int a, int b, int c)
{
	setTest1(a);
	setTest2(b);
	setTest3(c);
}

void Student::setTest1(int a)
{ test1 = a;}

void Student::setTest2(int b)
{ test2 = b;}

void Student::setTest3(int c)
{ test3 = c;}

int Student::getTest1()
{ return test1; }

int Student::getTest2()
{ return test2; }

int Student::getTest3()
{ return test3; }

void Student::printData()
{
	cout << "test 1, 2, 3 are " << setw(10) << test1;
	cout << setw(10) << test2 << setw(10) << test3 << endl;
}

int main()
{
	cout << "number of data is " << Student::getCount() << endl;
	Student one, two;
	cout << "number of data is " << Student::getCount() << endl;
	int qz1, qz2, qz3;
	cout << "student one data is" << endl;
	one.printData();

	two.setTest1(10);
	two.setTest2(20);
	two.setTest3(30);
	cout <<endl << "student two data is"  <<endl;
	two.printData();

	cout <<endl;
	qz1 = two.getTest1();
	qz2 = two.getTest2();
	qz3 = two.getTest3();
	cout << "using the get functions" << endl;
	cout << setw(10) << qz1 << setw(10) << qz2;
	cout << setw(10) << qz3 << endl << endl;

	return 0;
}
/*
number of data is 0
number of data is 2
student one data is
test 1, 2, 3 are          0         0         0

student two data is
test 1, 2, 3 are         10        20        30

using the get functions
		  10        20        30

		  10        20        30 destroyed
destructor - # data is 1
			0         0         0 destroyed
destructor - # data is 0
*/