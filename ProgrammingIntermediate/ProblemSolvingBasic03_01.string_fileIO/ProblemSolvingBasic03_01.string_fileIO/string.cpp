#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define TEST_CASE 2

void show_result(int* arr);

int main()
{
	int* result = new int[TEST_CASE];
	string testCase, temp;

	for (int i = 0; i < TEST_CASE; i++) {
		getline(cin, testCase);

		getline(cin, temp);
		char* pattern = new char[temp.length()];
		strcpy(pattern, temp.c_str());

		getline(cin, temp);
		char* sentence = new char[temp.length()];
		strcpy(sentence, temp.c_str());

		int patternSize = strlen(pattern);
		int sentenceSize = strlen(sentence);

		char* skipArr = new char[patternSize];
		for (int i = 0; i < patternSize; i++) {
			skipArr[i] = i;
		}

		/*for (int j = patternSize - 1; j < sentenceSize; j++) {
			for (int k = patternSize - 1; k >= 0; k--) {
				if (pattern[k]==sentence[j]) {

				}
			}
		}*/

		int sentencePoint=patternSize-1, patternPoint=patternSize-1, matchCount=0;
		while (sentencePoint < sentenceSize) {
			if (sentence[sentencePoint] == pattern[patternPoint]) {
				sentencePoint--;
				patternPoint--;

			}
			else {

			}
		}


		delete[] pattern;
		pattern = NULL;
		delete[] sentence;
		sentence = NULL;
		delete[] skipArr;
		skipArr = NULL;
	}
	

	//결과 출력
	show_result(result, TEST_CASE);

	delete[] result;
	result = NULL;

	return 0;
}

void show_result(int* arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << "#" << i + 1 << " " << arr[i] << endl;
	}
}