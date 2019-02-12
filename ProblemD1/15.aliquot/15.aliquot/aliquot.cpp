#include <iostream>
using namespace std;

int main()
{
	try {
		int n;

		cin >> n;
		if (n < 1 || n>1000) {
			throw n;
		}

		for (int i = 1; i <= n; i++) {
			if (n%i == 0) {
				cout << i << " ";
			}
		}
		cout << endl;

	}
	catch (int exception) {
		cout << exception << " -> it must be a natural number(1~1000)." << endl;
	}

	return 0;
}