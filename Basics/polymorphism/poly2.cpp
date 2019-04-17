#include<iostream>
using namespace std;

// same as poly1 but left off the word virtual
// when declaring talk in the Mammal class.

class Mammal
{
	public:
		 void talk() const  // the word virtual removed here
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
for a cat ptr:   mammal says hi
for a bird ptr:   mammal says hi
for a cow ptr:   mammal says hi
for a dog ptr:   mammal says hi
for a mammal ptr:   mammal says hi
*/