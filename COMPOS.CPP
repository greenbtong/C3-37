// composition example
// a class can have objects of other classes as members

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Student
{
	public:
		Student( int = 1, int = 1, int = 1); // default constructor
		void print() const;
		~Student();
	private:
		int test1, test2, test3;
};

Student::Student( int a, int b, int c)
{
	test1 = a;
	test2 = b;
	test3 = c;
	cout << "INSIDE STUDENT CONSTRUCTOR with " << setw(10) << test1;
	cout << setw(10) << test2 << setw(10) << test3 <<endl << endl;
}

void Student::print() const
{
	cout << "the three test scores are " << setw(10) << test1;
	cout << setw(10) << test2 << setw(10) << test3 << endl;
}

Student::~Student()
{
	cout << "INSIDE THE STUDENT DESTRUCTOR with test scores:" << endl;
	print();
	cout << endl;
}

class Transcript
{
	public:
		Transcript( char *, char *, int, int, int, int, int, int);
		void print() const;
		~Transcript();
	private:
		char firstName[25];
		char lastName[25];
		const Student engTests;
		const Student mathTests;
};

Transcript::Transcript(char *fname, char *lname,
								int t1a, int t2a, int t3a,
								int t1b, int t2b, int t3b)
								:engTests(t1a, t2a, t3a),
								 mathTests(t1b, t2b, t3b)

// must specify after the colon which arguments are being passed
// to the constructors for the Student objects.

{
	strcpy(firstName, fname);
	strcpy(lastName, lname);
	cout << "INSIDE TRANSCRIPT CONSTRUCTOR with " << firstName;
	cout << " " << lastName << endl << endl;
}

void Transcript::print() const
{
	cout << "INSIDE THE TRANSCRIPT PRINT ROUTINE" << endl;
	cout << lastName << ", " << firstName << endl;
	cout << "the English test scores are: " << endl;
	engTests.print();
	cout << endl <<"the Math test scores are: " << endl;
	mathTests.print();
	cout << endl;
}

Transcript::~Transcript()
{
	cout << "INSIDE THE TRANSCRIPT DESTRUCTOR with the person:" << endl;
	cout << lastName << ", " << firstName << endl << endl;
}

int main()
{
	Transcript t("Mary", "Jones", 10, 20, 30, 40, 50, 60);
	t.print();
	Student s(80, 90, 100); // can still just declare a Student
	s.print();
	return 0;
}

/*
INSIDE STUDENT CONSTRUCTOR with         10        20        30

INSIDE STUDENT CONSTRUCTOR with         40        50        60

INSIDE TRANSCRIPT CONSTRUCTOR with Mary Jones

INSIDE THE TRANSCRIPT PRINT ROUTINE
Jones, Mary
the English test scores are:
the three test scores are         10        20        30

the Math test scores are:
the three test scores are         40        50        60

INSIDE STUDENT CONSTRUCTOR with         80        90       100

the three test scores are         80        90       100
INSIDE THE STUDENT DESTRUCTOR with test scores:
the three test scores are         80        90       100

INSIDE THE TRANSCRIPT DESTRUCTOR with the person:
Jones, Mary

INSIDE THE STUDENT DESTRUCTOR with test scores:
the three test scores are         40        50        60

INSIDE THE STUDENT DESTRUCTOR with test scores:
the three test scores are         10        20        30

Press any key to continue . . .  
*/
