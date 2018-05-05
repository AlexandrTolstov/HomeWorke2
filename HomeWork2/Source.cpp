#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;


#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

class time_ {
private:
	int hours, minutes, seconds;
public:
	time_(int a = 0, int b = 0, int c = 0) {
		set_hours(a);
		set_minutes(b);
		set_seconds(c);
	}

	//getters
	int get_hours() { return hours; }
	int get_minutes() { return minutes; }
	int get_seconds() { return seconds; }

	//setters
	void set_hours(int a) {
		if (a > 23 || a < 0) {
			a = 0;
		}
		hours = a;
	}
	void set_minutes(int a)
	{
		if (a > 59 || a < 0) {
			a = 0;
		}
		minutes = a;
	}
	void set_seconds(int a) {
		if (a > 59 || a < 0) {
			a = 0;
		}
		seconds = a;
	}

	void printTime() {
		if (hours < 10)
			cout << "0";
		cout << hours << ":";
		if (minutes < 10)
			cout << "0";
		cout << minutes << ":";
		if (seconds < 10)
			cout << "0";
		cout << seconds << endl;
	}

	void addHours(int a) {
		hours += a;
		hours %= 24;
	}

	void addMinutes(int a) {
		minutes += a;
		addHours(minutes / 60);
		minutes %= 60;
	}

	void addSeconds(int a) {
		seconds += a;
		addMinutes(seconds / 60);
		seconds %= 60;
	}
};

void main() {

	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	time_ T(20, 30, 16);
	T.printTime();

	cout << "Hours + 25" << endl;
	T.addHours(25);
	T.printTime();

	cout << "Minutes + 121" << endl;
	T.addMinutes(121);
	T.printTime();

	cout << "Seconds + 61" << endl;
	T.addSeconds(61);
	T.printTime();
	
	system("pause");
}