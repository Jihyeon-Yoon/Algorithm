#include <iostream>
using namespace std;

#define MAX 10

int main()
{
	int testCount=0, num, oddSum = 0, i, j;

	try {
		cin >> testCount;
		if (testCount < 0)
			throw testCount;
		
		int* result = new int[testCount];

		try {
			//��ǲ �ޱ�
			for (i = 0; i < testCount; i++) {
				for (j = 0; j < MAX; j++) {
					cin >> num;
					if (num < 0 || num > 10000) {
						throw num;
					}
					if (num % 2 != 0) {
						oddSum += num;
					}
				}
				result[i] = oddSum;
				oddSum = 0;
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
			//�޸� ����
			delete[] result;
			result = NULL;
		}
	}
	catch(int exception) {
		cout << exception << " -> ��ȿ ������ �ƴմϴ�." << endl;
	}
	
	return 0;
}