#include<iostream>
using namespace std;

class Student {
public:
	friend class Person; // a friend class
	Student()
	{
		test1 = test2 = test3 = big = small = 0;
	};

private:
	int test1, test2, test3, big, small;
	
	int biggest(int t1,int t2,int t3)
	{
		if (t1 >= t2 && t1 >= t3)
			return big = t1;
		if (t2 >= t1 && t2 >= t3)
			return big = t2;
		return big = t3;
	};

	int smallest(int t1 ,int t2,int t3)
	{
		if (t1 <= t2 && t1 <= t3)
			return small = t1;
		if (t2 <= t1 && t2 <= t3)
			return small = t2;
		return small = t3;
	};
};

class Person
{
public:
	Student stock;
	int stock1, stock2, stock3, big, small;

	void getInfo();
	
	Person()
	{
		getInfo();
	};

private:
};

	void Person::getInfo()
	{
		cout << "enter three stock values ";
		cin >> stock1 >> stock2 >> stock3;
		cout << endl << "the three stocks are ";
		cout << stock1 << "  " << stock2 <<"  " << stock3 << endl;
		
		// use the biggest and smallest functions in the Student class
		// to find the biggest and smallest stock values

		big = stock.biggest(stock1, stock2, stock3);
		small = stock.smallest(stock1, stock2, stock3);
		cout << "the biggest value is " << big << endl;
		cout << "the smallest value is " <<small << endl;
	};	
		

int main()
{
	Person one;
	return 0;
}

/*
enter three stock values 25 35 15

the three stocks are 25  35  15
the biggest value is 35
the smallest value is 15
Press any key to continue
*/