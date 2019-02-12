#include <iostream>
using namespace std;

int main()
{
	int p, k, count=0;

	cin >> p >> k;

	if (p < k) {
		cout << "cant' find password" << endl;
		return 0;
	}

	for (int i = k; k <= p; k++) {
		count++;
		if (k == p) {
			cout << count << endl;
			break;
		}
	}

	return 0;
}