#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

// a small String library of overloaded operators

class String
{
	friend ostream &operator<<(ostream &, const String &);
	friend istream &operator>>(istream &, String &);

public:
	const String &operator=( const String &);  // assignment operator
	int getLength() const;
	String( const char * = "");
	~String();      // destructor
	bool operator!() const;  // check for an empty string
	bool operator==(const String &) const;  // check if two string are equal

private:
	int length;
	char *ptr;   // pointer to start of string

	void setString( const char *);
};

String::~String()
{
	cout << "destructor for " << ptr <<endl;
	delete[] ptr;
}

ostream &operator<<( ostream &output, const String &s)
{
	output << s.ptr;
	return output;
}

istream &operator>>( istream &input, String &s)
{
	char temp[50];
	input>> setw(50) >> temp;
	s = temp;  // use assignment operator
	return input;
}

int String::getLength() const {return length;}

// conversion constructor to convert char * to String
String::String( const char *s): length(strlen(s))  
{
	setString(s);
}

const String &String::operator=(const String &right)
{
	if (&right != this)    // check for self assignment
	{
		delete[] ptr;
		length = right.length;
		setString(right.ptr);  // call utility function
	}
	return *this;
}

void String::setString( const char *string2)
{
	ptr = new char[length + 1];
	strcpy(ptr, string2);
}

bool String::operator!() const { return length ==0; }

bool String::operator==(const String &right ) const
{
	return strcmp(ptr, right.ptr) == 0; 
}

int main()
{
	String one("dork");
	cout << one << endl;
	
	String two;
	// test to see if string two is empty
	if(!two)
		cout << "string two is empty for now" << endl;
	else
		cout << "string two is not empty" << endl;
	two = one;
	cout << "the second string is " << two << endl;
	// test again to see if string two is empty
	if(!two)
		cout << "string two is empty for now" << endl;
	else
		cout << "string two is not empty" << endl;
	// check to see if the two string are equal
	if (one == two)
		cout << "the two strings are the same"<< endl;
	else
		cout << "the two strings are not equal"<< endl;
	// test the assignment operator
	two = "geek";
	cout << two<< endl;
	return 0;
}

/*
dork
string two is empty for now
the second string is dork
string two is not empty
the two strings are the same
destructor for geek
geek
destructor for geek
destructor for dork
Press any key to continue
*/

