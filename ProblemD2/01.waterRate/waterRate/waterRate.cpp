#include <iostream>
using namespace std;

int a_waterRate(int w, int p);
int b_waterRate(int w, int r, int q, int s);
void show_result(int* arr, int size);

int main()
{
	int testCase, p, q, r, s, w, a, b;

	cin >> testCase;

	int* result = new int[testCase];

	for (int i = 0; i < testCase; i++) {
		cin >> p >> q >> r >> s >> w;

		a = a_waterRate(w, p);
		b = b_waterRate(w, r, q, s);

		if (a > b) {
			result[i] = b;
		} 
		else {
			result[i] = a;
		}
	}

	show_result(result, testCase);

	delete[] result;
	result = NULL;

	return 0;
}

int a_waterRate(int w, int p)
{
	return w*p;
}

int b_waterRate(int w, int r, int q, int s)
{
	if (w > r) {
		return q + ((w - r)*s);
	}
	else {
		return q;
	}
}

void show_result(int* arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << "#" << i + 1 << " " << arr[i] << endl;
	}
}