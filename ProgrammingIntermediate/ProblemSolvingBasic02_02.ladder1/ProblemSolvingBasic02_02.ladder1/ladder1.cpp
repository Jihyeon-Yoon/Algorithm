#include <iostream>
#include <fstream>
using namespace std;
#define ROW 100
#define COLUMN 100
#define TEST_CASE 10

void show_result(int* arr);

int main()
{
	int testCase, start, r, c, point, preRow, preColumn;
	int matrix[ROW][COLUMN];
	int result[TEST_CASE];

	for (int i = 0; i < TEST_CASE; i++) {
		//값 저장
		cin >> testCase;
		for (r = 0; r < ROW; r++) {
			for (c = 0; c < COLUMN; c++) {
				cin >> matrix[r][c];
			}
		}

		//출발점 찾기
		for (start = 0; start < COLUMN; start++) {
			c = start;
			r = 0;
			point = matrix[r][c];

			if (point == 0) {
				continue;
			}

			preRow = r;
			preColumn = c;

			while (r < ROW - 1) {
				if ((c != COLUMN - 1) && (matrix[r][c + 1] == 1) && ((c + 1 != preColumn))) {
					preRow = r;
					preColumn = c;
					point = matrix[r][++c];
				}
				else if ((c != 0) && (matrix[r][c - 1] == 1) && ((c - 1) != preColumn)) {
					preRow = r;
					preColumn = c;
					point = matrix[r][--c];
				}
				else if ((matrix[r + 1][c] == 1) || (matrix[r + 1][c] == 2)) {
					preRow = r;
					preColumn = c;
					point = matrix[++r][c];
				}
			}

			if (point == 2) {
				result[i] = start;
				break;
			}
		}
	}

	//결과 출력
	show_result(result);

	return 0;
}

void show_result(int* arr)
{
	for (int i = 0; i < TEST_CASE; i++) {
		cout << "#" << i + 1 << " " << arr[i] << endl;
	}
}