#include<iostream>
using namespace std;

// inline functions reduce function call overhead
// compiler generates a copy of the function code in place where called
// used for small, frequently used functions

// can put const in parameter list to state parameter does not change

inline double cube(const double s) {return s * s * s;}

int main()
{
  cout <<"enter the side length of a cube: ";
  double side;
  cin >> side;
  cout << "volume of cube with side " <<side << " is " << cube(side) <<endl;

  return 0;
}

/*
enter the side length of a cube: 3
volume of cube with side 3 is 27
*/

