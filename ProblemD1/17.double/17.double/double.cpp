#include <iostream>
using namespace std;

int main()
{
	try {
		int n, value=1;

		cin >> n;
		if (n < 1 || n>30) {
			throw n;
		}

		cout << value << " ";
		for (int i = 0; i < n; i++) {
			value *= 2;
			cout << value << " ";
		}
		cout << endl;
	}
	catch (int exception) {
		cout << exception << " -> it must be a natural number(1~30)." << endl;
	}

	return 0;
}