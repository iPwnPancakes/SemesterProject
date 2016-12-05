#include "Cashier.h"
#include "BookList.h"
#include <time.h>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void printDate();
void printTransaction(string d, int q, string i, string t, double p);
void collectInfo();

Cashier::Cashier() { }

void Cashier::act() {
	
	while (true) {
		char input;
		collectInfo();
		cout << "Would you like to process another transaction? (Y/N)" << '\n';
		cin >> input;
		if (input == 'n' || input == 'N') {
			break;
		}
	}

	cout << '\n';
}

void printDate() {
	time_t now;

	struct tm * timeinfo;
	time(&now);
	timeinfo = localtime(&now);

	cout << "Date: " << asctime(timeinfo);
}

void printTransaction(string d, int q, string i, string t, double p) {
	cout << "Serendipity Book Sellers\n\n";
	printDate();
	cout << '\n';

	cout << setw(3) << "QTY" << setw(15) << "ISBN" << setw(30) << "TITLE" << setw(13) << "PRICE" << setw(13) << "TOTAL";
	cout << '\n';
	cout << setfill('_') << setw(75) << '\n';
	cout << setfill(' ') << setw(3) << to_string(q);
	cout << setw(15) << i;
	cout << setw(30) << t;
	cout << "      " << '$' << right << setw(6) << setprecision(2) << fixed << p;
	cout << "      " << '$' << right << setw(6) << setprecision(2) << fixed << p * q;
	cout << "\n\n\n";

	cout << setw(52) << "SUBTOTAL:";
	cout << setw(16) << '$';
	cout << setw(6) << setprecision(2) << fixed << p * q << '\n';

	cout << setw(52) << "TAX:";
	cout << setw(16) << '$';
	cout << setw(6) << setprecision(2) << fixed << (p * q) * 0.06 << '\n';

	cout << setw(52) << "TOTAL:";
	cout << setw(16) << '$';
	cout << setw(6) << setprecision(2) << fixed << (p * q) + ((p*q) * 0.6) << '\n';
	cout << '\n';
}

void collectInfo() {
	string d, i, t, q, p;
	int quantity;
	double price;

	cout << "Serendipity Book Sellers Cashier Module\n\n";
	cout << "Please enter the information of the book you would like to purchase:" << '\n';
	cin.ignore();
	cout << "Date: "; getline(cin, d);
	cout << "Quantity: "; getline(cin, q); quantity = stoi(q);
	cout << "ISBN: "; getline(cin, i);
	cout << "Title: "; getline(cin, t);
	cout << "Price: "; getline(cin, p); price = stod(p);
	cout << '\n';
	if (BookList::searchByTitle(t).equals(Book())) {
		cout << "Book was not found!" << '\n';
	}
	else {
		printTransaction(d, quantity, i, t, price);
		if (BookList::deleteBooks(BookList::searchByTitle(t), quantity)) {
			cout << "Transaction processed!" << '\n';
		}
		else {
			cout << "Not enough books!" << '\n';
		}
	}
}