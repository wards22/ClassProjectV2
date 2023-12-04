/* Prologue
 * Name: View Application Info Class
 * Description: Implementation of ViewApplication class
 * Contributors: Scott Ward
 * Date created: Dec 3 2023
 * Date last modified: Dec 3 2023
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

#include "Application.h"
#include "ViewApplication.h"
#include "ViewApartmentInfo.h"

void ViewApplicationInfo::submitApplication() {
    string name, phoneNumber, email, floorPlan;
    int year, month, day, floorPlanChoice;

    cout << "Welcome to the apartment application!" << endl;

    cout << "Please enter your name: ";
    cin.ignore();
    cin.clear();
    getline(cin, name);

    cout << "Please provide your phone number: ";
    cin >> phoneNumber;

    // Validate phone number length
    while (phoneNumber.length() != 10) {
        cout << "Invalid phone number length. Please enter a 10-digit number: ";
        cin >> phoneNumber;
    }

    cout << "Please enter your email address: ";
    cin >> email;

    bool dobValid = false;
    while (!dobValid) {
        cout << "Please enter your date of birth in the format MM/DD/YYYY: ";
        string dobInput;
        cin >> dobInput;

        // Extract month, day, and year from input string
        istringstream(dobInput.substr(0, 2)) >> month;
        istringstream(dobInput.substr(3, 2)) >> day;
        istringstream(dobInput.substr(6, 4)) >> year;

        // Create Application object and validate the date
        Application dob(name, email, phoneNumber, floorPlan, month, day, year);

        if (!dob.isValidDate()) {
            cout << "Invalid date of birth. Please try again: " << endl;
        }
        else {
            dobValid = true;
            if (!dob.isApplicantAdult()) 
                cout << "Sorry, only individuals that are 18 years of age and older can apply." << endl << endl;
            else {
                cout << "Here is the list of floor plans available: " << endl;
                ViewApartmentInfo::displayFloorPlans();
                cout << "What floor plan are you interested in?" << endl;
                cout << "[1] Floor Plan A" << endl;
                cout << "[2] Floor Plan B" << endl;
                cout << "[3] Floor Plan C" << endl;
                cout << "Please enter an option 1 - 3: ";
                cin >> floorPlanChoice;
                while (floorPlanChoice < 1 || floorPlanChoice > 3) {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid choice. Please enter an option 1 - 3: ";
                    cin >> floorPlanChoice;
                }
                if (floorPlanChoice == 1)
                    floorPlan = "A";
                else if (floorPlanChoice == 2)
                    floorPlan = "B";
                else
                    floorPlan = "C";
                cout << "Thank you for your application, " << name << "!" << endl;
                // Review of the application
                cout << "Here is a review of your application:" << endl;
                cout << "------------------------------------" << endl;
                cout << "Name: " << name << endl;
                cout << "Phone Number: " << phoneNumber << endl;
                cout << "Email Address: " << email << endl;
                cout << "Date of Birth: " << setw(2) << setfill('0') << month << "/" << setw(2) << day << "/" << setw(4) << year << endl;
                cout << "Floor Plan Requested: " << floorPlan << endl;
                dob.setFloorPlanRequested(floorPlan);
                dob.setStatus("Pending Review");
                dob.writeApplicationInfo();
            }
        }
    }
}

void ViewApplicationInfo::reviewAllApplications() {
    fstream applicationFile;

    applicationFile.open("Applications.csv", ios::in);

    vector<string> row;
    string line, data;

    while (getline(applicationFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }
        cout << "Applicant Name: " << row[0] << endl;
        cout << "\tEmail: " << row[1] << endl;
        cout << "\tPhone Number: " << row[2] << endl;
        cout << "\tRequested Floor Plan: " << row[3] << endl;
        cout << "\tDate Submitted: " << row[4] << endl;
        cout << "\tStatus: " << row[5] << endl << endl;
    }

    applicationFile.close();
}

void ViewApplicationInfo::reviewOpenApplications() {
    fstream applicationFile;

    applicationFile.open("Applications.csv", ios::in);

    vector<string> row;
    string line, data;

    while (getline(applicationFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (row[5] == "Pending Review") {
            cout << "Applicant Name: " << row[0] << endl;
            cout << "\tEmail: " << row[1] << endl;
            cout << "\tPhone Number: " << row[2] << endl;
            cout << "\tRequested Floor Plan: " << row[3] << endl;
            cout << "\tDate Submitted: " << row[4] << endl;
            cout << "\tStatus: " << row[5] << endl << endl;
        }
    }

    applicationFile.close();
}

void ViewApplicationInfo::reviewClosedApplications() {
    fstream applicationFile;

    applicationFile.open("Applications.csv", ios::in);

    vector<string> row;
    string line, data;

    while (getline(applicationFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (row[5] == "Approved" || row[5] == "Denied") {
            cout << "Applicant Name: " << row[0] << endl;
            cout << "\tEmail: " << row[1] << endl;
            cout << "\tPhone Number: " << row[2] << endl;
            cout << "\tRequested Floor Plan: " << row[3] << endl;
            cout << "\tDate Submitted: " << row[4] << endl;
            cout << "\tStatus: " << row[5] << endl << endl;
        }
    }

    applicationFile.close();
}

vector<string> ViewApplicationInfo::updateApplicationStatus() {
    fstream applicationFile;

    applicationFile.open("Applications.csv", ios::in);

    vector<string> row;
    vector<string> applicantEmail;
    vector<string> updatedStatus;
    char response;
    string line, data, newStatus;
    int count = 0, choice = -1;

    cout << "Below is the list of open Applications." << endl << endl;

    while (getline(applicationFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (row[5] == "Pending Review") {
            cout << "[" << count + 1 << "]" << endl;
            cout << "Applicant Name: " << row[0] << endl;
            cout << "\tEmail: " << row[1] << endl;
            cout << "\tPhone Number: " << row[2] << endl;
            cout << "\tRequested Floor Plan: " << row[3] << endl;
            cout << "\tDate Submitted: " << row[4] << endl;
            cout << "\tStatus: " << row[5] << endl << endl;
            applicantEmail.push_back(row[1]);
            count++;
        }
    }
    applicationFile.close();

    do {
        cout << "Which Application would you like to update? Choose an option from [1] - ";
        cout << "[" << applicantEmail.size() << "]: ";
        cin >> choice;


        while (choice < 1 || choice > applicantEmail.size()) {
            cin.clear();
            cin.ignore();
            cout << endl;
            cout << "Invalid option. Please choose an option from [1] -" << " [" << applicantEmail.size() << "]: ";
            cin >> choice;
        }

        cout << "You chose the following Application to update:  " << endl << endl;

        applicationFile.open("Applications.csv", ios::in);
        while (getline(applicationFile, line)) {
            row.clear();
            stringstream s(line);

            while (getline(s, data, ',')) {
                row.push_back(data);
            }

            if (applicantEmail[choice - 1] == row[1]) {
                cout << "Applicant Name: " << row[0] << endl;
                cout << "\tEmail: " << row[1] << endl;
                cout << "\tPhone Number: " << row[2] << endl;
                cout << "\tRequested Floor Plan: " << row[3] << endl;
                cout << "\tDate Submitted: " << row[4] << endl;
                cout << "\tStatus: " << row[5] << endl << endl;
            }
        }
        applicationFile.close();

        cout << "Is this correct? (y/Y) ";

        cin >> response;

    } while (!(response == 'y' || response == 'Y'));

    updatedStatus.push_back(applicantEmail[choice - 1]);

    cout << "Please choose the new status of the application: " << endl;
    cout << "[1] Approved" << endl;
    cout << "[2] Denied" << endl;
    cout << "Please choose an option from [1] - [2]: ";
    cin >> choice;

    while (choice < 1 || choice > 2) {
        cin.clear();
        cin.ignore();
        cout << endl;
        cout << "Invalid option. Please choose an option from [1] - [2]";
        cin >> choice;
    }

    if (choice == 1) {
        newStatus = "Approved";
    }
    else if (choice == 2) {
        newStatus = "Denied";
    }

    updatedStatus.push_back(newStatus);

    return updatedStatus;
}
