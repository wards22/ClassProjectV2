/* Prologue
 * Name: View Rent Receipts Info Class
 * Description: Creates and modifies tenant's Rent file
 * Contributors: Crischelle Polley
 * Date created: Dec 1 2023
 * Date last modified: Dec 2 2023
*/

/* References:
 * https://stackoverflow.com/questions/1784573/iterator-for-2d-vector
 * https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program
 * https://cplusplus.com/reference/chrono/
 * https://cplusplus.com/reference/thread/thread/
 */

#pragma once
#ifndef VIEW_RENT_RECEIPTS_H
#define VIEW_RENT_RECEIPTS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


class ViewRentReceipts {
	public:
	// Should reference be used here if this is boundary class?
	static void displayTenantRentReceipts(const vector<vector<string>>& rentReceipts)
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

	static void displayAllTenantsRentReceipts() {
       
        fstream inputFile;
        inputFile.open("RentReceipts.csv", ios::in);

        string line, data, record, field;
        vector<string> row;
        vector<vector<string>> rentReceipts;
        int i;          // Keep track of which field is rent receipts

        while (getline(inputFile, line)) {
            row.clear();
            stringstream s(line);

            i = 0;
            while (getline(s, data, ',')) {
                i++;

                if(i == 1) {
                    row.push_back(data);
                    continue;

                } else if(i == 4) {
                    // Skip over staff user IDs
                    if (data == "NULL") {
                        row.clear();
                        break;

                    } else {
                        // Read rent receipts into vector
                        stringstream dat(data);
                        while (getline(dat, record, '&')) {
                            stringstream rec(record);
                            while (getline(rec, field, ';')) {
                                row.push_back(field);
                            }
                        }
                        break;
                    }
                
                } else {
                    continue;
                }

            } 

            if(!row.empty()) 
                rentReceipts.push_back(row);
        }        
        inputFile.close();


        // Display all tenants' rent receipts
        cout << left << setw(40) << "All Tenants Rent Receipts" << endl;
        cout << left << setw(40) << "-------------------------------" << endl;

        int k;          //Keep track of each rent receipt for each tenant
        int n;          // Keep track of how many rent receipts each tenant has
        for(auto i = rentReceipts.begin(); i != rentReceipts.end(); i++) {
           
            k = 0;
            n = 0;
            for(auto j = i->begin(); j != i->end(); j++) {                
                if(k == 0) {
                    cout << left << setw(10) << "UserID:" << setw(30) << *j << endl;
                
                } else if((k % 4) == 1) {
                    // Date
                    n += 1;
                    cout << left << "   [" << n << setw(5) << "]:" << setw(15) << *j;
                
                } else if ((k % 4) == 2) {
                    // Reference #
                    cout << left << setw(15) << *j;

                } else if ((k % 4) == 3) {
                    // Description
                    cout << left << setw(45) << *j;

                } else if ((k % 4) == 0) {
                    // Amount Due
                    cout << left << "$" << setw(10) << *j << endl;
                }

                k++;
            } 
            cout << endl << endl;
        }

    }

};

#endif
