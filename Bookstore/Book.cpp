#include "Book.h"
#include <iostream>
#include <sstream>

int qty;
double wholesale, retail;
string isbn, title, author, publisher;
Date date;

Book::Book() {
	isbn = "0000000000";
	title = "Default";
	author = "Default";
	publisher = "Default";
	date = Date();
	qty = 0;
	wholesale = 0.0;
	retail = 0.0;
}

Book::Book(string i, string t, string a, string p, string d, int q, double w, double r) {
	isbn = i;
	title = t;
	author = a;
	publisher = p;
	date = Date::toDate(d);
	qty = q;
	wholesale = w;
	retail = r;
}

Book::Book(string i, string t, string a, string p, Date d, int q, double w, double r) {
	isbn = i;
	title = t;
	author = a;
	publisher = p;
	date = d;
	qty = q;
	wholesale = w;
	retail = r;
}

Book Book::createBook() {
	string i, t, a, p, d, q, w, r;

	cin.ignore();
	cout << "Enter the ISBN: " << '\n';
	getline(cin, i);
	cout << "Enter the title: " << '\n';
	getline(cin, t);
	cout << "Enter the author: " << '\n';
	getline(cin, a);
	cout << "Enter the publisher: " << '\n';
	getline(cin, p);
	cout << "Enter the date (MM-DD-YYYY): " << '\n';
	getline(cin, d);
	cout << "Enter the quantity: " << '\n';
	getline(cin, q);
	cout << "Enter the wholesale value: " << '\n';
	getline(cin, w);
	cout << "Enter the retail value: " << '\n';
	getline(cin, r);

	Book newBook = Book(i, t, a, p, Date::toDate(d), stoi(q), stod(w), stod(r));
	return newBook;
}

void Book::printInfo() {
	cout << "Serendipity Booksellers Book Information\n";
	cout << "ISBN: " << isbn << '\n'
		<< "Title: " << title << '\n'
		<< "Author: " << author << '\n'
		<< "Publisher: " << publisher << '\n'
		<< "Date Added: " << date.toString() << '\n'
		<< "Quantity-On-Hand: " << qty << '\n'
		<< "Wholesale Cost: " << wholesale << '\n'
		<< "Retail Price: " << retail << "\n\n";
}

string Book::toString() {
	string str = isbn + ',' + title + ',' + author + ',' + publisher + ',' + date.toString() + ',' + to_string(qty) + ',' + to_string(wholesale).erase(to_string(wholesale).find_last_not_of('0') + 1) + ',' + to_string(retail).erase(to_string(retail).find_last_not_of('0') + 1);
	return str;
}

Book Book::toBook(string str) {
	Book book;
	vector<string> tokens = Book::split(str, ','); 
	if (isValidBook(tokens)) {
		book = Book(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], stoi(tokens[5]), stod(tokens[6]), stod(tokens[7]));
	}
	else {
		book = Book();
	}
	return book;
}

bool Book::equals(Book book) {
	if (isbn == book.isbn && title == book.title && author == book.author && publisher == book.publisher && publisher == book.publisher && date.equals(book.date) && qty == book.qty && wholesale == book.wholesale && retail == book.retail) {
		return true;
	}
	return false;
}

bool Book::isValidBook(vector<string> tokens) {
	if (tokens.size() == 8) {
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens[i].empty()) {
				return false;
			}
		}
		return true;
	}
	return false;
}

vector<string> Book::split(string s, char delim) {
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}