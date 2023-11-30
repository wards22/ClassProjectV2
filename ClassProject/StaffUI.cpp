#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

#include "StaffUI.h"
#include "Staff.h"
#include "Tenant.h"
#include "GeneralUI.h"

void StaffUI::displayMainMenu(int user_ID) {
    Staff staff(user_ID);
    int choice = 0;

    cout << "Main Menu" << endl;
    cout << "--------------------------" << endl;
    cout << "[1] Account" << endl;
    cout << "[2] Tenant Info" << endl;
    cout << "[3] Apartment Info" << endl;
    cout << "[4] Tenant Rent" << endl;
    cout << "[5] Maintenance Requests" << endl;
    cout << "[6] Applications" << endl;
    cout << "[7] Lease Editor" << endl;
    cout << "[8] Notifications" << endl;
    cout << "[9] Logout" << endl << endl;
    cout << "Enter a number 1 through 9: ";

    cin >> choice;
    cout << endl;

    if (choice == 1) {
        displayStaffAccountMenu(staff.getUserID());
    }
    else if (choice == 2) {
        displayTenantInfoMenu();
    }
    else if (choice == 3) {
        displayApartmentInfoMenu();
    }
    else if (choice == 4) {
        displayRentMenu();
    }
    else if (choice == 5) {
        displayMaintenanceRequestMenu();
    }
    else if (choice == 6) {
        viewApplications();
    }
    else if (choice == 7) {
        displayLease();
    }
    else if (choice == 8) {
        displayNotifications();
    }
    else if (choice == 9) {
        cout << endl << endl;
        logout();
    }
    else {
        cout << "Please enter a number 1 through 7." << endl << endl;
        displayMainMenu(staff.getUserID());
    }
}

void StaffUI::displayStaffAccountMenu(int user_ID) {
    
    Staff staff(user_ID);

    
    cout << staff.getName() << "'s Account" << endl;
    cout << "--------------------------" << endl;
    // Have view account information as option 
    // or automatically display account info?
    cout << "[1] View Account Information\n";
    cout << "[2] Change Username" << endl;
    cout << "[3] Change Password" << endl;
    cout << "[4] Change Phone Number" << endl;
    cout << "[5] Change Email" << endl;
    cout << "[6] Return to Main Menu" << endl;
    cout << "[7] Logout" << endl;
    cout << "\nEnter a number 1 through 7: ";

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

        cout << "Your username has been changed successfully\n\n";
        displayStaffAccountMenu(staff.getUserID());

        // [3] Change Password
    }
    else if (option == 3) {
        string password;
        cout << "Enter your new password: ";
        cin.ignore();
        cin.clear();
        getline(cin, password);

        // Input validation to be added later

        manager.manageStaff(option, staff.getUserID(), password);

        cout << "Your password has been changed successfully\n\n";
        displayStaffAccountMenu(staff.getUserID());

        // [4] Change Phone Number
    }
    else if (option == 4) {
        string phoneNum;
        cout << "Enter your new phone number: ";
        cin.ignore();
        cin.clear();
        getline(cin, phoneNum);

        // Input validation to be added later

        manager.manageStaff(option, staff.getUserID(), phoneNum);

        cout << "Your phone number has been changed successfully\n\n";
        displayStaffAccountMenu(staff.getUserID());

        // [5] Change Email
    }
    else if (option == 5) {
        string email;
        cout << "Enter your new email: ";
        cin.ignore();
        cin.clear();
        getline(cin, email);

        // Input validation to be added later

        manager.manageStaff(option, staff.getUserID(), email);

        cout << "Your email has been changed successfully\n\n";
        displayStaffAccountMenu(staff.getUserID());

        // [6] Return to Main Menu
    }
    else if (option == 6) {
        cout << "Returning to Main Menu\n\n";
        displayMainMenu(staff.getUserID());

        // [7] Exit
    }
    else if (option == 7) {
        cout << endl << endl;
        logout();

    }
    else {
        cout << "Please enter a number 1 through 7. \n\n";
        displayStaffAccountMenu(staff.getUserID());
    }
}


void StaffUI::displayTenantInfoMenu() {
    cout << "This is where you will view tenant info." << endl << endl;
}

void StaffUI::displayApartmentInfoMenu() {
    cout << "This is where you will view apartment info." << endl << endl;
}

void StaffUI::displayRentMenu() {
    cout << "This is where you will view rent operations." << endl << endl;
}

void StaffUI::displayMaintenanceRequestMenu() {
    cout << "This is where you will view maintenance requests." << endl << endl;
}

void StaffUI::displayNotifications() {
    cout << "This is where you will view notifications." << endl << endl;
}

void StaffUI::displayLease() {
    cout << "This is where you will view leases." << endl << endl;
}

void StaffUI::viewApplications() {
    cout << "This is where you will view applications." << endl << endl;
}

void StaffUI::logout() {
    cout << "You have successfully logged out." << endl << endl;

    GeneralUI::displayGeneralUI();
}
