#include <iostream>
using namespace std;
#define MAX 10

int main()
{
	int testCount, i, j, num, max;

	try {
		cin >> testCount;
		if (testCount < 0) {
			throw testCount;
		}

		int* result = new int[testCount];

		try {
			//테스트 케이스만큼 반복
			for (i = 0; i < testCount; i++) {
				for (j = 0; j < MAX; j++) {
					cin >> num;
					if (num < 0 || num>10000) {
						throw num;
					}
					if (j == 0) {
						max = num;
					}
					else {
						if (num > max) {
							max = num;
						}
					}
				}
				result[i] = max;
			}

			//결과 출력
			for (i = 0; i < testCount; i++) {
				cout << "#" << i + 1 << " " << result[i] << endl;
			}

			//메모리 해제
			delete[] result;
			result = NULL;
		}
		catch (int exception) {
			cout << exception << " -> 유효 범위가 아닙니다." << endl;
			delete[] result;
			result = NULL;
		}
	}
	catch (int exception) {
		cout << exception << " -> 유효 범위가 아닙니다." << endl;
	}

	return 0;
}