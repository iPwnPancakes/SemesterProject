#include "BookList.h"
#include <fstream>
#include <iostream>

using namespace std;

string fileName = "Database.txt";

vector<Book> bookList;

BookList::BookList() { }

vector<Book> BookList::getBookList() {
	return bookList;
}

void BookList::setBookList(vector<Book> blist) {
	bookList = blist;
}

void BookList::addBook(Book book) {
	bookList.push_back(book);
}

void BookList::removeBook(Book book) {
	int index = BookList::getAt(book);
	BookList::removeAt(index);
}

bool BookList::deleteBooks(Book book, int q) {
	int index = BookList::getAt(book);
	if (bookList[index].qty - q < 0) {
		cout << "Too many books being bought/subtracted!\n";
		return false;
	}
	else if (bookList[index].qty - q == 0) {
		bookList[index].qty = bookList[index].qty - q;
		BookList::removeAt(index);
		return true;
	}
	else {
		bookList[index].qty = bookList[index].qty - q;
	}
	return true;
}

void BookList::editBook(Book book) {
	int input;
	int index = BookList::getAt(book);
	do {
		cout << "What field would you like to edit?" << '\n';
		cout << " 1. ISBN \n 2. Title \n 3. Author \n 4. Publisher \n 5. Date \n 6. Quantity \n 7. Wholesale cost \n 8. Retail cost \n";
		cin >> input;
	} while (input < 1 || input > 8);
	cin.ignore();
	switch (input) {
	case 1: {
		string ISBN;
		cout << "Enter the new ISBN: \n";
		getline(cin, ISBN);
		book.isbn = ISBN;
		break;
	}
	case 2: {
		string t;
		cout << "Enter the new title: \n";
		getline(cin, t);
		book.title = t;
		break;
	}
	case 3: {
		string a;
		cout << "Enter the new author: \n";
		getline(cin, a);
		book.author = a;
		break;
	}
	case 4: {
		string p;
		cout << "Enter the new publisher: \n";
		getline(cin, p);
		book.publisher = p;
		break;
	}
	case 5: {
		string d;
		cout << "Enter the new date: \n";
		getline(cin, d);
		book.date = Date::toDate(d);
		break;
	}
	case 6: {
		string q;
		cout << "Enter the new quantity: \n";
		getline(cin, q);
		book.qty = stoi(q);
		break;
	}
	case 7: {
		string w;
		cout << "Enter the new wholesale: \n";
		getline(cin, w);
		book.wholesale = stod(w);
		break;
	}
	case 8: {
		string r;
		cout << "Enter the new retail: \n";
		getline(cin, r);
		book.retail = stod(r);
		break;
	}
	}
	cout << '\n';
	BookList::setAt(index, book);
}

Book BookList::searchByISBN(string str) {
	Book foundBook = Book();
	for (int i = 0; i < bookList.size(); i++) {
		if (!bookList[i].isbn.compare(str)) {
			foundBook = bookList[i];
		}
	}
	return foundBook;
}

Book BookList::searchByTitle(string str) {
	Book bookFound = Book();
	for (int i = 0; i < bookList.size(); i++) {
		if (!bookList[i].title.compare(str)) {
			bookFound = bookList[i];
		}
	}
	return bookFound;
}

vector<Book> BookList::searchByAuthor(string str) {
	vector<Book> authorList;
	for (int i = 0; i < bookList.size(); i++) {
		if (!bookList[i].author.compare(str)) {
			authorList.push_back(bookList[i]);
		}
	}
	return authorList;
}

vector<Book> BookList::searchByPublisher(string str) {
	vector<Book> publisherList;
	for (int i = 0; i < bookList.size(); i++) {
		if (!bookList[i].publisher.compare(str)) {
			publisherList.push_back(bookList[i]);
		}
	}
	return publisherList;
}

vector<Book> BookList::searchByDate(string str) {
	vector<Book> dateList;
	for (int i = 0; i < bookList.size(); i++) {
		if (!bookList[i].date.toString().compare(str)) {
			dateList.push_back(bookList[i]);
		}
	}
	return dateList;
}

vector<Book> BookList::orderByQuantity() {
	vector<Book> sort = BookList::getBookList();
	int startScan, minIndex;
	Book minBook;

	for (startScan = 0; startScan < sort.size(); startScan++) {
		minIndex = startScan;
		minBook = sort[startScan];
		for (int i = startScan; i < sort.size(); i++) {
			if (sort[i].qty < sort[startScan].qty) {
				minBook = sort[i];
				minIndex = i;
			}
		}
		sort[minIndex] = sort[startScan];
		sort[startScan] = minBook;
	}
	return sort;
}

vector<Book> BookList::orderByWholesale() {
	vector<Book> sort = BookList::getBookList();
	int startScan, minIndex;
	Book minBook;

	for (startScan = 0; startScan < sort.size(); startScan++) {
		minIndex = startScan;
		minBook = sort[startScan];
		for (int i = startScan; i < sort.size(); i++) {
			if (sort[i].wholesale < sort[startScan].wholesale) {
				minBook = sort[i];
				minIndex = i;
			}
		}
		sort[minIndex] = sort[startScan];
		sort[startScan] = minBook;
	}
	return sort;
}

vector<Book> BookList::orderByAge() {
	vector<Book> sort = BookList::getBookList();
	int startScan, minIndex;
	Book minBook;

	for (startScan = 0; startScan < sort.size(); startScan++) {
		minIndex = startScan;
		minBook = sort[startScan];
		for (int i = startScan; i < sort.size(); i++) {
			if (!(sort[i].date.olderThan(sort[startScan].date))) {
				minBook = sort[i];
				minIndex = i;
			}
		}
		sort[minIndex] = sort[startScan];
		sort[startScan] = minBook;
	}
	return sort;
}

int BookList::getAt(Book b) {
	int index = -1;
	for (int i = 0; i < bookList.size(); i++) {
		if (bookList[i].equals(b)) {
			index = i;
		}
	}
	return index;
}

void BookList::setAt(int index, Book b) {
	if (index < 0 || index > bookList.size() - 1) {
		cout << "INVALID INDEX VALUE. \n";
	}
	else {
		bookList[index] = b;
	}
}

void BookList::removeAt(int index) {
	if (index < 0 || index > bookList.size() - 1) {
		cout << "INVALID INDEX VALUE. \n";
	}
	else {
		bookList.erase(bookList.begin() + index);
	}
}

void BookList::readFromFile() {
	ifstream readFile(fileName);
	string line;
	int lineNum = 0;
	if (readFile.is_open()) {
		while (getline(readFile, line)) {
			lineNum++;
			if (!Book::toBook(line).equals(Book())) {
				bookList.push_back(Book::toBook(line));
			}
			else {
				cout << "Line number " << lineNum << " in the database is invalid!" << "\n\n";
			}
		}
		readFile.close();
	}
	else {
		cout << "Could not locate " << fileName << '\n';
	}
}

void BookList::writeToFile() {
	ofstream writeFile;
	writeFile.open(fileName);
	for (int i = 0; i < bookList.size(); i++) {
		writeFile << bookList[i].toString() << '\n';
	}
	writeFile.close();
}