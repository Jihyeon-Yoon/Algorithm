#include <iostream>
#include <fstream>
using namespace std;

#define TEST_CASE 10
#define INPUT_ROW 100
#define INPUT_COLUMN 100

void get_rowSum(int* max, int matrix[][INPUT_COLUMN]);
void get_columnSum(int* max, int matrix[][INPUT_COLUMN]);
void get_diagonalSum(int* max, int matrix[][INPUT_COLUMN]);
void set_result(int* max, int testCase, int result[]);
void get_result(int result[]);

int main()
{
	int testCase = 0, max;
	int matrix[INPUT_ROW][INPUT_COLUMN];
	int result[TEST_CASE];
	ifstream in("input.txt");

	if (in.fail()) {
		cout << "fail to open file" << endl;
		return 0;
	}

	for (int i = 0; i < TEST_CASE; i++) {
		in >> testCase;
		for (int i = 0; i < INPUT_ROW; i++) {
			for (int j = 0; j < INPUT_COLUMN; j++) {
				in >> matrix[i][j];
			}
		}
		get_rowSum(&max, matrix);
		get_columnSum(&max, matrix);
		get_diagonalSum(&max, matrix);
		set_result(&max, testCase, result);
	}
	
	in.close();
	get_result(result);

	return 0;
}

void get_rowSum(int* max, int matrix[][INPUT_COLUMN])
{
	for (int i = 0; i < INPUT_ROW; i++) {
		int sum = 0;
		for (int j = 0; j < INPUT_COLUMN; j++) {
			sum += matrix[i][j];
		}
		if (i == 0 || (i != 0 && sum>*max)) {
			*max = sum;
		}
	}
}

void get_columnSum(int* max, int matrix[][INPUT_COLUMN])
{
	for (int j = 0; j < INPUT_COLUMN; j++) {
		int sum = 0;
		for (int i = 0; i < INPUT_ROW; i++) {
			sum += matrix[i][j];
		}
		if (sum>*max) {
			*max = sum;
		}
	}
}

void get_diagonalSum(int* max, int matrix[][INPUT_COLUMN])
{
	int sum = 0;

	//오른쪽 대각선 합
	for (int i = 0; i < INPUT_ROW; i++) {
		for (int j = 0; j < INPUT_COLUMN; j++) {
			if (i == j) {
				sum += matrix[i][j];
			}
		}
	}
	if (sum > *max) {
		*max = sum;
	}

	//왼쪽 대각선 합
	sum = 0;
	for (int i = 0; i < INPUT_ROW; i++) {
		for (int j = INPUT_COLUMN - 1; j >= 0; j--) {
			//에러 원인이었음 (식 안써줘서)
			if (i + j == INPUT_ROW - 1) {
				sum += matrix[i][j];
			}
		}
	}
	if (sum > *max) {
		*max = sum;
	}
}

void set_result(int* max, int testCase, int result[])
{
	result[testCase - 1] = *max;
}

void get_result(int result[])
{
	for (int i = 0; i < TEST_CASE; i++) {
		cout << "#" << i + 1 << " " << result[i] << endl;
	}
}