#include <iostream>
using namespace std;
#define TEST_COUNT 10

int main()
{
	int i, j, k, buildingNum, max, view=0;
	int result[TEST_COUNT];

	for (i = 0; i < TEST_COUNT; i++) {
		cin >> buildingNum;
		//building 높이 저장할 배열 할당
		int* building = new int[buildingNum];

		//bilding 높이 저장
		for (j = 0; j < buildingNum; j++) {
			cin >> building[j];
		}

		//조망권 확보된 세대 수 구하기
		for (j = 2; j < buildingNum - 2; j++) {
			//가장 높은 이웃 빌딩 찾기
			for (k = -2; k < 3; k++) {
				if (k == 0) {
					continue;
				}
				if (k == -2) {
					max = building[j + k];
				}
				else {
					if (building[j + k] > max) {
						max = building[j + k];
					}
				}
			}
			if (max < building[j]) {
				view += (building[j] - max);
			}
		}
		result[i] = view;

		view = 0;
		//메모리 해제
		delete[] building;
		building = NULL;
	}

	//결과 출력
	for (i = 0; i < TEST_COUNT; i++) {
		cout << "#" << i + 1 << " " << result[i] << endl;
	}

	return 0;
}