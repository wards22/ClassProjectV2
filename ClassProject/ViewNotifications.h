/* Prologue
 * Name: View Notifications Info Class
 * Description: Creates and modifies tenant's Rent file
 * Contributors: Crischelle Polley
 * Date created: Dec 1 2023
 * Date last modified: Dec 1 2023
*/


#pragma once
#ifndef VIEW_NOTIFICATIONS_H
#define VIEW_NOTIFICATIONS_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class ViewNotifications {
	public:
	static void displayNotifications()
	{
		cout << left << setw(40) << "Rent Receipts" << endl;
		cout << left << setw(40) << "-------------------------------" << endl;

		for (auto i = rentReceipts.begin(); i != rentReceipts.end(); i++) {
			for (auto j = i->begin(); ;) {
				cout << left << setw(10) << "Date:           " << setw(30) << *j << endl;
				cout << left << setw(10) << "Reference #:    " << setw(30) << *(j + 1) << endl;
				cout << left << setw(10) << "Description:    " << setw(30) << *(j + 2) << endl;
				cout << left << setw(10) << "Amount Due:     " << "$" << setw(29) << *(j + 3) << endl;
				cout << endl;
				break;
			}
			cout << endl;
		}

	}
};

#endif

