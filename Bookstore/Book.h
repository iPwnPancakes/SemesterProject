#ifndef H_BOOK
#define H_BOOK

#include "Date.h"
#include <string>
#include <vector>

using namespace std;

class Book {
public:
	int qty;
	double wholesale, retail;
	string isbn, title, author, publisher;
	Date date;
	Book();
	Book(string, string, string, string, string, int, double, double);
	Book(string i, string t, string a, string p, Date d, int q, double w, double r);
	static Book createBook();
	void printInfo();
	string toString();
	static Book toBook(string);

	bool equals(Book book);
	
private:
	static bool isValidBook(vector<string>);
	static vector<string> split(string, char);
};

#endif
