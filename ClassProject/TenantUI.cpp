/* Prologue
 * Name: Tenant UI Class
 * Description: Implementation file for TenantUI.h
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Nov 21 2023
*/

/* Two options for connecting Tenant UI to Entity Classes
 * 1: directly call the manageClassname() from MainMenu
 * 2: pass option number as argument to manageClassname
 *    in secondary menus
 * Option 2 is best because:
 * This keeps delination of boundary class and control
 * class (encapsulation)
 */


#include "TenantUI.h"
#include "ManageTenantAccount.h"
#include "ManageRent.h"
#include <iostream>

using namespace std;


void TenantUI::displayMainMenu() {

    cout << "Main Menu\n";
    cout << "--------------------------\n";
    cout << "[1] Account\n";
    cout << "[2] Rent\n";
    cout << "[3] Maintenance Request\n";
    cout << "[4] Notifications\n";
    cout << "[5] Lease\n";
    cout << "[6] Application\n";
    cout << "[7] Exit\n";
    cout << "\nEnter a number 1 through 7: ";

    int option = -1;
    cin >> option;
    cout << endl;

    if (option == 1) {
        displayTenantAccountMenu();
    }
    else if (option == 2) {
        displayRentMenu();
    }
    else if (option == 3) {
        displayMaintenanceRequestMenu();
    }
    else if (option == 4) {
        displayNotifications();
    }
    else if (option == 5) {
        displayLease();
    }
    else if (option == 6) {
        displayApplication();
    }
    else if (option == 7) {
        exit();
    }
    else {
        cout << "Please enter a number 1 through 7. \n\n";
        displayMainMenu();
    }

}

//-------------------------------------------------------------------------------------------

void TenantUI::displayTenantAccountMenu() {

    // Display Account features for tenant
    cout << "Account\n";
    cout << "--------------------------\n";
    // Have view account information as option 
    // or automatically display account info?
    cout << "[1] View Account Information\n";
    cout << "[2] Change Username\n";
    cout << "[3] Change Password\n";
    cout << "[4] Change Phone Number\n";
    cout << "[5] Change Email\n";
    cout << "[6] Return to Main Menu\n";
    cout << "[7] Exit\n";
    cout << "\nEnter a number 1 through 7: ";

    // Read in tenant option
    int option = -1;
    cin >> option;
    cout << endl;

    // Create object to access ManageTenantAccount class
    ManageTenantAccount manager;

    // [1] View Account Information
    if (option == 1) {
        //manager.manageTenantAccountForTenant(option, "NULL");

    // [2] Change Username
    }
    else if (option == 2) {
        string username;
        cout << "Enter your new username: ";
        cin >> username;

        // Input validation to be added later

        manager.manageTenantAccountForTenant(option, username);

        cout << "Your username has been changed successfully\n\n";
        displayTenantAccountMenu();

        // [3] Change Password
    }
    else if (option == 3) {
        string password;
        cout << "Enter your new password: ";
        cin >> password;

        // Input validation to be added later

        //manager.manageTenantAccountForTenant(option, password);

        cout << "Your password has been changed successfully\n\n";
        displayTenantAccountMenu();

        // [4] Change Phone Number
    }
    else if (option == 4) {
        string phoneNum;
        cout << "Enter your new phone number: ";
        cin >> phoneNum;

        // Input validation to be added later

        //manager.manageTenantAccountForTenant(option, phoneNum);

        cout << "Your phone number has been changed successfully\n\n";
        displayTenantAccountMenu();

        // [5] Change Email
    }
    else if (option == 5) {
        string email;
        cout << "Enter your new email: ";
        cin >> email;

        // Input validation to be added later

        //manager.manageTenantAccountForTenant(option, email);

        cout << "Your email has been changed successfully\n\n";
        displayTenantAccountMenu();

        // [6] Return to Main Menu
    }
    else if (option == 6) {
        cout << "Returning to Main Menu\n\n";
        displayMainMenu();

        // [7] Exit
    }
    else if (option == 7) {
        cout << "Exiting program\n\n";
        exit();

    }
    else {
        cout << "Please enter a number 1 through 7. \n\n";
        displayTenantAccountMenu();
    }

}

//-------------------------------------------------------------------------------------------

void TenantUI::displayRentMenu() {
    // Display Rent features for tenant
    cout << "Rent\n";
    cout << "--------------------------\n";
    cout << "[1] View Rent Receipts\n";
    cout << "[2] Set Payment Method\n";
    // Display current rent price in Pay Rent option
    cout << "[3] Pay Rent\n";
    cout << "[4] Return to Main Menu\n";
    cout << "[5] Exit\n";
    cout << "\nEnter a number 1 through 5: ";

    // Read in tenant option
    int option = -1;
    cin >> option;
    cout << endl;

    // Create object to access ManageRent class
    ManageRent manager;

    // [1] View Rent Receipts
    if (option == 1) {
        //manager.manageRentForTenant(option, "NULL");

    // [2] Set Payment Method
    }
    else if (option == 2) {
        cout << "Choose a payment method:\n";
        cout << "[1] Credit/Debit Card (one-time payment)\n";
        cout << "[2] ACH/Automatic Withdrawal\n";
        cout << "[3] eCheck\n";
        cout << "[4] Money Order\n";
        cout << "[5] Return to Rent Menu\n";
        cout << "[6] Return to Main Menu\n";
        cout << "[7] Exit\n";
        cout << "\nEnter a number 1 through 7: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: manager.manageRentForTenant(option, "card");
            cout << "Your payment method has been changed successfully\n\n";
            break;
        case 2: manager.manageRentForTenant(option, "ACH");
            cout << "Your payment method has been changed successfully\n\n";
            break;
        case 3: manager.manageRentForTenant(option, "eCheck");
            cout << "Your payment method has been changed successfully\n\n";
            break;
        case 4: manager.manageRentForTenant(option, "moneyOrder");
            cout << "Your payment method has been changed successfully\n\n";
            break;
        case 5: displayRentMenu(); break;
        case 6: displayMainMenu(); break;
        case 7: exit(); break;
        }

        // [3] Pay Rent
    }
    else if (option == 3) {
        // Display balance due
        manager.manageRentForTenant(NULL, "NULL");

        string paymentAmount;
        cout << "Enter how much you want to pay: $";
        cin >> paymentAmount;

        // Input validation to be added later

        manager.manageRentForTenant(option, paymentAmount);
        cout << "Your rent has been paid successfully\n\n";

        // [4] Return to Main Menu
    }
    else if (option == 4) {
        cout << "Returning to Main Menu\n\n";
        displayMainMenu();

        // [5] Exit
    }
    else if (option == 5) {
        cout << "Exiting program\n\n";
        exit();

    }
    else {
        cout << "Please enter a number 1 through 5. \n\n";
        displayRentMenu();
    }
}

//-------------------------------------------------------------------------------------------

void TenantUI::displayMaintenanceRequestMenu() {
    cout << "This is MaintenanceRequestMenu" << endl;
}

//-------------------------------------------------------------------------------------------

void TenantUI::displayNotifications() {
    cout << "This is Notifications" << endl;
}

//-------------------------------------------------------------------------------------------

void TenantUI::displayLease() {
    cout << "This is Lease" << endl;
}

//-------------------------------------------------------------------------------------------

void TenantUI::displayApplication() {
    cout << "This is Application" << endl;
}

//-------------------------------------------------------------------------------------------

void TenantUI::exit() {
    // Exits entire program
    cout << "This is exit" << endl;
}