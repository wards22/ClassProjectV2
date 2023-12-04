/* Prologue
 * Name: Manage Tenant Account Methods
 * Description: Implementation file for ManageTenantAccount
 * Contributors: Crischelle Polley
 * Date created: Nov 27 2023
 * Date last modified: Dec 3 2023
*/

#include "ManageRent.h"
#include "Rent.h"
#include "ViewRentReceipts.h"
#include "StaffUI.h"
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

//-------------------------------------------------------------------------------------------


void ManageRent::manageRentForStaff(int uid, int option) {
    Rent rent(uid);
    // [1] View Rent Receipts
    // This will access View Rent Receipts boundary class
    if (option == 1) {
        ViewRentReceipts::displayRentReceipts(rent.getRentReceipts());
    }
    
    // [2] Create Rent Receipt
    else if (option == 2) {
        // Check if rent receipt is in progress
        if (rent.getProgressStatus() == true) {
            cout << "A rent receipt is waiting to be posted.\n"
                << "Go to Edit Rent Receipt to edit current rent receipt.\n\n";
        } else {
            rent.setDate("","","");
            rent.setReferenceNum("");
            rent.setDescription("");
            rent.setAmount(-1);

            string mm, dd, yyyy;
            cout << "Enter the current month (MM): ";
            cin >> mm;
            rent.setMonth(mm);

            cout << "Enter the current day (DD): ";
            cin >> dd;
            rent.setDay(dd);

            cout << "Enter the current year (YYYY): ";
            cin >> yyyy;
            rent.setYear(yyyy);

            rent.setDate(mm, dd, yyyy);

            string refNum;
            cout << "Enter the reference number (LLL NNNN): ";
            getline(cin, refNum);
            rent.setReferenceNum(refNum);

            string descr;
            cout << "Enter the description: ";
            getline(cin, descr);
            rent.setDescription(descr);

            string amount;
            cout << "Enter the amount: $";
            getline(cin, amount);
            rent.setAmount(stof(amount));

        }

    }
    /*
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
    */
}

void ManageRent::manageRentForStaff(int uid, int tid, string option) {
    Rent rent(tid, "inProgress"); 

    if(option == "balanceDue") {
        cout << "Current Rent Due: $" << rent.getBalanceDue() << endl;
    
    } else if (option == "createRentReceipt") {
        ViewRentReceipts::displayRentReceipts_inProgress(rent.getRentReceipts());

        if (rent.getRentReceipts().size() == 0) {
            StaffUI::displayRentMenu(uid);
        }

    } else if(option == "editRentReceipt") {
        ViewRentReceipts::displayRentReceipts_inProgress(rent.getRentReceipts());

        if(rent.getRentReceipts().size() == 0) {
            StaffUI::displayRentMenu(uid);
        }
 
    } else if (option == "deleteRentReceipt") {
        ViewRentReceipts::displayRentReceipts_inProgress(rent.getRentReceipts());

        if (rent.getRentReceipts().size() == 0) {
            StaffUI::displayRentMenu(uid);
        }    
    }
}


void ManageRent::manageRentForStaff(int sid, int tid, float a, string refNum) {
    // Create object to get tenant receipts
    Rent rent(sid);

    rent.writeRentReceipt(tid, a, refNum);
}
