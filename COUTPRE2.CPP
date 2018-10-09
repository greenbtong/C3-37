#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	float num1 = 1234.567;
	float num2 = 57.41111;
	for (int i = 2; i <= 7; i++)
		{
			cout << setprecision(i);  // equivalent to cout.precision(i);
			cout <<"cout with precision " << i << " is " << num1 << endl;
			cout <<"cout with precision " << i << " is " << num2 << endl;
			cout << endl;
		}
	return 0;
}

/*
The output is:

cout with precision 2 is 1.2e+003
cout with precision 2 is 57

cout with precision 3 is 1.23e+003
cout with precision 3 is 57.4

cout with precision 4 is 1235
cout with precision 4 is 57.41

cout with precision 5 is 1234.6
cout with precision 5 is 57.411

cout with precision 6 is 1234.57
cout with precision 6 is 57.4111

cout with precision 7 is 1234.567
cout with precision 7 is 57.41111

Press any key to continue . . .

*/

