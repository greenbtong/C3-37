#include<iostream>
#include<iomanip>
using namespace std;

class Point
{
	friend ostream &operator<<( ostream &, const Point &);

public:
	Point(int = 0, int = 0); // default constructor
	int getx() const { return x;}
	int gety() const { return y;}

protected:
	int x,y;  // accessible by classes that inherit the point class
};

Point::Point(int a, int b) 
{
	x = a;
	y = b;
}

ostream &operator<<( ostream &output, const Point &p)
{
	output << '[' << p.x << ", " << p.y << ']' << endl;
	return output; // enables cascaded calls
}

// stream-extraction operator not overloaded in this program

class Circle : public Point  // circle inherits from point
							 // point is the base class
							 // circle is the derived class
{
	friend ostream &operator<<( ostream &, const Circle &);

public:
	Circle( double r = 0.0, int x = 0, int y = 0);
	double getRadius() const;
	
protected:
	double radius;
};

Circle::Circle(double r, int a, int b)
	:Point(a,b)  // call base class constructor
{
	radius = (r >=0 ? r : 0);
}	


double Circle::getRadius() const { return radius; }

ostream &operator<<(ostream &output, const Circle &c)
{
	output << "the center of the circle is at " << (Point) c;
	output << endl << "the radius is " << setprecision(2);
	output << fixed << showpoint << c.radius << endl;
	// only outputs 15 without the fixed and showpoint
	return output;
}

int main()
{
	Point p1, p2(10,20);
	cout << "first point is " << p1 << endl;
	cout << "second point is " << p2 << endl;
	Circle c1, c2(15.25,20,50);
	cout << "first circle: " << c1 << endl;
	cout << "second circle: " << c2 << endl;
	return 0;
}

/*
first point is [0, 0]

second point is [10, 20]

first circle: the center of the circle is at [0, 0]

the radius is 0.00

second circle: the center of the circle is at [20, 50]

the radius is 15.25

Press any key to continue
*/