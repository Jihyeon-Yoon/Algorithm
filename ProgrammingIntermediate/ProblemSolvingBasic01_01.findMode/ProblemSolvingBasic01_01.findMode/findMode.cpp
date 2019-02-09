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

		//��� ������ �迭 �Ҵ�
		int* result = new int[testCount];
		//���� �� ������ �迭
		int score[TOTAL_SCORE] = { 0 };

		try {
			//�׽�Ʈ ���̽���ŭ �ݺ�
			for (i = 0; i < testCount; i++) {
				cin >> caseNum;
				//���� ����
				for (j = 0; j < TOTAL_STUDENT; j++) {
					cin >> num;
					if (num < 0 || num>100) {
						throw num;
					}
					score[num]++;
				}
				//�ֺ� ã��
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
				//fill_n(�ʱ�ȭ�� �迭 �̸�, �迭�� �ڸ���, �ʱ�ȭ�� ��)
				fill_n(score, TOTAL_SCORE, 0);
			}

			//��� ���
			for (i = 0; i < testCount; i++) {
				cout << "#" << i + 1 << " " << result[i] << endl;
			}

			//��� �޸� ����
			delete[] result;
			result = NULL;
		}
		catch (int exception) {
			cout << exception << " -> it must be a zero or positive integer(0~100)" << endl;

			//��� �޸� ����
			delete[] result;
			result = NULL;
		}
	}
	catch (int exception) {
		cout << exception << " -> it must be a positive integer" << endl;
	}

	return 0;
}