#include<iostream>
#include<iomanip>
using namespace std;

class Person
{
public:
	Person();   // constructor
	void getSales();  // get sales amount from keyboard
	void printSales(); // print the sales array

private:
	float totalSales();  // private utility function
	float sales[5];  // data members can be arrays
};

Person::Person()  // constructor function sets array elements to 0.0
{
	for (int i = 0; i < 5; i++)
		sales[i] = 0.0;
}

void Person::getSales()
{
	for (int i = 1; i < 6; i++)
	{
		cout << "enter amount for month " << i << "   ";
		cin >> sales[i-1];
	}
}

void Person::printSales()
{
	cout << endl;
	cout << setprecision(2) << showpoint << fixed;
	for (int i = 0; i < 5; i++)
		cout << sales[i] << "  ";
		cout <<endl << endl;
	cout << "total sales are " << totalSales() << endl;
}

float Person::totalSales()
{
	float sum = 0.0;
	for (int i = 0; i < 5; i++)
		sum += sales[i];
	return sum;
}

int main()
{
	Person p;
	p.getSales();
	p.printSales();
	return 0;
}
/*
enter amount for month 1   10.22
enter amount for month 2   20.33
enter amount for month 3   30.44
enter amount for month 4   40.55
enter amount for month 5   50.66

10.22  20.33  30.44  40.55  50.66

total sales are 152.20
Press any key to continue . . . */

