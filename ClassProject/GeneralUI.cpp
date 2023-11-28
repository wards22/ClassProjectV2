/* Prologue
 * Name: General UI Class
 * Description: The implementation of the General UI Class
 * Contributors: Scott Ward
 * Date created: Nov 27 2023
 * Date last modified: Nov 27 2023
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#include "GeneralUI.h"

void GeneralUI::displayGeneralUI() {

    int choice = 0;
    int getch();

    cout << "Welcome to UHD Apartments! Please choose an option to continue." << endl;

    do {
        cout << "1. User Login\n2. View Floor Plans\n3. Fill Out An Application\n4. View Apartment Information\n5. Quit" << endl << endl;
        cout << "Please make a selection: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << endl;
            cout << "Please login with your username and password" << endl;
            displayUserLogin();
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

int GeneralUI::getUserType() {
    //may or may not be necessary
    //we may be able to create tenant or staff objects with this code
    //read from file
    //int userType = type; //reads from csv file and returns
                    // the user type (staff or tenant)

    int userType = 1;
    return userType;
}

void GeneralUI::viewFloorPlans() {
    //floor plan class goes here
}

void GeneralUI::viewApplication() {
    //application class viewing goes here
}

