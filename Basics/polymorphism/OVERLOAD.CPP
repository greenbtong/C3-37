// overloaded functions
// a collection of functions with the same name but different signatures
// or parameter lists.  The appropriate function is automatically called.
// this is an example of polymorphism - "many shapes"

#include <iostream>
using namespace std;

int twice(int x)   { return x + x;}

double twice(double x)  { return x + x;}

int twice (int x, int y)  { return x + y;}

int twice (int x, int y, int z)  { return x + y + z;}

int main()
{
	cout << twice(5) << endl;
	cout << twice(2.5)<< endl;
	cout << twice (10, 20) << endl;
	cout << twice (10, 20, 40) << endl;
   return 0;
}


/*
The output is:

10
5
30
70
*/
