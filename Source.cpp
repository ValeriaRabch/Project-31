#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Date {
	int day, month, year;
public:
	Date() {
		day = 0;
		month = 0;
		year = 0;
	}
	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	Date operator + (int number) {
		Date data2;

		int days = day + (month * 30) + (year * 365);
		days += number;

		data2.year = days / 365; days -= year * 365;
		if (days / 30 < 12) {
			data2.month = days / 30; days -= month * 30;
		}
		else {
			for (int i = days / 30; ; i -= 12) {
				if (i < 12) {
					data2.month = i;
					break;
				}
			}
		}
		if (days < 30) {
			data2.day = days;
		}
		else {
			for (int i = days; ; i -= 30) {
				if (i < 30) {
					data2.day = i;
					break;
				}
			}
		}

		return data2;
	}
	int operator - (Date date2) {
		if ((day + (month * 30) + (year * 365)) > (date2.day + (date2.month * 30) + (date2.year * 365))) {
			return (day + (month * 30) + (year * 365)) - (date2.day + (date2.month * 30) + (date2.year * 365));
		}
		else {
			return (date2.day + (date2.month * 30) + (date2.year * 365)) - (day + (month * 30) + (year * 365));
		}
	}
	void Print() {
		cout << "Day " << day << endl;
		cout << "Month " << month << endl;
		cout << "Year " << year << endl;
	}
};

int main() {
	Date a(9, 4, 2024), b(11,9,2024);

	

	return 0;
}