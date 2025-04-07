#include <iostream>
#include "Number.h"

using namespace std;

int main() {

	Number n1("1010", 2);
	Number n2("A", 16);
	Number n3("100", 10);

	cout << "Initial Values:\n";
	n1.Print();
	n2.Print();
	n3.Print();

	Number sum = n1 + n2;
	cout << "Sum (n1 + n2): ";
	sum.Print();

	Number diff = n2 - n1;
	cout << "Difference (n2 - n1): ";
	diff.Print();

	cout << "n1 > n2: " << (n1 > n2 ? "True" : "False") << endl;
	cout << "n1 < n2: " << (n1 < n2 ? "True" : "False") << endl;
	cout << "n1 >= n2: " << (n1 >= n2 ? "True" : "False") << endl;
	cout << "n1 <= n2: " << (n1 <= n2 ? "True" : "False") << endl;
	cout << "n1 == n2: " << (n1 == n2 ? "True" : "False") << endl;

	cout << "First digit of n1 (n1[0]): " << n1[0] << endl;

	cout << "Switching n3 base to 2:\n";
	n3.SwitchBase(2);
	n3.Print();

	cout << "Pre-decrementing n1:\n";
	--n1;
	n1.Print();

	cout << "Post-decrementing n2:\n";
	n2--;
	n2.Print();

	cout << "Digit count of n1: " << n1.GetDigitCount() << endl;

	cout << "Base of n2: " << n2.GetBase() << endl;

	return 0;
}
