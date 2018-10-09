#include<iostream>
#include<fstream>
using namespace std;

struct Student
{
	char name[20];
	int test1, test2, test3;
	float avg;
};

int main()
{
	Student s[4];
	int i;
	
	// load the array of structures from the keyboard
	for (i = 0; i < 4; i++)
	{
		cout << "enter a full name ";
		cin.getline(s[i].name, 20);
		cout << "enter 3 test scores ";
		cin >> s[i].test1 >> s[i].test2 >> s[i].test3;
		s[i].avg = (s[i].test1 + s[i].test2 + s[i].test3) / (float) 3;
		cin.ignore(20, '\n');
		cout << endl;
	}

	// save the array of structures to a text file
	ofstream outfile("c:\\students.dat", ios::out);
	for (i = 0; i < 4; i++)
	{
		outfile << s[i].name << endl;  //file must be formatted
		outfile << s[i].test1 << ' ' << s[i].test2 << ' '
			    << s[i].test3 << ' ' << s[i].avg << endl;
	}
	outfile.close();

	// retrieve the array of structures from the text file
	ifstream infile("c:\\students.dat", ios::in);
	for (i = 0; i < 4; i++)
	{
		infile.getline(s[i].name, 20);
		infile >> s[i].test1 >> s[i].test2 >> s[i].test3 >> s[i].avg;
		infile.ignore(20, '\n');
	}
	infile.close();

	// print the array of structures after retrieving from the file
	for (i = 0; i < 4; i++)
	{
		cout << s[i].name << endl;
		cout << "the scores are " << s[i].test1 << ' ' << s[i].test2 << ' '
			 << s[i].test3 << endl;
		cout << "the average is " << s[i].avg << endl << endl;
	}
	return 0;
}

/*
enter a full name Joe Johnson
enter 3 test scores 33 55 66

enter a full name Wendy Smith
enter 3 test scores 55 77 88

enter a full name John Jones
enter 3 test scores 27 77 55

enter a full name Joan Brown
enter 3 test scores 82 79 66

Joe Johnson
the scores are 33 55 66
the average is 51.3333

Wendy Smith
the scores are 55 77 88
the average is 73.3333

John Jones
the scores are 27 77 55
the average is 53

Joan Brown
the scores are 82 79 66
the average is 75.6667

Press any key to continue . . .
*/