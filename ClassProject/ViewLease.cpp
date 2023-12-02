#include "ViewLease.h"

void ViewLease::displayLeaseForTenant(int id) {

    fstream leaseFile;

    leaseFile.open("LeaseRecords.csv", ios::in);

    vector<string> row;
    string line, data;


    while (getline(leaseFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (row[0] == to_string(id)) {
            cout << "Tenant's Name: " << row[1] << endl;
            cout << "Apartment Number: " << row[6] << endl;
            cout << "Rent: $" << row[7] << endl;
            cout << "Move-In Date: " << row[3] << endl;
            cout << "Move-Out Date: " << row[4] << endl;
            cout << "Date Last Modified: " << row[5] << endl << endl;
        }

    }
    leaseFile.close();

}

vector<string> ViewLease::modifyLease()
{
    fstream leaseFile;

    leaseFile.open("LeaseRecords.csv", ios::in);

    vector<string> row;
    vector<string> referenceNum;
    vector<string> updatedLease;
    char response;
    string line, data, newMoveOut, newRent;
    int refNum = 0, count = 0, choice = -1;

    cout << "Below are the list of tenants." << endl << endl;

    while (getline(leaseFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        cout << "[" << count + 1 << "]" << endl;
        cout << "\tTenant's Name: " << row[1] << endl;
        cout << "\tApartment Number: " << row[6] << endl;
        cout << "\tRent: $" << row[7] << endl;
        cout << "\tMove-In Date: " << row[3] << endl;
        cout << "\tMove-Out Date: " << row[4] << endl;
        cout << "\tDate Last Modified: " << row[5] << endl << endl;
        referenceNum.push_back(row[2]);
        count++;

    }
    leaseFile.close();

    do {
        cout << "Which tenant's lease would you like to update? Choose an option from [1] - ";
        cout << "[" << referenceNum.size() << "]: ";
        cin >> choice;


        while (choice < 1 || choice > referenceNum.size()) {
            cin.clear();
            cin.ignore();
            cout << endl;
            cout << "Invalid option. Please choose an option from [1] -" << " [" << referenceNum.size() << "]: ";
            cin >> choice;
        }

        cout << "You chose the following lease to update:  " << endl << endl;

        leaseFile.open("LeaseRecords.csv", ios::in);
        while (getline(leaseFile, line)) {
            row.clear();
            stringstream s(line);

            while (getline(s, data, ',')) {
                row.push_back(data);
            }

            if (referenceNum[choice - 1] == row[2]) {
                cout << "Tenant's Name: " << row[1] << endl;
                cout << "\tApartment Number: " << row[6] << endl;
                cout << "\tRent: $" << row[7] << endl;
                cout << "\tMove-In Date: " << row[3] << endl;
                cout << "\tMove-Out Date: " << row[4] << endl;
                cout << "\tDate Last Modified: " << row[5] << endl << endl;
            }
        }
        leaseFile.close();

        cout << "Is this correct? (y/Y) ";

        cin >> response;

    } while (!(response == 'y' || response == 'Y'));

    updatedLease.push_back(referenceNum[choice - 1]);

    cout << "What would you like to change? " << endl;
    cout << "[1] Move-Out Date" << endl;
    cout << "[2] Rent" << endl;
    cout << "Enter a number 1 - 2";
    cin >> choice;

    while (choice < 1 || choice > 2) {
        cin.clear();
        cin.ignore();
        cout << endl;
        cout << "Invalid option. Please choose an option from [1] -" << " [2]";
        cin >> choice;
    }

    if (choice == 1) {
        cout << "Enter new Move-Out Date: ";
        cin.clear();
        cin.ignore();
        getline(cin, newMoveOut);
        row[4] = newMoveOut;
    } else if (choice == 2) {
        cout << "Enter new Rent: ";
        cin.clear();
        cin.ignore();
        getline(cin, newRent);
        row[7] = newRent;
    }

    row[8] = "Welcome To UHD Aparments.  You are subject to our rules and regulations. Your move in date is "
        + row[3] + " and your move out date is " + row[4] + ". Your monthly rent is $" + row[7] + ".";

    updatedLease.push_back(row[4]);
    updatedLease.push_back(row[7]);
    updatedLease.push_back(row[8]);

    return updatedLease;
}