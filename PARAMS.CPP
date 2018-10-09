#include<iostream>
using namespace std;

// prototypes
void swapbyvalue(int, int);
void swapbyptr(int *, int *);
void swapbyref(int &, int &);
void getnames(char *, char *);  // strings are passed by reference only

int main()
{
	int a, b;
	cout <<"enter two numbers ";
	cin >> a >> b;
	cout <<"the two numbers are " <<a <<"\t" <<b << endl;
	swapbyvalue(a,b);
	cout <<"the two numbers after swapbyvalue are " <<a <<"\t" <<b << endl;
	swapbyptr(&a, &b);  // \t is tab
	cout <<"the two numbers after swapbyptr are " <<a <<"\t" <<b << endl;
	swapbyref(a,b);
	cout <<"the two numbers after swapbyref are " <<a <<"\t" <<b << endl << endl;

	char first[10], last[15];
	cout << "before the names are entered the values are " << first << ' ' << last << endl;
	getnames(first, last);
	cout << "after the names are entered the values are " << first << ' ' << last << endl;
	return 0;
}

void swapbyvalue(int x, int y)
{
	int t = x;
	x = y;
	y = t;
}

void swapbyptr(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void swapbyref(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}

void getnames(char *f, char *l)
{
	cin.ignore(10, '\n');  //needed when entering in string or character data
	                       //after entering in numeric data 
	cout << "enter a first name ";
	cin.getline(f, 10);
	cout << "enter a last name ";
	cin.getline(l, 15);
}

/*
enter two numbers 5 10
the two numbers are 5   10
the two numbers after swapbyvalue are 5 10
the two numbers after swapbyptr are 10  5
the two numbers after swapbyref are 5   10

before the names are entered the values are ??D,?   x?@ ê?@
enter a first name Joan Ann
enter a last name Jones
after the names are entered the values are Joan Ann Jones
Press any key to continue . . .
*/