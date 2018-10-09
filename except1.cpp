// the try block contains code that may generate an error
// generating an error produces an exception
// The try block is followed by one or more catch blocks
// Each catch block specifies the type of error it catches
// If no corresponding catch block is found, when the exception is
// thrown, the program aborts.

#include<iostream>
#include<iomanip>
using namespace std;

class DivByZeroException
{
public:
	DivByZeroException()
		: message (" attempt to divide by zero ") {}
	const char *print() const {return message;}
// the constructor points message at the string 
// "attempt to divide by zero"

private:
	const char *message;
};

float divide( float a, float b)
{
	if (b == 0)
		throw DivByZeroException();
	return a / b;
}

int main()
{
	float num1, num2, answer;
	cout << "enter two floats, ctrl z to quit ";
	while ( cin >> num1 >> num2)
	{

		// the try block surrounds the area of code that may throw an exception
		// and the code that should not execute if the exception occurs

		try
		{
			answer = divide(num1, num2);
			cout << "the numbers are " << setw(10) << num1 << setw(10) << num2 << endl;
			cout << "the quotient is " << answer << endl << endl;
		}

		// the exception handler:
		catch ( DivByZeroException goof)
		{
			cout << endl << "An exception has occurred: " << goof.print() << endl<< endl;
		}
	cout << "enter two floats, ctrl z to quit ";
	}
	return 0;
}

/*
enter two floats, ctrl z to quit 24.24 35.35
the numbers are      24.24     35.35
the quotient is 0.685714

enter two floats, ctrl z to quit 0 6.6
the numbers are          0       6.6
the quotient is 0

enter two floats, ctrl z to quit 7.7 0

An exception has occurred:  attempt to divide by zero

enter two floats, ctrl z to quit 24.8 12.3
the numbers are       24.8      12.3
the quotient is 2.01626

enter two floats, ctrl z to quit ^Z
Press any key to continue . . .
*/