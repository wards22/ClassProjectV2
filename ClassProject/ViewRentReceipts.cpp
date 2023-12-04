/* Prologue
* Name: View Rent Receipts Info Implementation File
* Description: Creates and modifies tenant's Rent file
* Contributors: Crischelle Polley
* Date created: Dec 2 2023
* Date last modified: Dec 2 2023
*/

/* References:
* https://stackoverflow.com/questions/1784573/iterator-for-2d-vector
* https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program
* https://cplusplus.com/reference/chrono/
* https://cplusplus.com/reference/thread/thread/
*/


#include "ViewRentReceipts.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


void ViewRentReceipts::displayRentReceipts(const vector<vector<string>>& rentReceipts)
{
    cout << left << setw(40) << "Rent Receipts" << endl;
    cout << left << setw(40) << "-------------------------------" << endl;

    int k;          //Keep track of each rent receipt for each tenant
    int n;          // Keep track of how many rent receipts each tenant has
    for (auto i = rentReceipts.begin(); i != rentReceipts.end(); i++) {

        k = 0;
        n = 0;
        for (auto j = i->begin(); j != i->end(); j++) {
            if (k == 0) {
                cout << left << setw(10) << "UserID:" << setw(30) << *j << endl;

            } else if ((k % 4) == 1) {
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



void ViewRentReceipts::displayRentReceipts_inProgress(const vector<vector<string>>& rentReceipts) {
    
    cout << left << setw(40) << "Rent Receipt In Progress" << endl;
    cout << left << setw(40) << "-------------------------------" << endl;

    if (rentReceipts.size() == 0)
        cout << "There are no unsubmitted receipts.\n\n";

    for (auto i = rentReceipts.begin(); i != rentReceipts.end(); i++) {

        for (auto j = i->begin(); ;) {
            cout << left << setw(16) << "UserID:" << setw(30) << *j << endl;
            // Date Posted
            cout << left << setw(16) << "" << setw(30) << *(j + 2) << endl << endl;
            // Reference #
            cout << left << setw(16) << "" << *(j + 3) << endl << endl;
            // Receipt
            cout << left << setw(16) << "" << *(j + 4) << endl << endl;
            // Amount
            cout << left << setw(16) << "" << *(j + 3) << endl << endl;
            cout << left << setw(40) << "-------------------------------" << endl;
            break;
        }
        cout << endl;
    }
}