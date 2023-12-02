/* Prologue
 * Name: View Rent Receipts Info Class
 * Description: Creates and modifies tenant's Rent file
 * Contributors: Crischelle Polley
 * Date created: Dec 1 2023
 * Date last modified: Dec 1 2023
*/

/* References:
 * https://stackoverflow.com/questions/1784573/iterator-for-2d-vector
 */

#pragma once
#ifndef VIEW_RENT_RECEIPTS_H
#define VIEW_RENT_RECEIPTS_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class ViewRentReceipts {
	public:
	// Should reference be used here if this is boundary class?
	static void displayRentReceipts(const vector<vector<string>>& rentReceipts)
	{
		cout << left << setw(40) << "Rent Receipts" << endl;
		cout << left << setw(40) << "-------------------------------" << endl;
		
		for(auto i = rentReceipts.begin(); i != rentReceipts.end(); i++) {
			for(auto j = i->begin(); ;) {				
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
