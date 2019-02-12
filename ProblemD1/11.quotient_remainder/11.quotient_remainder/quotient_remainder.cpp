#include <iostream>
using namespace std;

int main()
{
	int testCase, a, b;

	cin >> testCase;
	int** result = new int*[testCase];
	for (int i = 0; i < testCase; i++) {
		result[i] = new int[2];
	}

	for (int i = 0; i < testCase; i++) {
		cin >> a >> b;
		result[i][0] = a / b;
		result[i][1] = a % b;
	}

	for (int i = 0; i < testCase; i++) {
		cout << "#" << i + 1 << " " << result[i][0] << " " << result[i][1] << endl;
	}

	for (int i = 0; i < testCase; i++) {
		delete[] result[i];
	}

	delete[] result;

	return 0;
}