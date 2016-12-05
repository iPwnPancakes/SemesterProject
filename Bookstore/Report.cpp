#include "Report.h"
#include <iostream>
#include <algorithm>

using namespace std;

Report::Report() { };

void Report::act() {
	vector<Book> list = BookList::getBookList();

	int choice;
	do {
		Report::printMenu();
		cin >> choice;
		cout << '\n';
		switch (choice) {
			case 1: { // View inventory info
				for (int i = 0; i < list.size(); i++) {
					list[i].printInfo();
				}
				break;
			}
			case 2: { // View wholesale of inventory
				double total = 0;
				for (int i = 0; i < list.size(); i++) {
					total += list[i].wholesale;
					list[i].printInfo();
				}
				cout << "Total Wholesale: " << total << "\n\n";
				break;
			}
			case 3: { // View retail of inventory
				double total = 0;
				for (int i = 0; i < list.size(); i++) {
					total += list[i].retail;
					list[i].printInfo();
				}
				cout << "Total Retail: " << total << "\n\n";
				break;
			}
			case 4: {
				vector<Book> qtyList = BookList::orderByQuantity();
				reverse(qtyList.begin(), qtyList.end());
				for (int i = 0; i < qtyList.size(); i++) {
					qtyList[i].printInfo();
				}
				break;
			}
			case 5: {
				vector<Book> costList = BookList::orderByWholesale();
				reverse(costList.begin(), costList.end());
				for (int i = 0; i < costList.size(); i++) {
					costList[i].printInfo();
				}
				break;
			}
			case 6: {
				vector<Book> ageList = BookList::orderByAge();
				reverse(ageList.begin(), ageList.end());
				for (int i = 0; i < ageList.size(); i++) {
					ageList[i].printInfo();
				}
				break;
			}
			case 7: break;
			default: { "Please enter a valid value\n"; break; }
			cout << '\n';
		}
	} while (choice != 7);
}

void Report::printMenu() {	
	cout << "Serendipity Booksellers " << "Reports Menu\n";
	cout << "1. Inventory Listing\n" << "2. Inventory Wholesale Value\n" << "3. Inventory Retail Value\n"
		 << "4. Listing by Quantity\n" << "5. Listing by Cost\n" << "6. Listing by Age\n" 
		 << "7. Return to Main Menu\n";
	cout << "Enter Your Choice: \n";
}