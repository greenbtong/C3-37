#include<iostream>
using namespace std;

//when using function pointers, all functions must have the
//same signature

void one(int);
void two(int);
void three(int);
void four(int);

int main()
{
	void (*f)(int);
	int choice;

	cout<< "enter a number from 1 to 4, 5 to quit ";
	cin>>choice;

	while (choice >=1 && choice < 5)
	{
		switch(choice)
		{
			case 1: f = one; break;
			case 2: f = two; break;
			case 3: f = three; break;
			default: f = four; break;
		 }

		 f (choice);
		 cout<< "enter a number from 1 to 4, 5 to quit ";
		 cin>>choice;
	}

	cout<<"program is done" <<endl;
	return 0;
}

void one(int a)
{
	cout << "you entered  " << a <<" and you are in function one" <<endl;
}

void two(int a)
{
	cout << "you entered  " << a <<" and you are in function two" <<endl;
}

void three(int a)
{
	cout << "you entered  " << a <<" and you are in function three" <<endl;
}

void four(int a)
{
	cout << "you entered  " << a <<" and you are in function four" <<endl;
}

/*
enter a number from 1 to 4, 5 to quit 1
you entered  1 and you are in function one
enter a number from 1 to 4, 5 to quit 2
you entered  2 and you are in function two
enter a number from 1 to 4, 5 to quit 3
you entered  3 and you are in function three
enter a number from 1 to 4, 5 to quit 4
you entered  4 and you are in function four
enter a number from 1 to 4, 5 to quit 5
program is done
*/
