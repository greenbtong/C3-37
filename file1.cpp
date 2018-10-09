#include<iostream>
#include<fstream>  // must include when working with files
using namespace std;

// the file commands are similar to working with cin and cout

int main()
{
	ofstream outfile("c:\\nums.dat", ios::out);
	// can include a path such as "c:\\cppprogs\\nums.dat"
	
	int num;
	cout <<"enter a number and ctrl z to quit ";
	while( cin >> num)
	{
		outfile << num << endl;
		cout << "next number?  ";
	}
	outfile.close();
	cout <<endl  << endl;

	// time to retrieve and print the file

	ifstream infile("c:\\nums.dat", ios::in);
	while ( infile >> num)
		cout << num << "   ";
	cout << endl;
	infile.close();
	return 0;
}

// ios::app    writes to the end of the file (append)
// ios::in     opens the file for input
// ios::out    opens the file for output  
//             file is overwritten if already exists

/*
enter a number and ctrl z to quit 1
next number?  2
next number?  3
next number?  4
next number?  5
next number?  6
next number?  7
next number?  888
next number?  999
next number?  ^Z


1   2   3   4   5   6   7   888   999
Press any key to continue . . .
*/
