#include <iostream>
using namespace std;

int main()
{
	int testCount, num1, num2, i;

	try {
		cin >> testCount;
		if (testCount < 0) {
			throw testCount;
		}

		char* result = new char[testCount];

		try {
			//테스트 케이스만큼 시행
			for (i = 0; i < testCount; i++) {
				cin >> num1 >> num2;
				if (num1 < 0 || num1 > 10000) {
					throw num1;
				}
				if (num2 < 0 || num2 > 10000) {
					throw num2;
				}

				//결과 저장
				if (num1 > num2) {
					result[i] = '>';
				}
				else if (num1 < num2) {
					result[i] = '<';
				}
				else {
					result[i] = '=';
				}
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