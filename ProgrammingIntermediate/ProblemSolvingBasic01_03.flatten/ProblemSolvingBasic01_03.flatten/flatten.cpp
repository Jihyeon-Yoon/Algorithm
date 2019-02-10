#include <iostream>
using namespace std;
#define TEST_COUNT 10
#define TOTAL_BOX 100

void set_initBox(int* box);
int dump(int dumpNum, int* box);
void get_max(int* max, int* maxPos, int* box);
void get_min(int* min, int* minPos, int* box);
void move_box(int* box, int maxPos, int minPos);
void show_result(int* result);

int main()
{
	int i, dumpNum;
	int box[TOTAL_BOX], result[TEST_COUNT];

	for (i = 0; i < TEST_COUNT; i++) {
		cin >> dumpNum;
		//입력 값 저장
		set_initBox(box);
		//dump 실행
		result[i]=dump(dumpNum, box);
	}

	//결과 출력
	show_result(result);

	return 0;
}

int dump(int dumpNum, int* box)
{
	int max, maxPos, min, minPos, gap;

	for (int i = 0; i < dumpNum; i++) {
		get_max(&max, &maxPos, box);
		get_min(&min, &minPos, box);
		gap = max - min;
		if (gap <= 1) {
			return gap;
		}
		else {
			move_box(box, maxPos, minPos);
			//gap 한 번 더 구해야하는데 안해서 에러였음
			get_max(&max, &maxPos, box);
			get_min(&min, &minPos, box);
			gap = max - min;
		}
	}

	return gap;
}

void move_box(int* box, int maxPos, int minPos)
{
	box[maxPos]--;
	box[minPos]++;
}

void get_max(int* max, int* maxPos, int* box)
{
	//int arrSize = sizeof(arr) / sizeof(int); - 에러 원인이었음
	for (int i = 0; i < TOTAL_BOX; i++) {
		if (i == 0) {
			*max = box[i];
			*maxPos = i;
		}
		else {
			if (box[i] > *max) {
				*max = box[i];
				*maxPos = i;
			}
		}
	}
}

void get_min(int* min, int* minPos, int* box)
{
	//int arrSize = sizeof(arr) / sizeof(int); - 에러 원인이었음
	for (int i = 0; i < TOTAL_BOX; i++) {
		if (i == 0) {
			*min = box[i];
			*minPos = i;
		}
		else {
			if (box[i] < *min) {
				*min = box[i];
				*minPos = i;
			}
		}
	}
}

void set_initBox(int* box)
{
	for (int i = 0; i < TOTAL_BOX; i++) {
		cin >> box[i];
	}
}

void show_result(int* result)
{
	for (int i = 0; i < TEST_COUNT; i++) {
		cout << "#" << i + 1 << " " << result[i] << endl;
	}
}