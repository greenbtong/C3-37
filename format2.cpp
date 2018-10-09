#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	float num1 = 234.5673;
	float num2 = 13.9275;
	float num3 = 15.0;

	cout <<"num1 unformatted is: " << num1 << endl;
	cout <<"num2 unformatted is: " << num2 << endl;
	cout <<"num3 unformatted is: " << num3 << endl << endl;

	cout << setprecision(2) << showpoint << fixed;
	cout << "num1 formatted as a money amount is:  $" << num1 << endl;
	cout << "num1 formatted as a money amount is:  $" << num2 << endl;
	cout << "num1 formatted as a money amount is:  $" << num3 << endl << endl;
	return 0;
}

/*
num1 unformatted is: 234.567
num2 unformatted is: 13.9275
num3 unformatted is: 15

num1 formatted as a money amount is:  $234.57
num1 formatted as a money amount is:  $13.93
num1 formatted as a money amount is:  $15.00

Press any key to continue . . .


The setprecision command only needs to be specified once in this program.
The dollar amounts have been rounded.
The showpoint stream manipulator shows output with the decimal point.
The fixed stream manipulator shows output in fixed notation, that is NOT
in exponential notation.
*/