// same as last program but with different main
// to test pre and postincrements such as
// cout << ++pupil << endl;

#include<iostream>
using namespace std;

class Student
{
	friend ostream &operator<<( ostream&, const Student&);
	friend istream &operator>>( istream&, Student&);

public:
	Student &operator+=(int);    // modify the object
	Student &operator++();		 // preincrement
	Student operator++(int);     // postincrement - dummy int parameter
	                             // specifices postincrement 
private:
	int test1, test2, test3;
	float avg;
};

Student &Student::operator+=(int extraCredit)
{
	test1+= extraCredit;
	test2+= extraCredit;
	test3+= extraCredit;
   	avg = (test1 + test2 + test3) / (float) 3;
	return *this;
}	

Student &Student::operator ++()   // preincrement
{
	test1++;
	test2++;
	test3++;
	avg = (test1 + test2 + test3) / (float) 3;
	return *this;    
}

Student Student::operator ++(int) // postincrement - note dummy
								  // int parameter has no name	
{
	Student temp = *this;
	test1++;
	test2++;
	test3++;
	avg = (test1 + test2 + test3) / (float) 3;
	return temp;  // return non-incremented value
}

// overloaded stream-insertion operator
ostream &operator<<( ostream &output, const Student &one)
{
	output << "test 1 is " << one.test1 << "   ";
	output << "test 2 is " << one.test2 << "   ";
	output << "test 3 is " << one.test3 << endl;
	output << "the average is " << one.avg << endl;
	return output; // enables cascading eg cout << a << b << c;
}

// overloaded stream-extraction operator
istream &operator>>( istream &input, Student &one)
{
	input >> one.test1  >> one.test2 >> one.test3;
	one.avg = (one.test1 + one.test2 + one.test3) / (float) 3;
	return input; // enables cascading eg cin >> a >> b >> c;
}

int main()
{
	Student pupil;
	cout << "enter three test scores ";
	cin >> pupil;
	cout << endl << "the student information is " << endl;
	cout << pupil << endl;
	// test the preincrement
	cout << "after preincrement " << endl;
	cout << ++pupil << endl;
	cout << "the student information is " << endl;
	cout << pupil << endl;
	// test the postincrement
	cout << "after postincrement " << endl;
	cout << pupil++ << endl;
	cout << "the student information is " << endl;
	cout << pupil << endl;
	return 0;
}

/*
enter three test scores 20 40 60

the student information is
test 1 is 20   test 2 is 40   test 3 is 60
the average is 40

after preincrement
test 1 is 21   test 2 is 41   test 3 is 61
the average is 41

the student information is
test 1 is 21   test 2 is 41   test 3 is 61
the average is 41

after postincrement
test 1 is 21   test 2 is 41   test 3 is 61
the average is 41

the student information is
test 1 is 22   test 2 is 42   test 3 is 62
the average is 42

Press any key to continue
*/