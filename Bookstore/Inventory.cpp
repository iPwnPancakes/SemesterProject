#include <iostream>
#include <fstream>
#include <string>
#include "Inventory.h"
#include "BookList.h"

using namespace std;

void edit(Book);

Inventory::Inventory() { }

void Inventory::act() {
	int input;
	
	do {
		Inventory::printMenu();
		cin >> input;
		switch (input) {
			case 1: lookUpBook(); break;
			case 2: addBook(); break;
			case 3: updateBook(); break;
			case 4: deleteBook(); break;
			case 5: cout << '\n'; break;
			default: cout << "Please enter a valid value: \n";
		}
	} while (input != 5);
}

void Inventory::lookUpBook() {
	Book bookEditing;
	string input;
	cout << "What is the title of the book?" << '\n';
	cin >> input;
	cout << '\n';
	bookEditing = BookList::searchByTitle(input);
	if (bookEditing.equals(Book())) {
		cout << "Book not found!" << '\n' << '\n';
	}
	else {
		bookEditing.printInfo();
	}
}

void Inventory::addBook() {
	vector<Book> v = BookList::getBookList();
	v.push_back(Book::createBook());
	BookList::setBookList(v);
}

void Inventory::deleteBook() {
	Book bookEditing;
	string input;
	cout << "What is the title of the book?" << '\n';
	cin >> input;
	cout << '\n';
	bookEditing = BookList::searchByTitle(input);
	int index = BookList::getAt(bookEditing);
	BookList::removeAt(index);
}

void Inventory::updateBook() {
	Book bookEditing;
	string input;
	cout << "What is the title of the book?" << '\n';
	cin >> input;
	cout << '\n';
	bookEditing = BookList::searchByTitle(input);
	if (bookEditing.equals(Book())) {
		cout << "Book not found!" << '\n';
	}
	else {
		bookEditing.printInfo();
		edit(bookEditing);
	}
}

void Inventory::printMenu() {
	cout << "Serendipity Booksellers " << "Inventory Database\n";
	cout << "1. Look Up a Book\n" << "2. Add a Book\n" << "3. Edit a Book's Record\n" 
		 << "4. Delete a Book\n" << "5. Return to Main Menu\n";
	cout << "Enter Your Choice: \n";
}

void edit(Book bookEditing) {
	int input;
	int index = BookList::getAt(bookEditing);
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
			bookEditing.isbn = ISBN;
			break;
		}
		case 2: {
			string t;
			cout << "Enter the new title: \n";
			getline(cin, t);
			bookEditing.title = t;
			break;
		}
		case 3: {
			string a;
			cout << "Enter the new author: \n";
			getline(cin, a);
			bookEditing.author = a;
			break;
		}
		case 4: {
			string p;
			cout << "Enter the new publisher: \n";
			getline(cin, p);
			bookEditing.publisher = p;
			break;
		}
		case 5: {
			string d;
			cout << "Enter the new date: \n";
			getline(cin, d);
			bookEditing.date = Date::toDate(d);
			break;
		}
		case 6: {
			string q;
			cout << "Enter the new quantity: \n";
			getline(cin, q);
			bookEditing.qty = stoi(q);
			break;
		}
		case 7: {
			string w;
			cout << "Enter the new wholesale: \n";
			getline(cin, w);
			bookEditing.wholesale = stod(w);
			break;
		}
		case 8: {
			string r;
			cout << "Enter the new retail: \n";
			getline(cin, r);
			bookEditing.retail = stod(r);
			break;
		}
	}
	BookList::setAt(index, bookEditing);
}