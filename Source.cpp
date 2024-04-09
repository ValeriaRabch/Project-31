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
	int& SetGetDay() { return day; }
	int& SetGetMonth() { return month; }
	int& SetGetYear() { return year; }

	void Print() {
		cout << "Day " << day << endl;
		cout << "Month " << month << endl;
		cout << "Year " << year << endl;
	}
};

int main() {
	Date a, b;
	int enter;

	cout << "Enter day "; cin >> enter; a.SetGetDay() = enter;
	cout << "Enter month "; cin >> enter; a.SetGetMonth() = enter;
	cout << "Enter year "; cin >> enter; a.SetGetYear() = enter;

	cout << "Enter number "; cin >> enter;
	b = a + enter;
	cout << a.SetGetDay() << '.' << a.SetGetMonth() << '.' << a.SetGetYear() << '+' << enter << '=' << b.SetGetDay() << '.' << b.SetGetMonth() << '.' << b.SetGetYear() << endl;

	cout << "Enter day "; cin >> enter; b.SetGetDay() = enter;
	cout << "Enter month "; cin >> enter; b.SetGetMonth() = enter;
	cout << "Enter year "; cin >> enter; b.SetGetYear() = enter;

	int c = a - b;

	cout << a.SetGetDay() << '.' << a.SetGetMonth() << '.' << a.SetGetYear() << '-' << b.SetGetDay() << '.' << b.SetGetMonth() << '.' << b.SetGetYear() << '=' << c << endl;

	return 0;
}