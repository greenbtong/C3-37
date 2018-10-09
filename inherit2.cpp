#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Employee
{
public:
	Employee( const char *, const char *);  // constructor
	void print() const;
	~Employee();  // destructor

private:
	char *firstName;
	char *lastName;  // dynamically allocated string
};

Employee::Employee( const char *first, const char *last)
{
	firstName = new char[strlen(first) + 1];
	strcpy(firstName, first);
	lastName = new char[strlen(last) + 1];
	strcpy(lastName, last);
	cout << "inside Employee constructor" << endl;
}

void Employee::print() const
{
	cout << firstName << ' ' << lastName;
}

Employee::~Employee()
{
	cout << " inside Employee destructor to kill " << firstName << ' ' << lastName << endl;
	delete[] firstName;
	delete[] lastName;
}

class Worker : public Employee  // Worker is the derived class
								// Employee is the base class
// inheritance is used for an "is a" relationship.  A worker is an employee
// composition is used for a "has a relationship.  A student has a set of test scores

{
public:
	Worker(const char*, const char*, float, float);
	float getPay() const;
	void print() const;
	~Worker();

private:
	float wage;
	float hours;
};

Worker::Worker (const char *first, const char *last, 
				float initHours, float initWage)
				: Employee(first, last)  // call base-class constructor
{
	hours = initHours;
	wage = initWage;
	cout << "inside the Worker constructor" << endl;
}

float Worker::getPay() const { return wage * hours; }

void Worker::print() const
{
	Employee::print();  // call the base-class print function
	cout << " hours worked are " << fixed << showpoint
		 << setprecision(2) << hours << endl;
	cout << " wage is " << wage << endl;
	cout << " pay is "  << getPay() << endl;
}

Worker::~Worker()
{
	cout << " inside the Worker destructor " << endl; 
}

int main()
{
	Worker w("Joe", "Smith", 10.5, 20.0); // 10.5 hours at $20 per hour
	w.print();
	return 0;
}

/*
inside Employee constructor
inside the Worker constructor
Joe Smith hours worked are 10.50
 wage is 20.00
 pay is 210.00
 inside the Worker destructor
 inside Employee destructor to kill Joe Smith
Press any key to continue
*/
