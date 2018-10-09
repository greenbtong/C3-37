#include<iostream>
using namespace std;

// overloading binary and relational operators
// binary operators have two operands such as + - * /
// relational operators see how two operands relate such as
// == != < <= > >=

class Student
{
	friend ostream &operator<<( ostream&, const Student&);

public:
	Student(int = 0, int = 0, int = 0);

	Student operator+(const Student &rhs) const
	{
		return Student(test1 + rhs.test1, test2 + rhs.test2, test3 + rhs.test3);
	}

	bool operator> (const Student &rhs) const
	{
		return test1 > rhs.test1;
	}
	
private:
	int test1, test2, test3;
};

// constructor
Student::Student(int a, int b, int c)
		: test1(a), test2(b), test3(c)  {}

// overloaded stream-insertion operator
ostream &operator<<( ostream &output, const Student &one)
{
	output << "test 1 is " << one.test1 << "   ";
	output << "test 2 is " << one.test2 << "   ";
	output << "test 3 is " << one.test3 << endl;
	return output; // enables cascading eg cout << a << b << c;
}

// stream-extraction operator not overloaded in this program

int main()
{
	Student s1(10,20,30), s2(1,2,3), s3;
	cout <<"student 1 data is: " << s1 << endl;
	cout <<"student 2 data is: " << s2 << endl;
	s3 = s1 + s2;
	cout <<"student 3 data is: " << s3 << endl;
	if (s2 > s1)
		cout << "student 2 has a higher test 1 score " << endl;
	else
		cout << "student 2 does not have a higher test 1 score " << endl;
	return 0;
}
/*
student 1 data is: test 1 is 10   test 2 is 20   test 3 is 30

student 2 data is: test 1 is 1   test 2 is 2   test 3 is 3

student 3 data is: test 1 is 11   test 2 is 22   test 3 is 33

student 2 does not have a higher test 1 score
Press any key to continue
*/