/* Prologue
 * Name: Display Maintenance Request Information
 * Description: Implementation file for Display Maintenance Request
 * Contributors: Scott Ward
 * Date created: Dec 1 2023
 * Date last modified: Dec 1 2023
*/

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

#include "DisplayMaintenanceRequestInfo.h"

void DisplayMaintenanceRequestInfo::displayMaintenanceForTenant(int uid) {
    fstream maintenanceFile;

    maintenanceFile.open("MaintenanceRecords.csv", ios::in);

    vector<string> row;
    int user_id;
    string line, data, temp;

    while (getline(maintenanceFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (row[0] == to_string(uid)) {
            cout << "Reference Number: " << row[2] << endl;
            cout << "Date Submitted: " << row[3] << endl;
            cout << "Description: " << row[4] << endl;
            cout << "Status: " << row[5] << endl << endl;
        }
    }

    maintenanceFile.close();
}

vector<string> DisplayMaintenanceRequestInfo::createMaintenanceRequest(int uid) {
    
    fstream maintenanceFile;
    vector<string> row;
    vector<string> oldReferenceNum;
    vector<string> newMaintenanceRequest;
    string line, data, dateSubmitted, description, tenantName, status = "Pending Review";
    int size, newReferenceNum;

    cout << "Please enter a description of what is wrong: ";
    cin.clear();
    cin.ignore();
    getline(cin, description);

    maintenanceFile.open("MaintenanceRecords.csv", ios::in);
    while (getline(maintenanceFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }
        
        oldReferenceNum.push_back(row[2]);

        if (row[0] == to_string(uid))
            tenantName = row[1];
    }
    maintenanceFile.close();

    size = oldReferenceNum.size();

    newReferenceNum = stoi(oldReferenceNum[size - 1]) + 1;

    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);

    dateSubmitted = to_string(1 + newtime.tm_mon) + "/" + to_string(newtime.tm_mday) + "/" + to_string(1900 + newtime.tm_year);
   
    newMaintenanceRequest.push_back(to_string(uid));
    newMaintenanceRequest.push_back(tenantName);
    newMaintenanceRequest.push_back(to_string(newReferenceNum));
    newMaintenanceRequest.push_back(dateSubmitted);
    newMaintenanceRequest.push_back(description);
    newMaintenanceRequest.push_back(status);

    return newMaintenanceRequest;
};

vector<string> DisplayMaintenanceRequestInfo::editMaintenanceRequest(int uid) {

    fstream maintenanceFile;

    maintenanceFile.open("MaintenanceRecords.csv", ios::in);

    vector<string> row;
    vector<string> referenceNum;
    vector<string> updatedStatus;
    char response;
    string line, data, newStatus;
    int refNum = 0, count = 0, choice = -1;

    cout << "What maintenance request do you want to cancel?" << endl << endl;

    while (getline(maintenanceFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (row[0] == to_string(uid) && !(row[5] == "Completed" || row[5] == "Denied" || row[5] == "Canceled")) {
            cout << "[" << count + 1 << "]" << endl;
            cout << "\tReference Number: " << row[2] << endl;
            cout << "\tDate Submitted: " << row[3] << endl;
            cout << "\tDescription: " << row[4] << endl;
            cout << "\tStatus: " << row[5] << endl << endl;
            referenceNum.push_back(row[2]);
            count++;
        }
    }
    maintenanceFile.close();

    do {
        cout << "Which maintenance request would you like to cancel? Choose an option from [1] - ";
        cout << "[" << referenceNum.size() << "]: ";
        cin >> choice;


        while (choice < 1 || choice > referenceNum.size()) {
            cin.clear();
            cin.ignore();
            cout << endl;
            cout << "Invalid option. Please choose an option from [1] -" << " [" << referenceNum.size() << "]: ";
            cin >> choice;
        }

        cout << "You chose the following maintenance request to cancel:  " << endl << endl;

        maintenanceFile.open("MaintenanceRecords.csv", ios::in);
        while (getline(maintenanceFile, line)) {
            row.clear();
            stringstream s(line);

            while (getline(s, data, ',')) {
                row.push_back(data);
            }

            if (referenceNum[choice - 1] == row[2]) {
                cout << "\tReference Number: " << row[2] << endl;
                cout << "\tDate Submitted: " << row[3] << endl;
                cout << "\tDescription: " << row[4] << endl;
                cout << "\tStatus: " << row[5] << endl << endl;
            }
        }
        maintenanceFile.close();

        cout << "Do you wish to cancel this request? (y/Y) ";

        cin >> response;

    } while (!(response == 'y' || response == 'Y'));

    updatedStatus.push_back(referenceNum[choice - 1]);

    updatedStatus.push_back("Canceled");

    return updatedStatus;

};

void DisplayMaintenanceRequestInfo::displayAllMaintenanceForStaff() {
    fstream maintenanceFile;

    maintenanceFile.open("MaintenanceRecords.csv", ios::in);

    vector<string> row;
    string line, data, temp;

    while (getline(maintenanceFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }
        cout << "Tenant Name: " << row[1] << endl;
        cout << "\tReference Number: " << row[2] << endl;
        cout << "\tDate Submitted: " << row[3] << endl;
        cout << "\tDescription: " << row[4] << endl;
        cout << "\tStatus: " << row[5] << endl << endl;
    }

    maintenanceFile.close();
}

void DisplayMaintenanceRequestInfo::displayOpenMaintenceForStaff() {
    fstream maintenanceFile;

    maintenanceFile.open("MaintenanceRecords.csv", ios::in);

    vector<string> row;
    string line, data, temp;

    while (getline(maintenanceFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (row[5] == "In Progress" || row[5] == "Approved" || row[5] == "Pending Review") {
            cout << "Tenant Name: " << row[1] << endl;
            cout << "\tReference Number: " << row[2] << endl;
            cout << "\tDate Submitted: " << row[3] << endl;
            cout << "\tDescription: " << row[4] << endl;
            cout << "\tStatus: " << row[5] << endl << endl;
        }
    }

    maintenanceFile.close();
}

void DisplayMaintenanceRequestInfo::displayClosedMaintenanceForStaff() {
    fstream maintenanceFile;

    maintenanceFile.open("MaintenanceRecords.csv", ios::in);

    vector<string> row;
    string line, data, temp;

    while (getline(maintenanceFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (row[5] == "Completed" || row[5] == "Denied" || row[5] == "Canceled") {
            cout << "Tenant Name: " << row[1] << endl;
            cout << "\tReference Number: " << row[2] << endl;
            cout << "\tDate Submitted: " << row[3] << endl;
            cout << "\tDescription: " << row[4] << endl;
            cout << "\tStatus: " << row[5] << endl << endl;
        }
    }

    maintenanceFile.close();
}

vector<string> DisplayMaintenanceRequestInfo::updateMaintenanceStatusForStaff() {

    fstream maintenanceFile;

    maintenanceFile.open("MaintenanceRecords.csv", ios::in);

    vector<string> row;
    vector<string> referenceNum;
    vector<string> updatedStatus;
    char response;
    string line, data, newStatus;
    int refNum = 0, count = 0, choice = -1;
    
    cout << "Below is the list of open maintenance requests." << endl << endl;

    while (getline(maintenanceFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (row[5] == "In Progress" || row[5] == "Approved" || row[5] == "Pending Review") {
            cout << "[" << count + 1 << "]" << endl;
            cout << "\tTenant Name: " << row[1] << endl;
            cout << "\tReference Number: " << row[2] << endl;
            cout << "\tDate Submitted: " << row[3] << endl;
            cout << "\tDescription: " << row[4] << endl;
            cout << "\tStatus: " << row[5] << endl << endl;
            referenceNum.push_back(row[2]);
            count++;
        }
    }
    maintenanceFile.close();

    do {
        cout << "Which maintenance request would you like to update? Choose an option from [1] - ";
        cout << "[" << referenceNum.size() << "]: ";
        cin >> choice;


        while (choice < 1 || choice > referenceNum.size()) {
            cin.clear();
            cin.ignore();
            cout << endl;
            cout << "Invalid option. Please choose an option from [1] -" << " [" << referenceNum.size() << "]: ";
            cin >> choice;
        }

        cout << "You chose the following maintenance request to update:  " << endl << endl;
        
        maintenanceFile.open("MaintenanceRecords.csv", ios::in);
        while (getline(maintenanceFile, line)) {
            row.clear();
            stringstream s(line);

            while (getline(s, data, ',')) {
                row.push_back(data);
            }

            if (referenceNum[choice - 1] == row[2]) {
                cout << "Tenant's Name: " << row[1] << endl;
                cout << "\tReference Number: " << row[2] << endl;
                cout << "\tDate Submitted: " << row[3] << endl;
                cout << "\tDescription: " << row[4] << endl;
                cout << "\tStatus: " << row[5] << endl << endl;
            }
        }
        maintenanceFile.close();

        cout << "Is this correct? (y/Y) ";
        
        cin >> response;

    } while (!(response == 'y' || response == 'Y'));

    updatedStatus.push_back(referenceNum[choice - 1]);

    cout << "Please choose the new status of the maintenance request: " << endl;
    cout << "[1] Approved" << endl;
    cout << "[2] Denied" << endl;
    cout << "[3] In Progress" << endl;
    cout << "[4] Completed" << endl;
    cin >> choice;

    while (choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore();
            cout << endl;
            cout << "Invalid option. Please choose an option from [1] -" << " [4]";
            cin >> choice;
    }

    if (choice == 1) {
        newStatus = "Approved";
    }
    else if (choice == 2) {
        newStatus = "Denied";
    }
    else if (choice == 3) {
        newStatus = "In Progress";
    }
    else if (choice == 4) {
        newStatus = "Completed";
    }

    updatedStatus.push_back(newStatus);

    return updatedStatus;
}
