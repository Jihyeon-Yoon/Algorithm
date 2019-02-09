#include <iostream>
using namespace std;

int main()
{
	int num, sum=0;

	try {
		cin >> num;
		if (num < 1 || num>9999) {
			throw num;
		}

		while (num > 0) {
			sum += num % 10;
			num = num / 10;
		}

		cout << sum << endl;
	}
	catch (int exception) {
		cout << exception << " -> it must be a natural number(1~9999)." << endl;
	}

	return 0;
}