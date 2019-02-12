#include <iostream>
using namespace std;

int main()
{
	try {
		int a, b;

		cin >> a >> b;
		if (a < 1 || a>9) {
			throw a;
		}
		if (b < 1 || b>9) {
			throw b;
		}
		cout << a + b << endl;
		cout << a - b << endl;
		cout << a * b << endl;
		cout << a / b << endl;

	}
	catch (int exception) {
		cout << exception << " --> it must be a natural number(1~9)." << endl;
	}

	return 0;
}