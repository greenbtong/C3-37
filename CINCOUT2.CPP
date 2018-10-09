#include<iostream>
using namespace std;

int main()
{
	const int SIZE = 80;  //constant declaration 
	                      // SIZE cannot change value  
	char line[SIZE];

	cout << "enter a line of text ";
	cin >> line;
	cout << line <<endl;

// on strings, cin reads up to the whitespace only
// joe blow entered but only joe printed out

	cin.ignore(SIZE,'\n');

// cin.ignore will ignore up to SIZE characters or until newline character
// must use cin.ignore in this program to remove blow from the stream 
// before entering the second line of text

	cout << "enter a line of text ";
	cin.getline(line, SIZE);
	cout << line <<endl;

// getline member function reads to the end of the line instead of up to
// the whitespace
// joe blow entered and joe blow printed out
	return 0;
}

/*
enter a line of text joe blow
joe
enter a line of text joe blow
joe blow

Note that the ignore method ignores "blow" from the input stream so when the 
user types in joe blow the second time, the output is correct.
*/

