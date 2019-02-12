#include <iostream>
using namespace std;
#define ROW 5
#define COLUMN 5

int main()
{
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			if (i == j) {
				cout << "#";
			}
			else {
				cout << "+";
			}
		}
		cout << endl;
	}

	return 0;
}