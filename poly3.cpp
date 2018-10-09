#include<iostream>
using namespace std;

// abstract class - define class where programmer will NOT
// instantiate any objects. Also called abstract base class.
// sole purpose - provide base class from which classes may
// inherit interface and/or implementation.

// concrete class - classes from which objects can be instantiated

// A class is made abstract by declaring one or more of its virtual
// functions to be pure.  Set its initializer to 0 to make it pure.

class Mammal
{
	public:
		virtual void talk() const = 0; // pure virtual
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
// cannot assign ptr as a new Mammal as the Mammal class is abstract
// due to the pure virtual function
	return 0;
}

/*
for a cat ptr:   cat says meow
for a bird ptr:   bird says chirp
for a cow ptr:   cow says moo
for a dog ptr:   dog says woof
*/
