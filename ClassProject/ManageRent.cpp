/* Prologue
 * Name: Manage Tenant Account Methods
 * Description: Implementation file for ManageTenantAccount
 * Contributors: Crischelle Polley
 * Date created: Nov 27 2023
 * Date last modified: Dec 1 2023
*/

#include "ManageRent.h"
#include "Rent.h"
#include "ViewRentReceipts.h"
#include <string>
#include <iostream>

using namespace std;


void ManageRent::manageRentForTenant(int uid, int option, string s) {
    Rent rent(uid);

    // [1] View Rent Receipts
    // This will access View Rent Receipt boundary class
    if (option == 1) {
        ViewRentReceipts::displayRentReceipts(rent.getRentReceipts());
    }

    // [2] Set Payment Method
    else if (option == 2) {

        if (s == "card") {
            rent.setPaymentMethod(s);

        } else if (s == "ACH") {
            rent.setPaymentMethod(s);

        } else if (s == "eCheck") {
            rent.setPaymentMethod(s);

        } else if (s == "moneyOrder") {
            rent.setPaymentMethod(s);
            cout << "Once you have gotten your money order,\n"
                << "please turn it in at the leasing office.\n\n";
        }
    }

    // [3] Pay Rent
    else if (option == 3) {
        if (rent.getBalanceDue() <= 0) {
            cout << "You have no rent due at this time.\n\n";
        } else {
            float remainingBalanceDue = rent.payRentReceipt(stof(s));
            cout << "Remaining Balance Due: $" << remainingBalanceDue << endl;
        }
    }

    // To access balance due
    else if (option == NULL) {
        cout << "Current Rent Due: $" << rent.getBalanceDue() << endl;
    }

}

void ManageRent::manageRentForStaff(int uid, int option) {

}
