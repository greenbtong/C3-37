#include<iostream>
using namespace std;

// a class is the programming code for an object
// this class only contains data members
// data member access specifiers include:
// public: the data member can be accessed anywhere
// private: the data member can only be accessed in the class code
// protected: will do later for inheritance of objects

class Student
{
	public:
		char name[20];
		int test1, test2, test3;
		float avg;
};

int main()
{
	Student s;  //instantiates an object
	// if the data members were private, they could not be
	// accessed in the main
	cout << "enter the name ";
	cin.getline(s.name, 20);
	cout << "enter the three test scores ";
	cin >> s.test1 >> s.test2 >> s.test3;
	s.avg = (s.test1 + s.test2 + s.test3) / (float) 3;
	cout << endl << s.name << endl;
	cout << s.test1 << '\t' << s.test2 << '\t' << s.test3 << '\t' 
		 << s.avg << endl;
   return 0;
}
 
/*
enter the name Joe Brown
enter the three test scores 23 35 25

Joe Brown
23      35      25      27.6667
Press any key to continue . . .

*/
