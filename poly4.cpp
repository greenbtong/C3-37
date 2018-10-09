#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Employee
{
public:
	Employee( const char *, const char *);  // constructor
	~Employee();  // destructor reclaims memory
	virtual float calcPay() const = 0; // pure virtual 
									//to make abstract base class
	virtual void print() const;

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
}

void Employee::print() const
{
	cout << firstName << ' ' << lastName;
}

Employee::~Employee()
{
	delete[] firstName;
	delete[] lastName;
}

class Hourly: public Employee  //  Hourly class derived from Employee class 
{
public:
	Hourly(const char*, const char*, float = 0.0, float=0.0);
	virtual float calcPay() const; 
	virtual void print() const;

private:
	float wage;
	float hours;
};

Hourly::Hourly (const char *first, const char *last, 
				float initHours, float initWage)
				: Employee(first, last)  // call base-class constructor
{
	hours = initHours;
	wage = initWage;
}

float Hourly::calcPay() const 
{ 
	if (hours <=40)
		return wage * hours;
	else
		return 40 * wage + (hours - 40) * wage * 1.5; // overtime
 }

void Hourly::print() const
{
	cout << "Hourly worker: " ;
	Employee::print();  // call the base-class print function
}

class Crook: public Employee  //  Crook class derived from Employee class 
{
public:
	Crook(const char*, const char*, float p, float b, int n, float v);
	virtual float calcPay() const; 
	virtual void print() const;

private:
	float pickPocket;  // amount of money for pickpocketing
	float bribe;   // amount of money for each bribe
	int numBribes;    // number of bribes
	float vendMachine;  // amount of money for breaking into vending machines
};

Crook::Crook (const char *first, const char *last, 
				float p, float b, int n, float v)
				: Employee(first, last)  // call base-class constructor
{
	pickPocket = p;
	bribe = b;
	numBribes = n;
	vendMachine = v;
}

float Crook::calcPay() const 
{ 
	return pickPocket + (bribe * numBribes) + vendMachine;
 }

void Crook::print() const
{
	cout << "Crook: " ;
	Employee::print();  // call the base-class print function
}

class Sales: public Employee  //  Sales class derived from Employee class 
{
public:
	Sales(const char*, const char*, float s, float u, int q);
	virtual float calcPay() const; 
	virtual void print() const;

private:
	float salary;
	float unitpay;   // pay for each item sold
	int quantity;    // number sold
};

Sales::Sales (const char *first, const char *last, 
				float s, float u, int q)
				: Employee(first, last)  // call base-class constructor
{
	salary = s;
	unitpay = u;
	quantity = q;
}

float Sales::calcPay() const 
{ 
	return salary + unitpay * quantity;
 }

void Sales::print() const
{
	cout << "Sales worker: " ;
	Employee::print();  // call the base-class print function
}

int main()
{
	cout << fixed << showpoint << setprecision(2);
	
	// static binding (static means the object type cannot change)
	// the type is determined at compile time for static binding
	// that is h below can only be Hourly
	Hourly h ("Joe", "Smith",  10.5, 20.0); // 10.5 hours at $20 per hour
	h.print();
	cout << " earned $" << h.calcPay() << endl;
	// second way to call the functions using dynamic binding
	// the pointer can point to different object types
	// the type is determined during execution time for dynamic binding
	Employee* ptr;
	ptr = new Hourly("Joe", "Smith", 10.5, 20.0);
	ptr->print();
	cout << " earned $" << ptr->calcPay() << endl << endl;

	Sales s ("Mary", "Jones", 2000.0, 10.0, 50);  // $2000 salary
												// sells 50 units at $10 each	
	// static binding
	s.print();
	cout << " earned $" << s.calcPay() << endl;
	// dynamic binding
	ptr = new Sales("Mary", "Jones", 2000.0, 10.0, 50);
	ptr->print();
	cout << " earned $" << ptr->calcPay() << endl << endl;

	// static binding
	Crook c ("Bill", "Johnson", 100.0, 500.0, 10, 250.0);	
	// $100 pickpocket, 10 bribes at $500, stole $250 from vending machines
	c.print();
	cout << " earned $" << c.calcPay() << endl;
	// dynamic binding
	ptr = new Crook("Bill", "Johnson", 100.0, 500.0, 10, 250.0);
	ptr->print();
	cout << " earned $" << ptr->calcPay() << endl << endl;

	return 0;
}

/*
Hourly worker: Joe Smith earned $210.00
Hourly worker: Joe Smith earned $210.00

Sales worker: Mary Jones earned $2500.00
Sales worker: Mary Jones earned $2500.00

Crook: Bill Johnson earned $5350.00
Crook: Bill Johnson earned $5350.00

Press any key to continue . . .
*/


