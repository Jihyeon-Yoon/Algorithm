#include <iostream>
using namespace std;

int main()
{
	try {
		int n;

		cin >> n;

		for (int i = n; i >= 0; i--) {
			cout << i << " ";
		}
		cout << endl;
	}
	catch (int exception) {
		cout << exception << " -> it must be a natural number(1~10000)." << endl;
	}
	
	return 0;
}