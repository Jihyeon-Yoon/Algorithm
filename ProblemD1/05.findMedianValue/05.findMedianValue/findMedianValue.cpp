#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int scoreCount, i, medianPos;

	try {
		cin >> scoreCount;
		if ((scoreCount%2 == 0) || scoreCount<9 || scoreCount>199) {
			throw scoreCount;
		}

		int* score = new int[scoreCount];
		
		//점수 입력
		for (i = 0; i < scoreCount; i++) {
			cin >> score[i];
		}

		sort(score, score + scoreCount);
		medianPos = scoreCount / 2;

		cout << score[medianPos] << endl;

		delete[] score;
		score = NULL;
	}
	catch (int exception) {
		cout << exception << " -> it must be an odd number(9~199)." << endl;
	}

	return 0;
}