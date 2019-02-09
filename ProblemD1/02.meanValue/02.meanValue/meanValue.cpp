#include <iostream>
#include <cmath>
using namespace std;

#define MAX 10

int main()
{
	int testCount = 0, num, sum=0, i, j;

	try {
		cin >> testCount;
		if (testCount < 0) {
			throw testCount;
		}

		//��� ������ �޸� �Ҵ�
		int* result = new int[testCount];

		try {
			//��ǲ �Է� �ޱ�
			for (i = 0; i < testCount; i++) {
				for (j = 0; j < MAX; j++) {
					cin >> num;
					if (num < 0 || num>10000) {
						throw num;
					}
					sum += num;
				}
				result[i] = (int)floor((double)sum / MAX + 0.5);
				sum = 0;
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