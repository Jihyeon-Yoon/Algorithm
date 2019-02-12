#include <iostream>
using namespace std;

int main()
{
	try {
		int a, b;

		cin >> a >> b;

		if ((a == 1 && b == 3) || (a == 2 && b == 1) || (a == 3 && b == 2)) {
			cout << 'A' << endl;
		}
		else if ((b == 1 && a == 3) || (b == 2 && a == 1) || (b == 3 && a == 2)) {
			cout << 'B' << endl;
		}
	}
	catch (int exception) {
		cout << exception << " --> it must be a natural number(1,2,3)." << endl;
	}

	return 0;
}