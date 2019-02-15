#include <iostream>
using namespace std;

#define ATTRI 2

void show_result(int** arr, int size);
void set_distance(int* distance, int size);
int get_minDistance(int* distance, int size);
int get_minCount(int* distance, int size, int min);

int main()
{
	int testCase;

	cin >> testCase;

	int** result = new int*[testCase];
	for (int i = 0; i < testCase; i++) {
		result[i] = new int[ATTRI];
	}

	for (int i = 0; i < testCase; i++) {
		int n, min, count=0;
		cin >> n;
		int* distance = new int[n];

		set_distance(distance, n);
		min = get_minDistance(distance, n);
		count = get_minCount(distance, n, min);
	
		result[i][0] = min;
		result[i][1] = count;

		delete[] distance;
		distance = NULL;
	}

	show_result(result, testCase);

	for (int i = 0; i < testCase; i++) {
		delete[] result[i];
		result[i] == NULL;
	}
	delete[] result;
	result = NULL;

	return 0;
}

int get_minCount(int* distance, int size, int min)
{
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (distance[i] == min) {
			count++;
		}
	}

	return count;
}

int get_minDistance(int* distance, int size)
{
	int min;

	for (int i = 0; i < size; i++) {
		if (i == 0 || (distance[i] < min)) {
			min = distance[i];
		}
	}

	return min;
}

void set_distance(int* distance, int size)
{
	for (int i = 0; i < size; i++) {
		cin >> distance[i];
		distance[i] = abs(distance[i] - 0);
	}
}

void show_result(int** arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << "#" << i + 1 << " ";
		for (int j = 0; j < ATTRI; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}