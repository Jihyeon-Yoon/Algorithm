#include <iostream>
using namespace std;
#define TEST_COUNT 10

int main()
{
	int i, j, k, buildingNum, max, view=0;
	int result[TEST_COUNT];

	for (i = 0; i < TEST_COUNT; i++) {
		cin >> buildingNum;
		//building ���� ������ �迭 �Ҵ�
		int* building = new int[buildingNum];

		//bilding ���� ����
		for (j = 0; j < buildingNum; j++) {
			cin >> building[j];
		}

		//������ Ȯ���� ���� �� ���ϱ�
		for (j = 2; j < buildingNum - 2; j++) {
			//���� ���� �̿� ���� ã��
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
		//�޸� ����
		delete[] building;
		building = NULL;
	}

	//��� ���
	for (i = 0; i < TEST_COUNT; i++) {
		cout << "#" << i + 1 << " " << result[i] << endl;
	}

	return 0;
}