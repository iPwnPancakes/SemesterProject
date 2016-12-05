#include "Inventory.h"
#include "Report.h"
#include "Cashier.h"
#include <iostream>

#include "BookList.h"

using namespace std;

void printMenu();

Inventory inv = Inventory();
Report rep = Report();
Cashier cash = Cashier();

int main() {
	BookList::readFromFile();
	int input;
	do {
		printMenu();
		cin >> input;
		cout << '\n';
		switch (input) {
			case 1: cash.act(); break;
			case 2: inv.act(); break;
			case 3: rep.act(); break;
			case 4: BookList::writeToFile(); break;
			default: cout << "Please enter a valid value!\n"; break;
		}
	} while (input != 4);
	cout << "Goodbye!\n";
	system("pause");
	return 0;
}

void printMenu() {
	cout << "Serendipity Booksellers" << '\n' << "Main Menu" << '\n';
	cout << "1. Cashier Module\n" << "2. Inventory Database Module\n" << "3. Report Module\n" << "4. Exit\n";
	cout << "Enter your choice: \n";
}