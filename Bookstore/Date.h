#ifndef H_DATE
#define H_DATE

#include <string>
#include <vector>

using namespace std;

class Date {
public:
	Date();
	Date(int d, int m, int y);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	int getDay();
	int getMonth();
	int getYear();
	string toString();
	bool equals(Date d);
	bool olderThan(Date d);
	static Date toDate(string str);
private:
	int day;
	int month;
	int year;
	static vector<string> split(string s, char delim);
};

#endif