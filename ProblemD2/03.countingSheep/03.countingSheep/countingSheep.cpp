#include <iostream>
using namespace std;

int get_count(int n);
void show_result(int* arr, int size);
bool is_full(int* num, int size);

int main()
{
	int testCase;

	cin >> testCase;

	int* result = new int[testCase];

	for (int i = 0; i < testCase; i++)
	{
		int n;
		cin >> n;

		result[i] = get_count(n);
	}

	show_result(result, testCase);

	delete[] result;
	result = NULL;

	return 0;
}

int get_count(int n)
{
	int num[10] = { 0 };
	int multi=0, multiple, count;

	do {
		multi++;
		multiple = n*multi;
		count = multiple;
		while (multiple > 0) {
			num[multiple % 10]++;
			multiple /= 10;
		}
	} while (!is_full(num, 10));

	return count;
}

void show_result(int* arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << "#" << i + 1 << " " << arr[i] << endl;
	}
}

bool is_full(int* num, int size)
{
	for (int i = 0; i < size; i++) {
		if (num[i] == 0) {
			return false;
		}
	}
	return true;
}