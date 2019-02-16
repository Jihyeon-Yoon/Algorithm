#include <iostream>
using namespace std;

int zigzag(int n);
void show_result(int* arr, int size);

int main()
{
	try {
		int test_case;

		cin >> test_case;

		if (test_case < 1) {
			throw test_case;
		}

		int* result = new int[test_case];

		for (int i = 0; i < test_case; i++) {
			int n;
			cin >> n;
			result[i] = zigzag(n);
		}

		show_result(result, test_case);

		delete[] result;
		result = NULL;
	}
	catch(int exception) {
		cout << exception << " -> it must be a natural number(1~10)." << endl;
	}

	return 0;
}

int zigzag(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			sum -= i;
		}
		else {
			sum += i;
		}
	}
	return sum;
}

void show_result(int* arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << "#" << i + 1 << " " << arr[i] << endl;
	}
}