#include <iostream>
#include <cstring>
using namespace std;

#define PRIME_MAX 5

void show_result(int** arr, int size);
void factorize(int n, int** result, int order);

int main()
{
	int test_case;

	cin >> test_case;

	int** result = new int*[test_case];
	for (int i = 0; i < test_case; i++) {
		result[i] = new int[PRIME_MAX];
		//메모리 공간을 0으로 초기화 - #include <cstring>
		memset(result[i], 0, sizeof(int)*PRIME_MAX);
	}

	for (int i = 0; i < test_case; i++) {
		int n;
		cin >> n;
		factorize(n, result, i);
	}

	show_result(result, test_case);

	for (int i = 0; i < test_case; i++) {
		delete[] result[i];
		result[i] = NULL;
	}
	delete[] result;
	result = NULL;

	return 0;
}

void factorize(int n, int** result, int order)
{
	while (n > 0) {
		if (n % 11 == 0) {
			result[order][4]++;
			n /= 11;
		}
		else if (n % 7 == 0) {
			result[order][3]++;
			n /= 7;
		}
		else if (n % 5 == 0) {
			result[order][2]++;
			n /= 5;
		}
		else if (n % 3 == 0) {
			result[order][1]++;
			n /= 3;
		}
		else if (n % 2 == 0) {
			result[order][0]++;
			n /= 2;
		}
		else {
			break;
		}
	}
}

void show_result(int** arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << "#" << i + 1 << " ";
		for (int j = 0; j < PRIME_MAX; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}