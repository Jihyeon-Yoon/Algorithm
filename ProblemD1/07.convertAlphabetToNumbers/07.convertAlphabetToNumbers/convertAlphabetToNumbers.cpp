#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			cout << str[i]-'a'+1 << " ";
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			cout << str[i]-'A'+1 << " ";
		}
	}
	cout << endl;

	return 0;
}