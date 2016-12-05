#include <iostream>
#include <fstream>
#include <string>
#include "Inventory.h"
#include "BookList.h"

using namespace std;

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
	Book b = Book::createBook();
	cout << '\n';
	BookList::addBook(b);
}

void Inventory::deleteBook() {
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
		BookList::removeBook(bookEditing);
		cout << "Book removed!" << '\n';
	}
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
		BookList::editBook(bookEditing);
		cout << "Book edited!" << '\n';
	}
}

void Inventory::printMenu() {
	cout << "Serendipity Booksellers " << "Inventory Database\n";
	cout << "1. Look Up a Book\n" << "2. Add a Book\n" << "3. Edit a Book's Record\n" 
		 << "4. Delete a Book\n" << "5. Return to Main Menu\n";
	cout << "Enter Your Choice: \n";
}
