// default arguments program
#include <iostream>
using namespace std;

// program works whether the volume function is inline or not

inline int volume(int length = 1, int width = 1, int height = 1)
	{return length * width * height;}

int main ()
{
	cout << "the volume for no arguments is " << volume() << endl;
	cout << "the volume for length 10 is " << volume(10) << endl;
	cout << "the volume for length 10 and width 5 is " << volume(10,5);
	cout << endl << "the volume for all three parameters is ";
	cout << volume(10,5,2) << endl;
}

// default arguments must be the rightmost arguments in the
// parameter list

// inline functions advise compiler to generate a copy of the function's
// code.  Therefore, there is no function call.  Used for small functions.
// Reduces the function call overhead.

/*
the volume for no arguments is 1
the volume for length 10 is 10
the volume for length 10 and width 5 is 50
the volume for all three parameters is 100
*/
