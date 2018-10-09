#include<iostream>
using namespace std;

// overloaded operators are used to make the main section
// more consistent and easier to write
// eg easier to write cout << pupil; than pupil.printData();

class Student
{
	friend ostream &operator<<( ostream&, Student&);
	friend istream &operator>>( istream&, Student&);
	
private:
	int test1, test2, test3;
	float avg;
};

// overloaded stream-insertion operator
ostream &operator<<( ostream &output, Student &one)
{
	output << "test 1 is " << one.test1 << endl;
	output << "test 2 is " << one.test2 << endl;
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
	return 0;
}

/*
enter three test scores 10 50 20

the student information is
test 1 is 10
test 2 is 50
test 3 is 20
the average is 26.6667

Press any key to continue
*/
