#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n = 28;
	cout << n << " in hexadecimal is: "
		  << hex << n << endl;
	cout << uppercase << "hex in uppercase is " << n << endl;
	cout << nouppercase << "hex back in lowercase is " << n << endl;
	cout << n << " in octal is: "
		  << oct << n << endl;
	cout << n << " in decimal is: "
		  << dec << n << endl << endl;
	cout << setbase(16) << "hex is " << n << endl;
	cout << uppercase << "hex in uppercase is " << n << endl;
	cout << nouppercase << "hex back in lowercase is " << n << endl;
	cout << setbase(8) << "octal is " << n << endl;
	cout << setbase(10) << "decimal is " << n << endl;
	return 0;
}

/*
 possible values for setbase stream manipulator are
 8, 10, 16 only.
 uppercase and nouppercase stream manipulators only work for numbers

28 in hexadecimal is: 1c
hex in uppercase is 1C
hex back in lowercase is 1c
1c in octal is: 34
34 in decimal is: 28

hex is 1c
hex in uppercase is 1C
hex back in lowercase is 1c
octal is 34
decimal is 28
Press any key to continue . . .

*/