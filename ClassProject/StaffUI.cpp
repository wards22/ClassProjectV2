#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>

using namespace std;

#include "StaffUI.h"
#include "Staff.h"
#include "Tenant.h"
#include "GeneralUI.h"
#include "ManageStaff.h"
#include "ManageTenantAccount.h"
#include "ManageMaintenance.h"
#include "ManageLease.h"
#include "ManageRent.h"
#include "ManageNotifications.h"
#include "ViewStaffInfo.h"


void StaffUI::displayMainMenu(int user_ID) {
    Staff staff(user_ID);
    int choice = 0;

    cout << "Main Menu - Staff" << endl;
    cout << "--------------------------" << endl;
    cout << "[1]  Manage Your Account" << endl;
    cout << "[2]  Tenant Info" << endl;
    cout << "[3]  Apartment Info" << endl;
    cout << "[4]  Tenant Rent" << endl;
    cout << "[5]  Maintenance Requests" << endl;
    cout << "[6]  Applications" << endl;
    cout << "[7]  Modify Lease" << endl;
    cout << "[8]  Notifications" << endl;
    cout << "[9]  View Staffing Information" << endl;
    cout << "[10] Logout" << endl << endl;
    cout << "Enter a number 1 through 10: ";

    cin >> choice;
    cout << endl;

    if (choice == 1) {
        displayStaffAccountMenu(staff.getUserID());
    } else if (choice == 2) {
        displayTenantInfoMenu(staff.getUserID());
    } else if (choice == 3) {
        displayApartmentInfoMenu(staff.getUserID());
    } else if (choice == 4) {
        displayRentMenu(staff.getUserID());
    } else if (choice == 5) {
        displayMaintenanceRequestMenu(staff.getUserID());
    } else if (choice == 6) {
        viewApplications(staff.getUserID());
    } else if (choice == 7) {
        displayLease(staff.getUserID());
    } else if (choice == 8) {
        displayNotifications(staff.getUserID());
    } else if (choice == 9) {
        ViewStaffInfo::displayStaffInfo();
        displayMainMenu(staff.getUserID());
    } else if (choice == 10) {
        cout << endl << endl;
        logout();
    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number 1 through 10." << endl << endl;
        displayMainMenu(staff.getUserID());
    }
}

//-------------------------------------------------------------------------------------------

void StaffUI::displayStaffAccountMenu(int user_ID) {

    Staff staff(user_ID);


    cout << staff.getName() << "'s Account" << endl;
    cout << "--------------------------" << endl;
    cout << "[1] View Account Information\n";
    cout << "[2] Change Username" << endl;
    cout << "[3] Change Password" << endl;
    cout << "[4] Change Phone Number" << endl;
    cout << "[5] Change Email" << endl;
    cout << "[6] Return to Main Menu" << endl;
    cout << "[7] Logout" << endl << endl;
    cout << "Enter a number 1 through 7: ";

    // Read in staff option
    int option = 0;
    cin >> option;
    cout << endl;

    // Create object to access ManageStaff class
    ManageStaff manager;

    // [1] View Account Information
    if (option == 1) {
        cout << "Here is your information: " << endl << endl;
        manager.manageStaff(option, staff.getUserID(), "null");
        cout << endl;
        displayStaffAccountMenu(staff.getUserID());

    }
    // [2] Change Username
    else if (option == 2) {
        string username;
        cout << "Enter your new username: ";
        cin.ignore();
        cin.clear();
        getline(cin, username);

        // Input validation to be added later

        manager.manageStaff(option, staff.getUserID(), username);

        cout << "Your username has been changed successfully" << endl << endl;
        displayStaffAccountMenu(staff.getUserID());

        // [3] Change Password
    } else if (option == 3) {
        string password;
        cout << "Enter your new password: ";
        cin.ignore();
        cin.clear();
        getline(cin, password);

        // Input validation to be added later

        manager.manageStaff(option, staff.getUserID(), password);

        cout << "Your password has been changed successfully" << endl << endl;
        displayStaffAccountMenu(staff.getUserID());

        // [4] Change Phone Number
    } else if (option == 4) {
        string phoneNum;
        cout << "Enter your new phone number: ";
        cin.ignore();
        cin.clear();
        getline(cin, phoneNum);

        // Input validation to be added later

        manager.manageStaff(option, staff.getUserID(), phoneNum);

        cout << "Your phone number has been changed successfully" << endl << endl;
        displayStaffAccountMenu(staff.getUserID());

        // [5] Change Email
    } else if (option == 5) {
        string email;
        cout << "Enter your new email: ";
        cin.ignore();
        cin.clear();
        getline(cin, email);

        // Input validation to be added later

        manager.manageStaff(option, staff.getUserID(), email);

        cout << "Your email has been changed successfully" << endl << endl;
        displayStaffAccountMenu(staff.getUserID());

        // [6] Return to Main Menu
    } else if (option == 6) {
        cout << "Returning to Main Menu" << endl << endl;
        displayMainMenu(staff.getUserID());

        // [7] Exit
    } else if (option == 7) {
        cout << endl << endl;
        logout();

    } else {
        cout << "Please enter a number 1 through 7." << endl << endl;
        cin.clear();
        cin.ignore();
        displayStaffAccountMenu(staff.getUserID());
    }
}

//-------------------------------------------------------------------------------------------

void StaffUI::displayTenantInfoMenu(int user_ID) {
    cout << "This is where you will view tenant info." << endl << endl;
    Staff staff(user_ID);
    int tenantID;

    cout << "Tenant Accounts" << endl;
    cout << "--------------------------" << endl;
    cout << "[1] View Tenant Accounts" << endl;
    cout << "[2] Change Tenant Username" << endl;
    cout << "[3] Change Tenant Password" << endl;
    cout << "[4] Change Tenant Phone Number" << endl;
    cout << "[5] Change Tenant Email" << endl;
    cout << "[6] Return to Main Menu" << endl;
    cout << "[7] Logout" << endl << endl;
    cout << "Enter a number 1 through 7: ";

    // Read in staff option
    int option = 0;
    cin >> option;
    cout << endl;


    // [1] View Tenant Account Information
    if (option == 1) {
        cout << "Here is the list of tenants: " << endl << endl;
        ManageTenantAccount::manageTenantAccountForStaff(option, 0, "null");
        cout << endl;
        displayTenantInfoMenu(staff.getUserID());

    } // [2] Change Tenant Username    
    else if (option == 2) {
        string username;
        cout << "Enter the User ID of the tenant whose username you want to change: ";
        cin >> tenantID;
        cout << endl;
        cout << "Enter the tenant's new username: ";
        cin.ignore();
        cin.clear();
        getline(cin, username);

        // Input validation to be added later

        ManageTenantAccount::manageTenantAccountForStaff(option, tenantID, username);

        cout << "The tenant's username has been changed successfully" << endl << endl;
        displayTenantInfoMenu(staff.getUserID());

        
    } // [3] Change Tenant Password
    else if (option == 3) {
        string password;
        cout << "Enter the User ID of the tenant whose password you want to change: ";
        cin >> tenantID;
        cout << endl;
        cout << "Enter the tenant's new password: ";
        cin.ignore();
        cin.clear();
        getline(cin, password);


        ManageTenantAccount::manageTenantAccountForStaff(option, tenantID, password);

        cout << "The tenant's password has been changed successfully" << endl << endl;
        displayTenantInfoMenu(staff.getUserID());

    } // [4] Change Tenant Phone Number
    else if (option == 4) {
        string phoneNum;
        cout << "Enter the User ID of the tenant whose phone number you want to change: ";
        cin >> tenantID;
        cout << endl;
        cout << "Enter the tenant's new phone number: ";
        cin.ignore();
        cin.clear();
        getline(cin, phoneNum);

        ManageTenantAccount::manageTenantAccountForStaff(option, tenantID, phoneNum);

        cout << "The tenant's phone number has been changed successfully" << endl << endl;
        displayTenantInfoMenu(staff.getUserID());
        
    } // [5] Change Tenant Email
    else if (option == 5) {
        string email;
        cout << "Enter the User ID of the tenant whose username you want to change: ";
        cin >> tenantID;
        cout << endl;
        cout << "Enter the tenant's new email: ";
        cin.ignore();
        cin.clear();
        getline(cin, email);

        ManageTenantAccount::manageTenantAccountForStaff(option, tenantID, email);

        cout << "The tenant's email has been changed successfully" << endl << endl;
        displayTenantInfoMenu(staff.getUserID());
   
    } // [6] Return to Main Menu
    else if (option == 6) {
        cout << "Returning to Main Menu\n\n";
        displayMainMenu(staff.getUserID());

        
    } // [7] Exit
    else if (option == 7) {
        cout << endl << endl;
        logout();

    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number 1 through 7." << endl << endl;
        displayTenantInfoMenu(staff.getUserID());
    }

}

//-------------------------------------------------------------------------------------------

void StaffUI::displayApartmentInfoMenu(int user_ID) {
    cout << "This is where you will view apartment info." << endl << endl;
    Staff staff(user_ID);

    cout << "Apartment Information Window" << endl;
    cout << "--------------------------" << endl;
    cout << "[1] View Vacant Apartments" << endl;
    cout << "[2] View Inhabited Apartments" << endl;
    cout << "[3] Update Apartments" << endl;
    cout << "[4] Return to Main Menu" << endl;
    cout << "[5] Logout" << endl << endl;
    cout << "Enter a number 1 through 5: ";

    displayApartmentInfoMenu(staff.getUserID());
}

//-------------------------------------------------------------------------------------------

void StaffUI::displayRentMenu(int user_ID) {

    // Display Rent features for staff
    cout << "Tenant Rent Information\n";
    cout << "--------------------------\n";
    cout << "[1] View Rent Receipts\n";
    cout << "[2] Create Rent Receipt\n";
    cout << "[3] Edit Rent Receipt\n";
    cout << "[4] Delete Rent Receipt\n";
    cout << "[5] Submit Rent Receipt\n";
    cout << "[6] Return to Staff Menu\n";
    cout << "[7] Logout\n";
    cout << "\nEnter a number 1 through 7: ";


    // Read in staff option
    int option = -1;
    cin >> option;
    cout << endl;


    // [1] View Rent Receipts
    if (option == 1) {
        ManageRent::manageRentForStaff(user_ID, option);
        displayRentMenu(user_ID);

    } // [2] Create Rent Receipt
    else if (option == 2) {
        int tenant_id;
        cout << "Enter the user ID of the tenant you want to create a rent receipt for: ";
        cin >> tenant_id;    

        ManageRent::manageRentForStaff(user_ID, tenant_id, "createRentReceipt");


    } // [3] Edit Rent Receipt
    else if (option == 3) {
        int tenant_id;
        cout << "Enter the user ID of the tenant you want to edit a rent receipt for: ";
        cin >> tenant_id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << endl;

        // display tenant rent receipts and get number of rent receipts for input validation (use vector size)
        // Can only edit most recent receipt that is in progress
        ManageRent::manageRentForStaff(user_ID, tenant_id, "editRentReceipt");
        cout << endl;

        // Read in refnum and amount
        // System can automatically assign descr and date
        string refNum;
        float amount;
        cout << "Enter the reference number for this receipt (LLL NNNN): ";
        getline(cin, refNum);
        cout << "Enter the amount of rent for this receipt (NNNN): ";
        cin >> amount;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        // Set refnum and amount and write to file
        ManageRent::manageRentForStaff(user_ID, tenant_id, amount, refNum);

        cout << "\nYou have successfully edited the receipt.\n\n";

        displayRentMenu(user_ID);



    } // [4] Delete Rent Receipt
    else if (option == 4) {
        // Let staff choose which receipt to delete
        // Can only delete those that are not submitted (
        // Show receipts in progress
        int tenant_id;
        cout << "Enter the user ID of the tenant you want to delete a rent receipt for: ";
        cin >> tenant_id;
        cout << endl << endl;

        ManageRent::manageRentForStaff(user_ID, tenant_id, "displayRentReceipts_inProgress");
        // view rent receipt will display if there is any in progress
        cout << endl;

        displayRentMenu(user_ID);

    } // [5] Submit Rent Receipt
    else if (option == 5) {
        // Let staff choose which receipt to submit
        // Show in progress reports
        // choose one
        // change inProgress to false 
        // write inProgress status to file

        // Check if receipt has already been submitted
        // If yes, tell them
        // If no, change progress status 
        // (use progress status to determine which receipts the tenant sees)

        displayRentMenu(user_ID);

    } // [6] Return to Staff Menu
    else if (option == 6) {
        cout << "Returning to Staff Menu\n\n";
        displayMainMenu(user_ID);

    } // [7] Return to General UI
    else if (option == 7) {
        logout();

    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number 1 through 7. \n\n";
        displayRentMenu(user_ID);
    }
}

//-------------------------------------------------------------------------------------------

void StaffUI::displayMaintenanceRequestMenu(int user_ID) {
    cout << "This is where you will view maintenance requests." << endl << endl;

    cout << "Maintenance Request Manager" << endl;
    cout << "--------------------------" << endl;
    cout << "[1] View All" << endl;
    cout << "[2] View Open" << endl;
    cout << "[3] View Closed" << endl;
    cout << "[4] Update Status" << endl;
    cout << "[5] Return to Main Menu" << endl;
    cout << "[6] Logout" << endl << endl;
    cout << "Enter a number 1 through 6: ";

    int option = 0;
    cin >> option;
    cout << endl;

    ManageMaintenance manager;

    if (option == 1) {
        cout << "Here is a list of all Maintenance Requests: " << endl << endl;
        manager.manageMaintenanceForStaff(option);
        cout << endl;
        displayMaintenanceRequestMenu(user_ID);

    } else if (option == 2) {
        cout << "Here is a list of all Open Maintenance Requests: " << endl << endl;
        manager.manageMaintenanceForStaff(option);
        cout << endl;
        displayMaintenanceRequestMenu(user_ID);
    } else if (option == 3) {

        cout << "Here is a list of all Closed Maintenance Requests: " << endl << endl;
        manager.manageMaintenanceForStaff(option);
        cout << endl;
        displayMaintenanceRequestMenu(user_ID);
    } else if (option == 4) {

        cout << "Which Maintenance Requests would you like to update? " << endl << endl;
        manager.manageMaintenanceForStaff(option);
        cout << endl;
        displayMaintenanceRequestMenu(user_ID);
    } else if (option == 5) {
        cout << "Returning to Main Menu" << endl << endl;
        displayMainMenu(user_ID);
    } else if (option == 6) {
        cout << endl << endl;
        logout();
    } else {
        cout << "Please enter a number 1 through 6." << endl << endl;
        cin.clear();
        cin.ignore();
        displayMaintenanceRequestMenu(user_ID);
    }
}

//-------------------------------------------------------------------------------------------

void StaffUI::displayNotifications(int user_ID) {

    // Display Notifications features for staff
    cout << "Notifications\n";
    cout << "--------------------------\n";
    cout << "[1] View Notifications\n";
    cout << "[2] Create Notification\n";
    cout << "[3] Edit Notification\n";
    cout << "[4] Delete Notification\n";
    cout << "[5] Submit Notification\n";
    cout << "[6] Return to Staff Menu\n";
    cout << "[7] Logout\n";
    cout << "\nEnter a number 1 through 7: ";


    // Read in staff option
    int option = -1;
    cin >> option;
    cout << endl << endl;


    // [1] View Notifications
    if (option == 1) {
        ManageNotifications::manageNotifications(user_ID, option, "NULL", "NULL", "NULL");
        displayNotifications(user_ID);


    } // [2] Create Notifications
    else if (option == 2) {
        string title, content;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the title:\n";
        getline(cin, title);
        cout << "\nEnter the message you want to post. Enter '~' and press enter when done:\n" ;
        getline(cin, content, '~');

        ManageNotifications::manageNotifications(user_ID, option, "true", title, content);
        displayNotifications(user_ID);



    } // [3] Edit Notifications
    else if (option == 3) {
        ManageNotifications::manageNotifications(user_ID, option, "NULL", "NULL", "NULL");
        displayNotifications(user_ID);

    } // [4] Delete Notifications
    else if (option == 4) {
        ManageNotifications::manageNotifications(user_ID, option, "NULL", "NULL", "NULL");
        displayNotifications(user_ID);

    } // [5] Submit Notifications
    else if (option == 5) {
        ManageNotifications::manageNotifications(user_ID, option, "NULL", "NULL", "NULL");
        displayNotifications(user_ID);

    } // [6] Return to Staff Menu
    else if (option == 6) {
        cout << "Returning to Staff Menu\n\n";
        displayMainMenu(user_ID);

    } // [7] Return to General UI
    else if (option == 7) {
        logout();

    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number 1 through 7. \n\n";
        displayRentMenu(user_ID);
    }
}

//-------------------------------------------------------------------------------------------

void StaffUI::displayLease(int user_ID) {
    cout << "This is where you will view leases." << endl << endl;

    Staff staff(user_ID);


    cout << "Lease Editor" << endl;
    cout << "--------------------------" << endl;
    cout << "[1] Modify Tenant's Lease" << endl;
    cout << "[2] Return To Main menu" << endl;
    cout << "[3] Logout" << endl << endl;
    cout << "Enter a number 1 through 3: ";

    int option = 0;
    cin >> option;
    cout << endl;

    ManageLease manager;

    if (option == 1) {
        cout << "Here is a list of all Maintenance Requests: " << endl << endl;
        manager.manageLeaseForStaff(option);
        cout << endl;
        displayLease(staff.getUserID());

    } else if (option == 2) {
        cout << "Returning to Main Menu" << endl << endl;
        displayMainMenu(staff.getUserID());
    } else if (option == 3) {
        cout << endl << endl;
        logout();
    } else {
        cout << "Please enter a number 1 through 3." << endl << endl;
        cin.clear();
        cin.ignore();
        displayLease(staff.getUserID());
    }
}

//-------------------------------------------------------------------------------------------

void StaffUI::viewApplications(int user_ID) {
    cout << "This is where you will view applications." << endl << endl;
    Staff staff(user_ID);

    viewApplications(staff.getUserID());
}

//-------------------------------------------------------------------------------------------

void StaffUI::logout() {
    cout << "You have successfully logged out." << endl << endl;

    GeneralUI::displayGeneralUI();
}