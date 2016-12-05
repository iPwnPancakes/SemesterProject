#ifndef H_INVENTORY
#define H_INVENTORY

#include "Book.h"

using namespace std;

class Inventory {
private:
	int lineNumber;
public:
	Inventory();
	void act();
	void lookUpBook();
	void addBook();
	void deleteBook();
	void updateBook();
	void printMenu();
};

#endif