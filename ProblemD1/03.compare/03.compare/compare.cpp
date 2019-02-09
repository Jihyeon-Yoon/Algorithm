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
			//�׽�Ʈ ���̽���ŭ ����
			for (i = 0; i < testCount; i++) {
				cin >> num1 >> num2;
				if (num1 < 0 || num1 > 10000) {
					throw num1;
				}
				if (num2 < 0 || num2 > 10000) {
					throw num2;
				}

				//��� ����
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