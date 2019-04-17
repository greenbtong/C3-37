// same as class2 except that the class is in a header file
// makes the class reusable

#include<iostream>
#include "student.h" 
using namespace std;

int main()
{
	Student one, two;
	cout << "student one data is" << endl;
	one.printData();
	two.setData(10, 15, 30);
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
Press any key to continue . . .
*/
