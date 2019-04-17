//the unary scope resolution operator ::
//allows access to variables outside of the current scope
//will be used later with objects to call methods in other classes

#include<iostream>
using namespace std;

float num = 2.345;

int main()
{
	int num = 5;

   // can use single quotes for the characters
	cout <<"local value = " << num <<endl;
	cout <<"global value = " <<::num << endl;
	return 0;
}


/*
local value = 5
global value = 2.345
*/
