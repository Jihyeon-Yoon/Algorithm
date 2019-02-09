#include <iostream>
using namespace std;
#define TOTAL_SCORE 101
#define TOTAL_STUDENT 1000

int main()
{
	int testCount, caseNum, num, i, j, max, mode;

	try {
		cin >> testCount;
		if (testCount < 0) {
			throw testCount;
		}

		//결과 저장할 배열 할당
		int* result = new int[testCount];
		//점수 빈도 저장할 배열
		int score[TOTAL_SCORE] = { 0 };

		try {
			//테스트 케이스만큼 반복
			for (i = 0; i < testCount; i++) {
				cin >> caseNum;
				//점수 저장
				for (j = 0; j < TOTAL_STUDENT; j++) {
					cin >> num;
					if (num < 0 || num>100) {
						throw num;
					}
					score[num]++;
				}
				//최빈값 찾기
				for (j = 0; j < TOTAL_SCORE; j++) {
					if (j == 0) {
						max = score[j];
						mode = j;
					}
					else {
						if (score[j] >= max) {
							max = score[j];
							mode = j;
						}
					}
				}
				result[caseNum - 1] = mode;
				//fill_n(초기화할 배열 이름, 배열의 자리수, 초기화할 값)
				fill_n(score, TOTAL_SCORE, 0);
			}

			//결과 출력
			for (i = 0; i < testCount; i++) {
				cout << "#" << i + 1 << " " << result[i] << endl;
			}

			//결과 메모리 해제
			delete[] result;
			result = NULL;
		}
		catch (int exception) {
			cout << exception << " -> it must be a zero or positive integer(0~100)" << endl;

			//결과 메모리 해제
			delete[] result;
			result = NULL;
		}
	}
	catch (int exception) {
		cout << exception << " -> it must be a positive integer" << endl;
	}

	return 0;
}