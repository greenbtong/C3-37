#include<iostream>
#include<iomanip>
using namespace std;

// same as class8 but a function has been added to change
// a student's values (adds 10 points to test2 and 20 points to test3)

class Student{
public:
	Student(int = 0, int = 0, int = 0);	//default arguments with constructors
	~Student();				// destructor
	void setData(int, int, int);
	void setTest1(int); // set functions (mutators)
	void setTest2(int);
	void setTest3(int);
	int getTest1(); //get functions (accessors)
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

void change( Student &); // prototype for function to change a student's values

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
	change(two);
	cout << "after the change function "  << endl;
	two.printData();
	cout << endl;
	return 0;
}

void change(Student &pupil)
{
	// add extra credit for test 2 and test 3
	pupil.setTest2(pupil.getTest2() + 10);
	pupil.setTest3(pupil.getTest3() + 20);
}

/*
student two data is
test 1, 2, 3 are         10        20        30

using the get functions
        10        20        30

after the change function
test 1, 2, 3 are         10        30        50

        10        30        50 destroyed
*/

