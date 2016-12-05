#ifndef H_BOOKLIST
#define H_BOOKLIST

#include <string>
#include <vector>
#include "Book.h"

using namespace std;

class BookList {
public:
	BookList();
	static void setBookList(vector<Book>);
	void addBook(Book book);
	static bool deleteBooks(Book book, int q);
	void editBook(Book book);
	static Book searchByISBN(string str);
	static Book searchByTitle(string str);
	static vector<Book> searchByAuthor(string str);
	static vector<Book> searchByPublisher(string str);
	static vector<Book> searchByDate(string str);
	static vector<Book> orderByQuantity();
	static vector<Book> orderByWholesale();
	static vector<Book> orderByAge();
	static int getAt(Book b);
	void static setAt(int index, Book b);
	void static removeAt(int index);
	static vector<Book> getBookList();
	static void readFromFile();
	static void writeToFile();
};

#endif