#include<iostream>
#include<iomanip>
using namespace std;

// demonstration of the this pointer to cascade member function calls
class Student{
public:
	Student(int = 0, int = 0, int = 0);	//default arguments with constructors
	~Student();				// destructor
	Student &setData(int, int, int);
	Student &setTest1(int); // set functions
	Student &setTest2(int);
	Student &setTest3(int);
	int getTest1() const; //get functions
	int getTest2() const; // const means object cannot be modified
	int getTest3() const;
	void printData() const;

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

Student &Student::setData(int a, int b, int c)
{
	setTest1(a);
	setTest2(b);
	setTest3(c);
	return *this;	// enables cascading
}

Student &Student::setTest1(int a)
{ test1 = a;
  return *this;
}

Student &Student::setTest2(int b)
{ test2 = b;
  return *this; 
}

Student &Student::setTest3(int c)
{ test3 = c;
   return *this;
}
  
int Student::getTest1() const
{ return test1; }

int Student::getTest2() const
{ return test2; }

int Student::getTest3() const
{ return test3; }

void Student::printData() const
{
	cout << "test 1, 2, 3 are " << setw(10) << test1; 
	cout << setw(10) << test2 << setw(10) << test3 << endl;
}

int main()
{
	Student one, two;
	
	one.setTest1(10).setTest2(20).setTest3(30);  // cascade member function calls
	cout << "student one data is" << endl;
	one.printData();
	
	cout << endl << "student two data is" << endl;
    two.setData(50,60,70).printData();
	cout << endl;

	// get functions still work the same
	int qz1 = two.getTest1();
	cout << "first test score of student two is " << qz1 <<endl << endl;
	
	return 0;
}

/*
student one data is
test 1, 2, 3 are         10        20        30

student two data is
test 1, 2, 3 are         50        60        70

first test score of student two is 50

        50        60        70 destroyed
        10        20        30 destroyed
Press any key to continue
*/