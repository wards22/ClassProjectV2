/* Prologue
 * Name: General UI Class
 * Description: The implementation of the General UI Class
 * Contributors: Scott Ward
 * Date created: Nov 27 2023
 * Date last modified: Dec 3 2023
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#include "GeneralUI.h"
#include "StaffUI.h"
#include "TenantUI.h"
#include "Staff.h"
#include "Tenant.h"
#include "ViewApartmentInfo.h"
#include "ViewApplication.h"

void GeneralUI::displayGeneralUI() {

    int userID = 0;
    int getch();
    string username, password, userType;

    cout << "Welcome to UHD Apartments!" << endl;
    cout << "--------------------------" << endl;
    cout << "[1] User Login" << endl;
    cout << "[2] View Apartment Information" << endl;
    cout << "[3] Quit" << endl << endl;
    cout << "Please make a selection by entering a number 1 through 3: ";

    int option = 0;
    cin >> option;
    cout << endl;
    if (option == 1) {
        cout << endl;
        cout << "Enter your username and password to access you account." << endl;
        cin.ignore();

        do {
            cout << "Username: ";
            cin.clear();
            getline(cin, username);
            cout << "\nPassword: ";
            cin.clear();
            getline(cin, password);
        } while (!validateUser(username, password));
        userID = getUserID(username);
        userType = getUserType(userID);
        if (userType == "Staff") {
            Staff staff(userID);
            StaffUI::displayMainMenu(staff.getUserID());
        }
        else if (userType == "Tenant") {
            Tenant tenant(userID);
            TenantUI::displayTenantMenu(tenant.getUserID());
        }
    }
    else if (option == 2) {
        viewApartmentInfo();
    }
    else if (option == 3) {
        cout << "Thank you for visiting UHD Apartments!!" << endl;
        exit(0);
    }
    else {
        cout << "Please enter a number 1 through 3." << endl << endl;
        cin.clear();
        cin.ignore();
        displayGeneralUI();
    }
}

bool GeneralUI::validateUser(string username, string password) {

    fstream inputFile;
    inputFile.open("UserRecords.csv", ios::in);

    bool found = false;
    string user_name, line, data, temp;
    char choice;
    vector<string> row;

    while (getline(inputFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (username == row[1] && password == row[2]) {
            found = true;
            cout << "\nLogin Successful." << endl;
            inputFile.close();
            break;
        }
    }

    if (!found) {
        inputFile.close();
        cerr << "\nLogin failed, do you wish to try again?. (Y/y) ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {

            cin.clear();
            cin.ignore();
            return false;
        } else {
            cout << endl;
            cout << "Returning you to the main menu. " << endl << endl;
            displayGeneralUI();
        }
    }

    return true;
}

int GeneralUI::getUserID(string username) {
    //used to create staff/tenant object and direct towards correct menus

    fstream inputFile;
    inputFile.open("UserRecords.csv", ios::in);

    int user_ID = 0;
    string user_name, line, data, temp;
    vector<string> row;

    while (getline(inputFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (username == row[1]) {
            user_ID = stoi(row[0]);
            inputFile.close();
            break;
        }
    }

    return user_ID;
}

string GeneralUI::getUserType(int userID) {
    //used to create staff/tenant object and direct towards correct menus

    fstream inputFile;
    inputFile.open("UserRecords.csv", ios::in);

    int user_ID_From_File;
    string user_name, line, data, user_Type;
    vector<string> row;

    while (getline(inputFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        user_ID_From_File = stoi(row[0]);

        if (userID == user_ID_From_File) {
            user_Type = row[3];
            inputFile.close();
            break;
        }
    }

    return user_Type;
}

void GeneralUI::viewApartmentInfo() {
    
    cout << "Apartment Information" << endl;
    cout << "--------------------------" << endl;
    cout << "[1] View General Floor Plans" << endl;
    cout << "[2] View Vacant Apartments" << endl;
    cout << "[3] Fill Out An Application" << endl;
    cout << "[4] View Apartment Complex Information" << endl;
    cout << "[5] Return to Main Menu" << endl;
    cout << "[6] Quit" << endl << endl;
    cout << "Please make a selection by entering a number 1 through 6: ";

    int option = 0;
    cin >> option;
    cout << endl;

    if (option == 1) {

        cout << endl;
        cout << "Here are the available floor plans" << endl << endl;
        ViewApartmentInfo::displayFloorPlans();
        cout << endl;
        viewApartmentInfo();
    }
    else if (option == 2) {
        cout << endl;
        cout << "Here are the list of Vacant Apartments." << endl << endl;
        ViewApartmentInfo::displayVacantApartments();
        cout << endl;
        viewApartmentInfo();
    }
    else if (option == 3) {
        cout << endl;
        cout << "Enter your information to fill out an application." << endl << endl;
        ViewApplicationInfo::submitApplication();
        cout << endl;
        viewApartmentInfo();
    }
    else if (option == 4) {
        cout << endl;
        ViewApartmentInfo::displayApartmentComplexInfo();
        cout << endl;
        viewApartmentInfo();
    }
    else if (option == 5) {
        cout << "Returning To Main Menu" << endl;
        displayGeneralUI();
    }
    else if (option == 6) {
        cout << "Thank you for visiting UHD Apartments!!" << endl << endl;
        exit(0);
    }
    else {
        cout << "Please enter a number 1 through 6." << endl << endl;
        cin.clear();
        cin.ignore();
        displayGeneralUI();
    }
}
