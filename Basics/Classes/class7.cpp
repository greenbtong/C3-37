#include<iostream>
#include<iomanip>
using namespace std;

class Student{
public:
	Student(int = 0, int = 0, int = 0);	//default arguments with constructors
	~Student();				// destructor
	void setData(int, int, int);
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
	test1 = a;
	test2 = b;
	test3 = c;
}

void Student::printData()
{
	cout << "test 1, 2, 3 are " << setw(10) << test1; 
	cout << setw(10) << test2 << setw(10) << test3 << endl;
}

int main()
{
	Student one, two(50,70), cpone, cptwo;
	cout << "student one data is" << endl;
	one.printData();

	// can copy objects using default membership copy
	cpone = one; 
	cout <<endl << "student one's copy data is"  <<endl;
	cpone.printData();
	
	cout <<endl << "student two data is"  <<endl;
	two.printData();
	cptwo = two;
	cout <<endl << "student two's copy data is"  <<endl;
	cptwo.printData();
	cout <<endl <<endl;
	return 0;
}

/*
student one data is
test 1, 2, 3 are          0         0         0

student one's copy data is
test 1, 2, 3 are          0         0         0

student two data is
test 1, 2, 3 are         50        70         0

student two's copy data is
test 1, 2, 3 are         50        70         0


        50        70         0 destroyed
         0         0         0 destroyed
        50        70         0 destroyed
         0         0         0 destroyed
Press any key to continue
*/