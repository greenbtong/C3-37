#include <iostream>
using namespace std;

//function template to print an array
//works for multiple data types

template <class T>
void printarray (T *a, const int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}

int main()
{
	const int n1 = 5, n2 = 7, n3 = 6;
	int a[n1] = {2, 4, 6, 8, 10};
	float b[n2] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	char c[n3] = "HELLO";

	cout <<"the integer array" << endl;
	printarray(a, n1);

	cout <<"the float array" << endl;
	printarray(b,n2);

	cout <<"the string is" << endl;
	printarray(c,n3);
	return 0;
}

/*
the integer array
2  4  6  8  10
the float array
1.1  2.2  3.3  4.4  5.5  6.6  7.7
the string is
H  E  L  L  O
*/