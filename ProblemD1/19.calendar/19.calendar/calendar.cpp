#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void set_date(string* year, string* month, string* date);
bool is_year(string year);
bool is_month(string month);
bool is_date(string month, string date);
void show_result(string* arr, int size);


int main()
{
	int testCase;
	string year, month, date;

	cin >> testCase;

	string* result = new string[testCase];

	for (int i = 0; i < testCase; i++) {
		set_date(&year, &month, &date);
		if (is_year(year) && is_month(month) && is_date(month, date)) {
			result[i] = year + "/" + month + "/" + date;
		} 
		else {
			result[i] = "-1";
		}
	}

	show_result(result, testCase);

	delete[] result;
	result = NULL;

	return 0;
}

void set_date(string* year, string* month, string* date)
{
	string str;
	cin >> str;
	*year = str.substr(0, 4);
	*month = str.substr(4, 2);
	*date = str.substr(6, 2);
}

bool is_year(string year)
{
	int num = atoi(year.c_str());

	if (num >= 0) {
		return true;
	}
	else {
		return false;
	}
}

bool is_month(string month)
{
	int num = atoi(month.c_str());

	if (num >= 1 && num <= 12) {
		return true;
	}
	else {
		return false;
	}
}

bool is_date(string month, string date)
{
	int monthInt = atoi(month.c_str());
	int dateInt = atoi(date.c_str());

	switch (monthInt) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (dateInt >= 1 && dateInt <= 31) {
			return true;
		}
		else {
			return false;
		}
	case 2:
		if (dateInt >= 1 && dateInt <= 28) {
			return true;
		}
		else {
			return false;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		if (dateInt >= 1 && dateInt <= 30) {
			return true;
		}
		else {
			return false;
		}
	default:
		return false;
	}
}

void show_result(string* arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << "#" << i + 1 << " " << arr[i] << endl;
	}
	cout << endl;
}