#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string str;
	/*ofstream out;
	out.open("test.txt");*/
	ofstream out("test.txt");
	for (int i = 0; i < 6; i++) {
		getline(cin, str);
		out << str << endl;
	}
	out.close();

	ifstream in("test.txt");
	if (in.fail()) {
		cout << "fail to open file" << endl;
		return 0;
	}
	/*while (getline(in, str)) {
		cout << str << endl;
	}*/
	int count, arr[5], i=0;
	/*while (!in.eof()) {
		in >> count;
		cout << count << endl;
		for (int i = 0; i < 5; i++) {
			in >> arr[i];
			cout << arr[i] << " ";
		}
		cout << endl;
	}*/
	for (int i = 0; i < 3; i++) {
		in >> count;
		cout << count << endl;
		for (int j = 0; j < 5; j++) {
			in >> arr[j];
			cout << arr[j] << " ";
		}
		cout << endl;
	}

	in.close();

	return 0;
}