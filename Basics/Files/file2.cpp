#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream outfile("c:\\people.dat", ios::out);
	
	char name[30];

	cout <<"enter a name and ctrl z to quit  ";
	while( cin.getline(name,30))
	{
		outfile << name << endl;
		// the file must be formatted so the file can be retrieved
		// that is, add the whitespace, eg spaces and end lines
		cout << "next name  ";
	}
	outfile.close();
	cout <<endl  << endl;

	// time to retrieve and print the file
	// getline is needed to retrieve strings with whitespace
	// can also do infile.ignore(30, '\n') for entering
	// strings or characters from a file after numbers have been read in

	ifstream infile("c:\\people.dat", ios::in);
	while (infile.getline(name, 30))
		cout << name << endl;
	cout << endl;
	infile.close();
	return 0;
}
/*
enter a name and ctrl z to quit  jim brown
next name  wendy jones
next name  john smith
next name  mary johnson
next name  ^Z


jim brown
wendy jones
john smith
mary johnson

Press any key to continue . . .
*/

// can also do while (!infile.eof()) to check for end of file