#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>       // For delay after display 
#include <thread>       // For delay after display

using namespace std;
using namespace chrono;
using namespace this_thread;

#include "StaffUI.h"
#include "Staff.h"
#include "Tenant.h"
#include "GeneralUI.h"
#include "ManageStaff.h"
#include "ManageTenantAccount.h"
#include "ManageMaintenance.h"
#include "ManageLease.h"
#include "ManageRent.h"
#include "ViewStaffInfo.h"


void StaffUI::displayMainMenu(int user_ID) {
    Staff staff(user_ID);
    int choice = 0;

    cout << "Main Menu - Staff" << endl;
    cout << "--------------------------" << endl;
    cout << "[1] Manage Your Account" << endl;
    cout << "[2] Tenant Info" << endl;
    cout << "[3] Apartment Info" << endl;
    cout << "[4] Tenant Rent" << endl;
    cout << "[5] Maintenance Requests" << endl;
    cout << "[6] Applications" << endl;
    cout << "[7] Modify Lease" << endl;
    cout << "[8] Notifications" << endl;
    cout << "[9] View Staffing Information" << endl;
    cout << "[10] Logout" << endl << endl;
    cout << "Enter a number 1 through 9: ";

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
        cout << "Please enter a number 1 through 7." << endl << endl;
        cin.clear();
        cin.ignore();
        displayMainMenu(staff.getUserID());
    }
}

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

void StaffUI::displayTenantInfoMenu(int user_ID) {
    cout << "This is where you will view tenant info." << endl << endl;
    Staff staff(user_ID);
    int tenantID;

    cout << "Tenant Information Window" << endl;
    cout << "--------------------------" << endl;
    cout << "[1] View Tenants" << endl;
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

    // Create object to access ManageStaff class
    ManageTenantAccount manager;

    // [1] View Tenant Account Information
    if (option == 1) {
        cout << "Here is the list of tenants: " << endl << endl;
        manager.manageTenantAccountForStaff(option, 0, "null");
        cout << endl;
        displayTenantInfoMenu(staff.getUserID());

    }
    // [2] Change Tenant Username
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

        manager.manageTenantAccountForStaff(option, tenantID, username);

        cout << "The tenant's username has been changed successfully" << endl << endl;
        displayTenantInfoMenu(staff.getUserID());

        // [3] Change Tenant Password
    } else if (option == 3) {
        string password;
        cout << "Enter the User ID of the tenant whose password you want to change: ";
        cin >> tenantID;
        cout << endl;
        cout << "Enter the tenant's new password: ";
        cin.ignore();
        cin.clear();
        getline(cin, password);


        manager.manageTenantAccountForStaff(option, tenantID, password);

        cout << "The tenant's password has been changed successfully" << endl << endl;
        displayTenantInfoMenu(staff.getUserID());

        // [4] Change Tenant Phone Number
    } else if (option == 4) {
        string phoneNum;
        cout << "Enter the User ID of the tenant whose phone number you want to change: ";
        cin >> tenantID;
        cout << endl;
        cout << "Enter the tenant's new phone number: ";
        cin.ignore();
        cin.clear();
        getline(cin, phoneNum);

        manager.manageTenantAccountForStaff(option, tenantID, phoneNum);

        cout << "The tenant's phone number has been changed successfully" << endl << endl;
        displayTenantInfoMenu(staff.getUserID());

        // [5] Change Tenant Email
    } else if (option == 5) {
        string email;
        cout << "Enter the User ID of the tenant whose username you want to change: ";
        cin >> tenantID;
        cout << endl;
        cout << "Enter the tenant's new email: ";
        cin.ignore();
        cin.clear();
        getline(cin, email);

        manager.manageTenantAccountForStaff(option, tenantID, email);

        cout << "The tenant's email has been changed successfully" << endl << endl;
        displayTenantInfoMenu(staff.getUserID());

        // [6] Return to Main Menu
    } else if (option == 6) {
        cout << "Returning to Main Menu\n\n";
        displayMainMenu(staff.getUserID());

        // [7] Exit
    } else if (option == 7) {
        cout << endl << endl;
        logout();

    } else {
        cout << "Please enter a number 1 through 7." << endl << endl;
        cin.clear();
        cin.ignore();
        displayTenantInfoMenu(staff.getUserID());
    }

}

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
    cout << "This is where you will view rent operations." << endl << endl;
    Staff staff(user_ID);

    // Display Rent features for staff
    cout << "Tenant Rent Information\n";
    cout << "--------------------------\n";
    cout << "[1] View Rent Receipts\n";
    cout << "[2] Create Rent Receipt\n";
    cout << "[3] Edit Rent Receipt\n";
    cout << "[4] Delete Rent Receipt\n";
    cout << "[5] Submit Rent Receipt\n";
    cout << "[6] Return to Staff Menu\n";
    cout << "[7] Return to Start Menu\n";
    cout << "[8] Exit\n";
    cout << "\nEnter a number 1 through 8: ";


    // Read in tenant option
    int option = -1;
    cin >> option;
    cout << endl;


    // [1] View Rent Receipts
    if (option == 1) {
        ManageRent::manageRentForStaff(NULL, option);
        sleep_for(seconds(1));
        displayRentMenu(staff.getUserID());

    } // [2] Create Rent Receipt
    else if (option == 2) {
        int userid;
        cout << "Enter the user ID of the tenant you want to create a rent receipt for: ";
        cin >> userid;    

        ManageRent::manageRentForStaff(userid, option);
    }/*
    } // [3] Edit Rent Receipt
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
    */
    
    displayRentMenu(staff.getUserID());
}

//-------------------------------------------------------------------------------------------

void StaffUI::displayMaintenanceRequestMenu(int user_ID) {
    cout << "This is where you will view maintenance requests." << endl << endl;

    Staff staff(user_ID);


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
        displayMaintenanceRequestMenu(staff.getUserID());

    } else if (option == 2) {
        cout << "Here is a list of all Open Maintenance Requests: " << endl << endl;
        manager.manageMaintenanceForStaff(option);
        cout << endl;
        displayMaintenanceRequestMenu(staff.getUserID());
    } else if (option == 3) {

        cout << "Here is a list of all Closed Maintenance Requests: " << endl << endl;
        manager.manageMaintenanceForStaff(option);
        cout << endl;
        displayMaintenanceRequestMenu(staff.getUserID());
    } else if (option == 4) {

        cout << "Which Maintenance Requests would you like to update? " << endl << endl;
        manager.manageMaintenanceForStaff(option);
        cout << endl;
        displayMaintenanceRequestMenu(staff.getUserID());
    } else if (option == 5) {
        cout << "Returning to Main Menu" << endl << endl;
        displayMainMenu(staff.getUserID());
    } else if (option == 6) {
        cout << endl << endl;
        logout();
    } else {
        cout << "Please enter a number 1 through 6." << endl << endl;
        cin.clear();
        cin.ignore();
        displayMaintenanceRequestMenu(staff.getUserID());
    }
}

void StaffUI::displayNotifications(int user_ID) {
    cout << "This is where you will view notifications." << endl << endl;
    Staff staff(user_ID);

    displayNotifications(staff.getUserID());
}

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

void StaffUI::viewApplications(int user_ID) {
    cout << "This is where you will view applications." << endl << endl;
    Staff staff(user_ID);

    viewApplications(staff.getUserID());
}

void StaffUI::logout() {
    cout << "You have successfully logged out." << endl << endl;

    GeneralUI::displayGeneralUI();
}