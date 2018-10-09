#include<iostream>
#include<iomanip>
using namespace std;

class Student{
friend void change( Student &, int,int,int);  // friend declaration
// a friend function of a class is defined outside of the class.
// but has access to private members of the class.

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

private:
	int test1, test2, test3;
};

Student::Student(int a, int b, int c)
{	
	setData(a,b,c);
}

Student::~Student()         // destructor - called when object is destroyed
{	
	cout << setw(10) <<test1 << setw(10) << test2;
	cout << setw(10) << test3 << " destroyed" <<endl;
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

void change(Student &pupil, int add1, int add2, int add3)
{
	// add extra credit using friend function
	pupil.test1 += add1; 
	pupil.test2 += add2;
	pupil.test3 += add3;
}

int main()
{
	Student two;
	int qz1, qz2, qz3;

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
	change(two, 10, 20, 30);
	cout << "after the change function "  << endl;
	two.printData();
	cout << endl;
	return 0;
}

/*
student two data is
test 1, 2, 3 are         10        20        30

using the get functions
        10        20        30

after the change function
test 1, 2, 3 are         20        40        60

        20        40        60 destroyed
Press any key to continue
*/