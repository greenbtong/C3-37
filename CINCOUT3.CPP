#include<iostream>
using namespace std;

int main()
{
	char c;
	cout <<"enter a line of text " << endl;
	while (( c = cin.get()) != '\n')
		cout.put(c);
	cout <<endl <<"loop is done" << endl;
	return 0;
 }


// examples of more member functions that work with cin and cout
// cin.get inputs one character
// cout.put print one character
 
/*
enter a line of text
hello world today
hello world today
loop is done
*/
