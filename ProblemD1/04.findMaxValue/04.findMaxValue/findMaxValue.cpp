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
			//�׽�Ʈ ���̽���ŭ �ݺ�
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

			//��� ���
			for (i = 0; i < testCount; i++) {
				cout << "#" << i + 1 << " " << result[i] << endl;
			}

			//�޸� ����
			delete[] result;
			result = NULL;
		}
		catch (int exception) {
			cout << exception << " -> ��ȿ ������ �ƴմϴ�." << endl;
			delete[] result;
			result = NULL;
		}
	}
	catch (int exception) {
		cout << exception << " -> ��ȿ ������ �ƴմϴ�." << endl;
	}

	return 0;
}