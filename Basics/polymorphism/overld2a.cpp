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
	pupil+=5;  //assign 5 extra credit points to each test
	cout << endl << "after extra credit the scores are " << endl;
	cout << pupil << endl;
	++pupil;  //add 1 to each test - preincrement
	cout << endl << "after preincrementing the scores are " << endl;
	cout << pupil << endl;
	pupil++;  //add 1 to each test - postincrement
	cout << endl << "after postincrementing the scores are " << endl;
	cout << pupil << endl;
	return 0;
}

/*
enter three test scores 10 30 50

the student information is
test 1 is 10   test 2 is 30   test 3 is 50
the average is 30


after extra credit the scores are
test 1 is 15   test 2 is 35   test 3 is 55
the average is 35


after preincrementing the scores are
test 1 is 16   test 2 is 36   test 3 is 56
the average is 36


after postincrementing the scores are
test 1 is 17   test 2 is 37   test 3 is 57
the average is 37

Press any key to continue
*/