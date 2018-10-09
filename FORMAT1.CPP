#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	char words[11] = "Hello Seth";
	float num = 23.45;

	// setw only applies to each field and must be repeated
	// default justification is right
	cout << "right justified: " << endl;
	cout << setw(15) << words <<endl;
	cout << setw(25) << words <<endl;
	cout << setw(10) << num <<endl;
	cout << setw(25) << num <<endl;
	cout << endl <<endl;

	// to left justify
	cout << "left justified: " << endl;
	cout << setw(15) <<left << words << endl;
	cout << setw(25) <<words <<endl;
	cout << setw(10) << num << endl;
	cout << setw(25) << num <<endl;
	cout << endl << endl;

	// to reset justification
	cout << "justification reset to right: " << endl;
	cout << setw(15) << right << words << endl;
	cout << setw(25) <<words <<endl;
	cout << setw(10) << num << endl;
	cout << setw(25) << num <<endl <<endl;

	return 0;
}

/*
 right justified:
     Hello Seth
               Hello Seth
     23.45
                    23.45


left justified:
Hello Seth
Hello Seth
23.45
23.45


justification reset to right:
     Hello Seth
               Hello Seth
     23.45
                    23.45

Press any key to continue . . . 

*/