#include<iostream>
using namespace std;

//example of a function template
//works for multiple data types

template <class T>
// or can do: template <typename T>

T max(T one, T two, T three)
{
	T big = one;
	if (two > big)
		big = two;
	if (three > big)
		big = three;
	return big;
}

int main()
{
	int a,b,c;
	cout << "enter three integers ";
	cin >> a >>b >>c;
	cout << "the biggest integer is " << max(a,b,c) << endl << endl;

	char c1,c2,c3;
	cout << "enter three characters ";
	cin >> c1 >> c2 >> c3;
	cout << "the biggest character is " << max(c1,c2,c3) << endl << endl;


	double d1,d2,d3;
	cout << "enter three doubles ";
	cin >> d1 >> d2 >> d3;
	cout << "the biggest double is " << max(d1,d2,d3) << endl << endl;
	
	return 0;
}

/*
enter three integers 2 6 4
the biggest integer is 6

enter three characters f h U
the biggest character is h

enter three doubles 2.3456 1.23435 7.6543
the biggest double is 7.6543
*/
