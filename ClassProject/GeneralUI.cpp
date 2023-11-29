/* Prologue
 * Name: General UI Class
 * Description: The implementation of the General UI Class
 * Contributors: Scott Ward
 * Date created: Nov 27 2023
 * Date last modified: Nov 29 2023
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

void GeneralUI::displayGeneralUI() {

    int choice = 0, userID = 0;
    int getch();
    string username, password, userType;

    cout << "Welcome to UHD Apartments!" << endl;
    cout << "--------------------------" << endl;
    cout << "[1] User Login" << endl;
    cout << "[2] View Floor Plans" << endl;
    cout << "[3] Fill Out An Application" << endl;
    cout << "[4] View Apartment Complex Information" << endl;
    cout << "[5] Quit" << endl << endl;
    cout << "Please make a selection by entering a number 1 through 5: ";

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
        else if (userType == "Tenant")
            Tenant tenant;
            TenantUI::displayMainMenu();
    }
    else if (option == 2) {
        cout << endl;
        cout << "Here are the available floor plans" << endl << endl;
        viewFloorPlans();
        cout << "Press any key to return to the main menu." << endl << endl;
        cin.clear();
        cin.ignore();
        getch();
        displayGeneralUI();
    }
    else if (option == 3) {
        cout << endl;
        cout << "Enter your information to fill out an application." << endl << endl;
        viewApplication();
        cout << endl;
        cout << "Press any key to return to the main menu." << endl << endl;
        cin.clear();
        cin.ignore();
        getch();
        displayGeneralUI();
    }
    else if (option == 4) {
        cout << endl;
        cout << "Apartment Information: Stuff goes here." << endl;
        cout << "Press any key to return to the main menu." << endl << endl;
        cin.clear();
        cin.ignore();
        getch();
        displayGeneralUI();
    }
    else if (option == 5) {
        cout << "Thank you for visitng UHD Apartments. Have a nice day!" << endl;
    }
    else {
        cout << "Please enter a number 1 through 5." << endl << endl;
        displayGeneralUI();
    }
}

    /*
    do {
        cout << "Welcome to UHD Apartments!\n";
        cout << "--------------------------\n";
        cout << "[1] User Login" << endl;
        cout << "[2] View Floor Plans" << endl;
        cout << "[3] Fill Out An Application" << endl;
        cout << "[4] View Apartment Complex Information" << endl;
        cout << "[5] Quit" << endl << endl;
        cout << "Please make a selection by entering a number 1 through 5: ";

        cin >> choice;
        switch (choice) {
        case 1:
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
                
                StaffUI::displayMainMenu(staff.getUserID());
            }
            else if (userType == "Tenant")
                TenantUI::displayMainMenu();

            break;
        case 2:
            cout << endl;
            cout << "Here are the available floor plans" << endl << endl;
            viewFloorPlans();
            cout << "Press any key to return to the main menu." << endl << endl;
            cin.clear();
            cin.ignore();
            getch();
            break;
        case 3:
            cout << endl;
            cout << "Enter your information to fill out an application." << endl << endl;
            viewApplication();
            cout << endl;
            cout << "Press any key to return to the main menu." << endl << endl;
            cin.clear();
            cin.ignore();
            getch();
            break;
        case 4:
            cout << endl;
            cout << "Apartment Information: Stuff goes here." << endl;
            cout << "Press any key to return to the main menu." << endl << endl;
            cin.clear();
            cin.ignore();
            getch();
            break;
        case 5:
            cout << "Thank you for visitng UHD Apartments. Have a nice day!" << endl;
            break;
        default:
            cerr << "Invalid selection, please choose again." << endl << endl;
            cin.clear();
            cin.ignore();
        }
    } while (choice != 5);
};

*/

/*
* We might not need this function. I can't figure
* out a clean way to pull the info to create an staff/tenant object with both this
* and the validate user function.
void GeneralUI::displayUserLogin() {

    string username, password;

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
}
*/
bool GeneralUI::validateUser(string username, string password) {

    fstream inputFile;
    inputFile.open("UserRecords.csv", ios::in);

    bool found = false;
    string user_name, line, data, temp;
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
        cerr << "\nLogin failed, please try again." << endl;
        inputFile.close();
        return false;
    }

    return true;
}

int GeneralUI::getUserID(string username) {
    //used to create staff/tenant object and direct towards correct menus

    fstream inputFile;
    inputFile.open("UserRecords.csv", ios::in);

    int user_ID;
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

void GeneralUI::viewFloorPlans() {
    //floor plan class goes here
}

void GeneralUI::viewApplication() {
    //application class viewing goes here
}

