#include "Date.h"
#include <sstream>
#include <iostream>

int day, month, year;

Date::Date() { day = 0; month = 0; year = 0; }

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

void Date::setDay(int d) { day = d; }

void Date::setMonth(int m) { month = m; }

void Date::setYear(int y) { year = y; }

int Date::getDay() { return day; }

int Date::getMonth() { return month; }

int Date::getYear() { return year; }

string Date::toString() {
	string str = to_string(month) + "-" + to_string(day) + "-" + to_string(year);
	return str;
}

bool Date::equals(Date d) {
	if (day == d.getDay() && month == d.getMonth() && year == d.getYear()) {
		return true;
	}
	return false;
}

bool Date::olderThan(Date d) {
	if (year < d.getYear()) {
		return true;
	}
	else {
		if (month < d.getMonth()) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

Date Date::toDate(string str) {
	Date d = Date();
	vector<string> tokens = Date::split(str, '-');
	d.setMonth(stoi(tokens[0]));
	d.setDay(stoi(tokens[1]));
	d.setYear(stoi(tokens[2]));
	return d;
}

vector<string> Date::split(string s, char delim) {
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}