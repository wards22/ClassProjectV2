/* Prologue
 * Name: Tenant UI Class
 * Description: Implementation file for TenantUI.h
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Nov 29 2023
*/

#include "TenantUI.h"
#include "GeneralUI.h"
#include "ManageTenantAccount.h"
#include "ManageRent.h"
#include "ManageNotifications.h"
#include "ManageLease.h"
#include "ManageMaintenance.h"
#include <iostream>

using namespace std;


void TenantUI::displayTenantMenu(int uid) {

    cout << "Tenant Menu\n";
    cout << "--------------------------\n";
    cout << "[1] Account\n";
    cout << "[2] Rent\n";
    cout << "[3] Maintenance\n";
    cout << "[4] Notifications\n";
    cout << "[5] Lease\n";
    cout << "[6] Application\n";
    cout << "[7] Return to Start Menu\n";
    cout << "[8] Exit\n";
    cout << "\nEnter a number 1 through 8: ";

    /*
    cin.ignore();
    char option = -1;
    cin.get(option);
    cout << endl;

    // Input validation
    if(!isdigit(option)) {
        cout << "Please enter a number 1 through 8.\n\n";
        // Discard rest of input buffer
        cin.ignore('\n');
        displayTenantMenu(uid);
    }
    */

    int option = -1;
    cin >> option;
    cout << endl;

    // [1] Account
    if (option == 1) {
        displayTenantAccountMenu(uid);

    } // [2] Rent
    else if (option == 2) {
        displayRentMenu(uid);

    } // [3] Maintenance Request
    else if (option == 3) {
        displayMaintenanceMenu(uid);

    } // [4] Notifications
    else if (option == 4) {
        displayNotificationsMenu(uid);

    } // [5] Lease
    else if (option == 5) {
        displayLeaseMenu(uid);

    } // [6] Application
    else if (option == 6) {
        displayApplicationMenu(uid);

    } // [7] Return to Start Menu
    else if (option == 7) {
        GeneralUI::displayGeneralUI();

    } // [8] Exit
    else if (option == 8) {
        exit();

    } else // Only catches int outside of 1-8 
    {
        cout << "Please enter a number 1 through 8.\n\n";
        displayTenantMenu(uid);
    }

}

//-------------------------------------------------------------------------------------------

void TenantUI::displayTenantAccountMenu(int uid) {

    // Display Account features for tenant
    cout << "Account\n";
    cout << "--------------------------\n";
    cout << "[1] View Account Information\n";
    cout << "[2] Change Username\n";
    cout << "[3] Change Password\n";
    cout << "[4] Change Phone Number\n";
    cout << "[5] Change Email\n";
    cout << "[6] Return to Tenant Menu\n";
    cout << "[7] Return to Start Menu\n";
    cout << "[8] Exit\n";
    cout << "\nEnter a number 1 through 8: ";


    // Read in tenant option
    int option = -1;
    cin >> option;
    cout << endl;


    // [1] View Account Information
    if (option == 1) {
        ManageTenantAccount::manageTenantAccountForTenant(uid, option, "NULL");
        displayTenantAccountMenu(uid);

    } // [2] Change Username
    else if (option == 2) {
        string username;
        cout << "Enter your new username: ";
        cin >> username;

        // Input validation to be added later

        ManageTenantAccount::manageTenantAccountForTenant(uid, option, username);

        cout << "Your username has been changed successfully\n\n";
        displayTenantAccountMenu(uid);

    } // [3] Change Password
    else if (option == 3) {
        string password;
        cout << "Enter your new password: ";
        cin >> password;

        // Input validation to be added later

        ManageTenantAccount::manageTenantAccountForTenant(uid, option, password);

        cout << "Your password has been changed successfully\n\n";
        displayTenantAccountMenu(uid);

    } // [4] Change Phone Number
    else if (option == 4) {
        string phoneNum;
        cout << "Enter your new phone number: ";
        cin >> phoneNum;

        // Input validation to be added later

        ManageTenantAccount::manageTenantAccountForTenant(uid, option, phoneNum);

        cout << "Your phone number has been changed successfully\n\n";
        displayTenantAccountMenu(uid);

    } // [5] Change Email
    else if (option == 5) {
        string email;
        cout << "Enter your new email: ";
        cin >> email;

        // Input validation to be added later

        ManageTenantAccount::manageTenantAccountForTenant(uid, option, email);

        cout << "Your email has been changed successfully\n\n";
        displayTenantAccountMenu(uid);

    } // [6] Return to Tenant Menu
    else if (option == 6) {
        cout << "Returning to Tenant Menu\n\n";
        displayTenantMenu(uid);

    } // [7] Return to General UI
    else if (option == 7) {
        cout << "Returning to Start Menu\n\n";
        GeneralUI::displayGeneralUI();

    } // [8] Exit
    else if (option == 8) {
        cout << "Exiting program\n\n";
        exit();

    } else {
        cout << "Please enter a number 1 through 8. \n\n";
        displayTenantAccountMenu(uid);
    }

}

//-------------------------------------------------------------------------------------------

void TenantUI::displayRentMenu(int uid) {
    // Display Rent features for tenant
    cout << "Rent\n";
    cout << "--------------------------\n";
    cout << "[1] View Rent Receipts\n";
    cout << "[2] Set Payment Method\n";
    // Display current rent price in Pay Rent option
    cout << "[3] Pay Rent\n";
    cout << "[4] Return to Tenant Menu\n";
    cout << "[5] Return to Start Menu\n";
    cout << "[6] Exit\n";
    cout << "\nEnter a number 1 through 6: ";


    // Read in tenant option
    int option = -1;
    cin >> option;
    cout << endl;


    // [1] View Rent Receipts
    if (option == 1) {
        ManageRent::manageRentForTenant(uid, option, "NULL");
        displayRentMenu(uid);

    } // [2] Set Payment Method
    else if (option == 2) {
        cout << "Choose a payment method:\n";
        cout << "[1] Credit/Debit Card (one-time payment)\n";
        cout << "[2] ACH/Automatic Withdrawal\n";
        cout << "[3] eCheck\n";
        cout << "[4] Money Order\n";
        cout << "[5] Return to Rent Menu\n";
        cout << "[6] Return to Tenant Menu\n";
        cout << "[7] Return to Start Menu\n";
        cout << "[8] Exit\n";
        cout << "\nEnter a number 1 through 8: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: ManageRent::manageRentForTenant(uid, option, "card");
            cout << "Your payment method has been changed successfully\n\n";
            displayRentMenu(uid);
            break;
        case 2: ManageRent::manageRentForTenant(uid, option, "ACH");
            cout << "Your payment method has been changed successfully\n\n";
            displayRentMenu(uid);
            break;
        case 3: ManageRent::manageRentForTenant(uid, option, "eCheck");
            cout << "Your payment method has been changed successfully\n\n";
            displayRentMenu(uid);
            break;
        case 4: ManageRent::manageRentForTenant(uid, option, "moneyOrder");
            cout << "Your payment method has been changed successfully\n\n";
            displayRentMenu(uid);
            break;
        case 5: displayRentMenu(uid);
            break;
        case 6: displayTenantMenu(uid);
            break;
        case 7: GeneralUI::displayGeneralUI();
            break;
        case 8: exit();
            break;
        default: cout << "Please enter a number 1 through 8. \n\n";
            displayRentMenu(uid);
            break;
        }

    } // [3] Pay Rent
    else if (option == 3) {
        // Display balance due
        ManageRent::manageRentForTenant(uid, NULL, "NULL");

        string paymentAmount;
        cout << "Enter how much you want to pay: $";
        cin >> paymentAmount;

        // Input validation to be added later

        ManageRent::manageRentForTenant(uid, option, paymentAmount);
        cout << "Your rent has been paid successfully.\n\n";
        displayRentMenu(uid);

    } // [4] Return to Tenant Menu
    else if (option == 4) {
        cout << "Returning to Tenant Menu\n\n";
        displayTenantMenu(uid);

    } // [5] Return to General UI
    else if (option == 7) {
        GeneralUI::displayGeneralUI();

    } // [6] Exit
    else if (option == 5) {
        cout << "Exiting program\n\n";
        exit();

    } else {
        cout << "Please enter a number 1 through 6. \n\n";
        displayRentMenu(uid);
    }
}

//-------------------------------------------------------------------------------------------

void TenantUI::displayMaintenanceMenu(int uid) {
    // Display Maintenance features for tenant
    cout << "Maintenance\n";
    cout << "--------------------------\n";
    // Status of current maintenance request can be shown in View Maintenance Request
    cout << "[1] View Maintenance Requests (see status)\n";
    cout << "[2] Request Maintenance\n";
    // Edit maintenance request if part of maintenance class
    cout << "[3] Edit Maintenance Requests\n";
    cout << "[4] Return to Tenant Menu\n";
    cout << "[5] Return to Start Menu\n";
    cout << "[6] Exit\n";
    cout << "\nEnter a number 1 through 6: ";


    // Read in tenant option
    int option = -1;
    cin >> option;
    cout << endl;


    // [1] View Maintenance Requests
    if (option == 1) {
        ManageMaintenance::manageMaintenanceForTenant();

    } // [2] Request Maintenance
    else if (option == 2) {
        ManageMaintenance::manageMaintenanceForTenant();
        cout << "You have requested maintenance successfully.\n\n";

    } // [3] Edit Maintenance Request
    else if (option == 3) {
        ManageMaintenance::manageMaintenanceForTenant();
        cout << "You have changed your maintenance request successfully.\n\n";

    } // [4] Return to Tenant Menu
    else if (option == 4) {
        cout << "Returning to Tenant Menu\n\n";
        displayTenantMenu(uid);

    } // [5] Return to General UI
    else if (option == 7) {
        cout << "Returning to Start Menu\n\n";
        GeneralUI::displayGeneralUI();

    } // [6] Exit
    else if (option == 5) {
        cout << "Exiting program\n\n";
        exit();

    } else {
        cout << "Please enter a number 1 through 6. \n\n";
        displayMaintenanceMenu(uid);
    }

}

//-------------------------------------------------------------------------------------------

void TenantUI::displayNotificationsMenu(int uid) {
    // Display Notification features for tenant
    // Tenant can only view notifications (limitation is tenant cannot communicate with staff through system)
    cout << "Notifications\n";
    cout << "--------------------------\n";
    // Status of current maintenance request can be shown in View Maintenance Request
    cout << "[1] View Notifications\n";
    cout << "[2] Return to Tenant Menu\n";
    cout << "[3] Return to Start Menu\n";
    cout << "[4] Exit\n";
    cout << "\nEnter a number 1 through 4: ";


    // Read in tenant option
    int option = -1;
    cin >> option;
    cout << endl;


    // [1] View Notifications
    if (option == 1) {
        ManageNotifications::manageNotifications(uid, option);
        displayNotificationsMenu(uid);

    } // [2] Return to Tenant Menu
    else if (option == 2) {
        cout << "Returning to Tenant Menu\n\n";
        displayTenantMenu(uid);

    } // [3] Return to General UI
    else if (option == 3) {
        cout << "Returning to Start Menu\n\n";
        GeneralUI::displayGeneralUI();

    } // [4] Exit
    else if (option == 4) {
        cout << "Exiting program\n\n";
        exit();

    } else {
        cout << "Please enter a number 1 through 4. \n\n";
        displayNotificationsMenu(uid);
    }
}

//-------------------------------------------------------------------------------------------

void TenantUI::displayLeaseMenu(int uid) {
    cout << "This is Lease" << endl;
}

//-------------------------------------------------------------------------------------------

void TenantUI::displayApplicationMenu(int uid) {
    cout << "This is Application" << endl;
}

//-------------------------------------------------------------------------------------------

void TenantUI::exit() {
    // Exits entire program
    cout << "This is exit" << endl;
}