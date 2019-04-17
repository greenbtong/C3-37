#include<iostream>   // do not include .h here
using namespace std;   //if not used, must use std:: before all cout and cin statements
                       // eg std::cout << "Enter your age: ";
                       // eg std::cin >> myage; 

// one line comment
// typical style for c++
// can still use /* and */ for multiline comments

// #include<iostream.h>  only works for older C++ compilers


void main()  // must include int here as int is no longer the default
            // type for the newer c++ compilers
{
	cout << "Enter your age: ";
	int myage;
	cin >> myage;

	cout << "Enter your friend's age: ";
	int frage;
	cin >> frage;

	cout << "the two ages are: " << myage << "\t" <<frage <<endl << endl;

	if (myage > frage)
		cout << "You are older \n";  // can still use \n for newline or endl
	else
		if (frage > myage)
			cout << "Your friend is older" << endl;
		else
			cout << "We are the same age" << endl;

	system("PAUSE");
	//return 0;
}

/*
one possible output is:

Enter your age: 25
Enter your friend's age: 35
the two ages are: 25    35

Your friend is older
Press any key to continue . . .


In C++, a variable can be declared anywhere.
For example, in a function to make it local.
You can even declare a variable in a loop which means
it is local to that loop.


<< is the stream insertion operator
>> is the stream extraction operator

In C++, in the cout statements, \n is the same as endl, that is

cout << "We are the same age \n";

is the same as 

cout << "We are the same age" << endl;

*/