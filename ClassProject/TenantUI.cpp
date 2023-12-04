/* Prologue
 * Name: Tenant UI Class
 * Description: Implementation file for TenantUI.h
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Dec 3 2023
*/

/* References:
 * https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input 
 */ 

#include "TenantUI.h"
#include "GeneralUI.h"
#include "ManageTenantAccount.h"
#include "ManageRent.h"
#include "ManageNotifications.h"
#include "ManageLease.h"
#include "ManageMaintenance.h"
#include <iostream>
#include <chrono>       // For delay after display
#include <thread>       // For delay after display
#include <limits>       // For input validation

using namespace std;
using namespace chrono;
using namespace this_thread;


void TenantUI::displayTenantMenu(int uid) {
    sleep_for(microseconds(1000));

    cout << "Tenant Menu\n";
    cout << "--------------------------\n";
    cout << "[1] Account\n";
    cout << "[2] Rent\n";
    cout << "[3] Maintenance\n";
    cout << "[4] Notifications\n";
    cout << "[5] Lease\n";
    cout << "[6] Application\n";
    cout << "[7] Return to Start Menu\n";
    cout << "[8] Quit\n";
    cout << "\nEnter a number 1 through 8: ";


    int option = -1;
    cin >> option;
    cout << endl;


    // [1] Account
    if (option == 1) {
        cout << "---------------------------------------------------------\n";
        displayTenantAccountMenu(uid);

    } // [2] Rent
    else if (option == 2) {
        cout << "---------------------------------------------------------\n";
        displayRentMenu(uid);

    } // [3] Maintenance Request
    else if (option == 3) {
        cout << "---------------------------------------------------------\n";
        displayMaintenanceMenu(uid);

    } // [4] Notifications
    else if (option == 4) {
        cout << "---------------------------------------------------------\n";
        displayNotificationsMenu(uid);

    } // [5] Lease
    else if (option == 5) {
        cout << "---------------------------------------------------------\n";
        displayLeaseMenu(uid);

    } // [6] Application
    else if (option == 6) {
        cout << "---------------------------------------------------------\n";
        displayApplicationMenu(uid);

    } // [7] Return to Start Menu
    else if (option == 7) {
        cout << "---------------------------------------------------------\n";
        sleep_for(microseconds(1000));
        GeneralUI::displayGeneralUI();

    } // [8] Quit
    else if (option == 8) {
        cout << "---------------------------------------------------------\n";
        quit();

    } else {
        // cin fails when reading non-int into int and sets fail flag
        // Flag has to be removed and buffer cleared (ignore needs size to work)
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number 1 through 8.\n\n";
        cout << "---------------------------------------------------------\n";
        displayTenantMenu(uid);
    }

}

//-------------------------------------------------------------------------------------------

void TenantUI::displayTenantAccountMenu(int uid) {
    sleep_for(microseconds(1000));

    // Display Account features for tenant
    cout << "Account Menu\n";
    cout << "--------------------------\n";
    cout << "[1] View Account Information\n";
    cout << "[2] Change Username\n";
    cout << "[3] Change Password\n";
    cout << "[4] Change Phone Number\n";
    cout << "[5] Change Email\n";
    cout << "[6] Return to Tenant Menu\n";
    cout << "[7] Return to Start Menu\n";
    cout << "[8] Quit\n";
    cout << "\nEnter a number 1 through 8: ";


    // Read in tenant option
    int option = -1;
    cin >> option;
    cout << endl;


    // [1] View Account Information
    if (option == 1) {
        ManageTenantAccount::manageTenantAccountForTenant(uid, option, "NULL");
        cout << "---------------------------------------------------------\n";
        displayTenantAccountMenu(uid);

    } // [2] Change Username
    else if (option == 2) {
        string username;
        cout << "Enter your new username: ";
        cin >> username;

        // Input validation to be added later

        ManageTenantAccount::manageTenantAccountForTenant(uid, option, username);

        cout << "Your username has been changed successfully\n\n";
        cout << "---------------------------------------------------------\n";
        displayTenantAccountMenu(uid);

    } // [3] Change Password
    else if (option == 3) {
        string password;
        cout << "Enter your new password: ";
        cin >> password;

        // Input validation to be added later

        ManageTenantAccount::manageTenantAccountForTenant(uid, option, password);

        cout << "Your password has been changed successfully\n\n";
        cout << "---------------------------------------------------------\n";
        displayTenantAccountMenu(uid);

    } // [4] Change Phone Number
    else if (option == 4) {
        string phoneNum;
        cout << "Enter your new phone number: ";
        cin >> phoneNum;

        // Input validation to be added later

        ManageTenantAccount::manageTenantAccountForTenant(uid, option, phoneNum);

        cout << "Your phone number has been changed successfully\n\n";
        cout << "---------------------------------------------------------\n";
        displayTenantAccountMenu(uid);

    } // [5] Change Email
    else if (option == 5) {
        string email;
        cout << "Enter your new email: ";
        cin >> email;

        // Input validation to be added later

        ManageTenantAccount::manageTenantAccountForTenant(uid, option, email);

        cout << "Your email has been changed successfully\n\n";
        cout << "---------------------------------------------------------\n";
        displayTenantAccountMenu(uid);

    } // [6] Return to Tenant Menu
    else if (option == 6) {
        cout << "Returning to Tenant Menu\n\n";
        displayTenantMenu(uid);

    } // [7] Return to General UI
    else if (option == 7) {
        cout << "Returning to Start Menu\n\n";
        cout << "---------------------------------------------------------\n";
        GeneralUI::displayGeneralUI();

    } // [8] Quit
    else if (option == 8) {
        quit();

    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number 1 through 8. \n\n";
        cout << "---------------------------------------------------------\n";
        displayTenantAccountMenu(uid);
    }

}

//-------------------------------------------------------------------------------------------

void TenantUI::displayRentMenu(int uid) {
    sleep_for(microseconds(1000));

    // Display Rent features for tenant
    cout << "Rent Menu\n";
    cout << "--------------------------\n";
    cout << "[1] View Rent Receipts\n";
    cout << "[2] Set Payment Method\n";
    // Display current rent price in Pay Rent option
    cout << "[3] Pay Rent\n";
    cout << "[4] Return to Tenant Menu\n";
    cout << "[5] Return to Start Menu\n";
    cout << "[6] Quit\n";
    cout << "\nEnter a number 1 through 6: ";


    // Read in tenant option
    int option = -1;
    cin >> option;
    cout << endl;


    // [1] View Rent Receipts
    if (option == 1) {
        ManageRent::manageRentForTenant(uid, option, "NULL");
        cout << "---------------------------------------------------------\n";
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
        cout << "[8] Quit\n";
        cout << "\nEnter a number 1 through 8: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: 
            ManageRent::manageRentForTenant(uid, option, "card");
            cout << "Your payment method has been changed successfully\n\n";
            cout << "---------------------------------------------------------\n";
            displayRentMenu(uid);
            break;
        case 2: 
            ManageRent::manageRentForTenant(uid, option, "ACH");
            cout << "Your payment method has been changed successfully\n\n";
            cout << "---------------------------------------------------------\n";
            displayRentMenu(uid);
            break;
        case 3: 
            ManageRent::manageRentForTenant(uid, option, "eCheck");
            cout << "Your payment method has been changed successfully\n\n";
            cout << "---------------------------------------------------------\n";
            displayRentMenu(uid);
            break;
        case 4: 
            ManageRent::manageRentForTenant(uid, option, "moneyOrder");
            cout << "Your payment method has been changed successfully\n\n";
            cout << "---------------------------------------------------------\n";
            displayRentMenu(uid);
            break;
        case 5: 
            cout << "---------------------------------------------------------\n"; 
            displayRentMenu(uid);
            break;
        case 6: 
            cout << "---------------------------------------------------------\n"; 
            displayTenantMenu(uid);
            break;
        case 7: 
            cout << "---------------------------------------------------------\n"; 
            GeneralUI::displayGeneralUI();
            break;
        case 8:  
            cout << "---------------------------------------------------------\n"; 
            quit();
            break;
        default: 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Please enter a number 1 through 8. \n\n";
            cout << "---------------------------------------------------------\n";
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
        cout << "---------------------------------------------------------\n";
        displayRentMenu(uid);

    } // [4] Return to Tenant Menu
    else if (option == 4) {
        cout << "Returning to Tenant Menu\n\n";
        cout << "---------------------------------------------------------\n";
        displayTenantMenu(uid);

    } // [5] Return to General UI
    else if (option == 7) {
        cout << "---------------------------------------------------------\n";
        GeneralUI::displayGeneralUI();

    } // [6] Quit
    else if (option == 5) {
        quit();

    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number 1 through 6. \n\n";
        cout << "---------------------------------------------------------\n";
        displayRentMenu(uid);
    }
}

//-------------------------------------------------------------------------------------------

void TenantUI::displayMaintenanceMenu(int uid) {
    sleep_for(microseconds(1000));

    // Display Maintenance features for tenant
    cout << "Maintenance Menu\n";
    cout << "--------------------------\n";
    // Status of current maintenance request can be shown in View Maintenance Request
    cout << "[1] View Maintenance Requests (see status)\n";
    cout << "[2] Request Maintenance\n";
    // Edit maintenance request if part of maintenance class
    cout << "[3] Edit Maintenance Requests\n";
    cout << "[4] Return to Tenant Menu\n";
    cout << "[5] Return to Start Menu\n";
    cout << "[6] Quit\n";
    cout << "\nEnter a number 1 through 6: ";


    // Read in tenant option
    int option = -1;
    cin >> option;
    cout << endl;


    // [1] View Maintenance Requests
    if (option == 1) {
        ManageMaintenance::manageMaintenanceForTenant(option, uid);
        cout << "---------------------------------------------------------\n";
        displayMaintenanceMenu(uid);

    } // [2] Request Maintenance
    else if (option == 2) {
        ManageMaintenance::manageMaintenanceForTenant(option, uid);
        cout << "You have requested maintenance successfully.\n\n";
        cout << "---------------------------------------------------------\n";
        displayMaintenanceMenu(uid);

    } // [3] Edit Maintenance Request
    else if (option == 3) {
        ManageMaintenance::manageMaintenanceForTenant(option, uid);
        cout << "You have changed your maintenance request successfully.\n\n";
        cout << "---------------------------------------------------------\n";
        displayMaintenanceMenu(uid);

    } // [4] Return to Tenant Menu
    else if (option == 4) {
        cout << "Returning to Tenant Menu\n\n";
        cout << "---------------------------------------------------------\n";
        displayTenantMenu(uid);

    } // [5] Return to General UI
    else if (option == 7) {
        cout << "Returning to Start Menu\n\n";
        cout << "---------------------------------------------------------\n";
        GeneralUI::displayGeneralUI();

    } // [6] Quit
    else if (option == 5) {
        cout << "---------------------------------------------------------\n";
        quit();

    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number 1 through 6. \n\n";
        cout << "---------------------------------------------------------\n";
        displayMaintenanceMenu(uid);
    }

}

//-------------------------------------------------------------------------------------------

void TenantUI::displayNotificationsMenu(int uid) {
    sleep_for(microseconds(1000));

    // Display Notification features for tenant
    // Tenant can only view notifications (limitation is tenant cannot communicate with staff through system)
    cout << "Notifications Menu\n";
    cout << "--------------------------\n";
    // Status of current maintenance request can be shown in View Maintenance Request
    cout << "[1] View Notifications\n";
    cout << "[2] Return to Tenant Menu\n";
    cout << "[3] Return to Start Menu\n";
    cout << "[4] Quit\n";
    cout << "\nEnter a number 1 through 4: ";


    // Read in tenant option
    int option = -1;
    cin >> option;
    cout << endl;


    // [1] View Notifications
    if (option == 1) {
        ManageNotifications::manageNotifications(uid, option);
        cout << "---------------------------------------------------------\n";
        displayNotificationsMenu(uid);

    } // [2] Return to Tenant Menu
    else if (option == 2) {
        cout << "Returning to Tenant Menu\n\n";
        cout << "---------------------------------------------------------\n";
        displayTenantMenu(uid);

    } // [3] Return to General UI
    else if (option == 3) {
        cout << "Returning to Start Menu\n\n";
        cout << "---------------------------------------------------------\n";
        GeneralUI::displayGeneralUI();

    } // [4] Quit
    else if (option == 4) {
        cout << "---------------------------------------------------------\n";
        quit();

    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number 1 through 4. \n\n";
        cout << "---------------------------------------------------------\n";
        displayNotificationsMenu(uid);
    }
}

//-------------------------------------------------------------------------------------------

void TenantUI::displayLeaseMenu(int uid) {
    sleep_for(microseconds(1000));

    // Display Lease features for tenant
    cout << "Lease Menu\n";
    cout << "--------------------------\n";
    cout << "[1] View Lease\n";
    cout << "[2] Return to Tenant Menu\n";
    cout << "[3] Return to Start Menu\n";
    cout << "[4] Quit\n";
    cout << "\nEnter a number 1 through 4: ";


    // Read in tenant option
    int option = -1;
    cin >> option;
    cout << endl;


    // [1] View Lease
    if (option == 1) {
        ManageLease::manageLeaseForTenant(uid);
        cout << "---------------------------------------------------------\n";
        displayNotificationsMenu(uid);

    } // [2] Return to Tenant Menu
    else if (option == 2) {
        cout << "Returning to Tenant Menu\n\n";
        cout << "---------------------------------------------------------\n";
        displayTenantMenu(uid);

    } // [3] Return to General UI
    else if (option == 3) {
        cout << "Returning to Start Menu\n\n";
        cout << "---------------------------------------------------------\n";
        GeneralUI::displayGeneralUI();

    } // [4] Quit
    else if (option == 4) {
        cout << "---------------------------------------------------------\n";
        quit();

    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number 1 through 4. \n\n";
        cout << "---------------------------------------------------------\n";
        displayNotificationsMenu(uid);
    }
}

//-------------------------------------------------------------------------------------------

void TenantUI::displayApplicationMenu(int uid) {
    sleep_for(microseconds(1000));

    cout << "This is Application" << endl;
}

//-------------------------------------------------------------------------------------------

void TenantUI::quit() {
    sleep_for(microseconds(3000));

    // Exits entire program
    cout << "You are being logged out..." << endl;
    sleep_for(microseconds(3000));
    cout << "Thank you for visitng UHD Apartments. Have a nice day!" << endl;
    exit(0);
}