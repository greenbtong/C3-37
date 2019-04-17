#include<iostream>
using namespace std;

// Polymorphism is the ability for objects of different classes
// related by inheritance to respond differently to the same member
// function call.  Polymorphism is implemented through virtual functions
// When a request is made through a base-class pointer, the
// correct function in the appropriate derived-class is called.

class Mammal
{
	public:
		virtual void talk() const
			{
				cout << "mammal says hi" << endl;
			}
};

class Dog : public Mammal
{
	public:
		void talk() const
			{
				cout << "dog says woof" << endl;
			}
};

class Cat : public Mammal
{
	public:
		void talk() const
			{
				cout << "cat says meow" << endl;
			}
};

class Cow : public Mammal
{
	public:
		void talk() const
			{
				cout << "cow says moo" << endl;
			}
};

class Bird : public Mammal
{
	public:
		void talk() const
			{
				cout << "bird says chirp" << endl;
			}
};

int main()
{
	Mammal* ptr;
	ptr = new Cat;
	cout << "for a cat ptr:   ";
	ptr->talk();
	ptr = new Bird;
	cout << "for a bird ptr:   ";
	ptr->talk();
	ptr = new Cow;
	cout << "for a cow ptr:   ";
	ptr->talk();
	ptr = new Dog;
	cout << "for a dog ptr:   ";
	ptr->talk();
	ptr = new Mammal;
	cout << "for a mammal ptr:   ";
	ptr->talk();
	return 0;
}

/*
for a cat ptr:   cat says meow
for a bird ptr:   bird says chirp
for a cow ptr:   cow says moo
for a dog ptr:   dog says woof
for a mammal ptr:   mammal says hi
*/