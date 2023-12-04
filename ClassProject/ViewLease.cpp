#include "ViewLease.h"
#include "Staff.h"


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

vector<string> ViewLease::createLease()
{
    vector<string> row;
    vector<string> referenceNum;
    vector<string> newLease;
    vector<string> applicantEmail;
    char response;
    string line, data, name, requestedFloorPlan, phoneNum, email;
    int choice = -1, count = 0;

    fstream applicationFile;
    applicationFile.open("Applications.csv", ios::in);

    while (getline(applicationFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (row[5] == "Approved") {
            cout << "[" << count + 1 << "]" << endl;
            cout << "\tApplicant Name: " << row[0] << endl;
            cout << "\tEmail: " << row[1] << endl;
            cout << "\tPhone Number: " << row[2] << endl;
            cout << "\tRequested Floor Plan: " << row[3] << endl;
            cout << "\tDate Submitted: " << row[4] << endl;
            cout << "\tStatus: " << row[5] << endl << endl;
            applicantEmail.push_back(row[1]);
        }
    }

    applicationFile.close();

    do {
        cout << "Which Applicant would you like to create a lease for? Choose an option from [1] - ";
        cout << "[" << applicantEmail.size() << "]: ";
        cin >> choice;


        while (choice < 1 || choice > applicantEmail.size()) {
            cin.clear();
            cin.ignore();
            cout << endl;
            cout << "Invalid option. Please choose an option from [1] -" << " [" << applicantEmail.size() << "]: ";
            cin >> choice;
        }

        cout << "You chose the following Applicant to create a lease for:  " << endl << endl;

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
                //get data for later use
                name = row[0];
                requestedFloorPlan = row[3];
                email = row[1];
                phoneNum = row[2];
            }
        }
        applicationFile.close();

        cout << "Is this correct? (y/Y): ";

        cin >> response;

    } while (!(response == 'y' || response == 'Y'));

    //removes approved applicant from applications record
    //and then create a record for them in user records

    applicationFile.open("Applications.csv", ios::in);
    fstream newApplicationFile;
    newApplicationFile.open("NewApplications.csv", ios::out);

    string newAppLine, newAppData;
    vector<string> newAppRow;
    while (getline(applicationFile, newAppLine)) {
        
        newAppRow.clear();
        stringstream s(newAppLine);


        while (getline(s, newAppData, ',')) {
            newAppRow.push_back(newAppData);
        }

        if (newAppRow[1] != email) {
            if (!applicationFile.eof()) {
                for (int i = 0; i < newAppRow.size(); i++) {
                    newApplicationFile << newAppRow[i] << ",";
                }
                newApplicationFile << newAppRow[newAppRow.size() - 1] << "\n";
            }
            if (applicationFile.eof())
                break;
        }
    }
    applicationFile.close();
    newApplicationFile.close();
    remove("Applications.csv");
    rename("NewApplications.csv", "Applications.csv");
    
    //generates new reference number for new lease
    fstream leaseFile;
    string leaseData, leaseLine;
    vector<string> oldReferenceNum;
    vector<string> leaseRow;
    leaseFile.open("LeaseRecords.csv", ios::in);
    while (getline(leaseFile, leaseLine)) {
        leaseRow.clear();
        stringstream s(leaseLine);

        while (getline(s, leaseData, ',')) {
            leaseRow.push_back(leaseData);
        }

        oldReferenceNum.push_back(leaseRow[2]);

    }
    leaseFile.close();

    int size = oldReferenceNum.size();

    int newReferenceNum = stoi(oldReferenceNum[size - 1]) + 1;

    //gets userID for lease
    fstream userFile;
    string userData, userLine;
    vector<string> oldUserID;
    vector<string> userRow;
    userFile.open("UserRecords.csv", ios::in);
    while (getline(userFile, userLine)) {
        userRow.clear();
        stringstream s(userLine);

        while (getline(s, userData, ',')) {
            userRow.push_back(userData);
        }

        oldUserID.push_back(userRow[0]);

    }
    userFile.close();

    size = oldUserID.size();

    int newUserID = stoi(oldUserID[size - 1]) + 1;

    //gets dates for lease
    string todaysDate, leaseExpirationDate;
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);

    todaysDate = to_string(1 + newtime.tm_mon) + "/" + to_string(newtime.tm_mday) + "/" + to_string(1900 + newtime.tm_year);
    leaseExpirationDate = to_string(1 + newtime.tm_mon) + "/" + to_string(newtime.tm_mday) 
        + "/" + to_string((1900 + newtime.tm_year) + 1);

    //generate apartment number
    fstream apartmentFile;
    string apartmentData, apartmentLine, newRent;
    vector<string> apartmentRow;
    apartmentFile.open("ApartmentRecords.csv", ios::in);
    while (getline(apartmentFile, apartmentLine)) {
        apartmentRow.clear();
        stringstream s(apartmentLine);

        while (getline(s, apartmentData, ',')) {
            apartmentRow.push_back(apartmentData);
        }

        if (apartmentRow[0] == requestedFloorPlan && apartmentRow[6] == "Y") {
            requestedFloorPlan += apartmentRow[1];
            newRent = apartmentRow[5];
        }

    }
    apartmentFile.close();

    //generate lease text
    string leaseText;
    leaseText = "Welcome To UHD Aparments.  You are subject to our rules and regulations. Your move in date is "
        + todaysDate + " and your move out date is " + leaseExpirationDate + ". Your monthly rent is $" + newRent + ".";
    //modeled after lease records
    newLease.push_back(to_string(newUserID)); //generate new user id
    newLease.push_back(name); //tenants name
    newLease.push_back(to_string(newReferenceNum)); //generate new ref num
    newLease.push_back(todaysDate); //beginning date = today's date
    newLease.push_back(leaseExpirationDate); //ending date = beginning date plus 1 year
    newLease.push_back(todaysDate); //date last modified
    newLease.push_back(requestedFloorPlan); //generate apartment num = floor plan requested plus vacant apt#
    newLease.push_back(newRent); //pull from apartment_complex_info
    newLease.push_back(leaseText); //generate lease text

    Staff::createNewTenantFromLease(to_string(newUserID), name, phoneNum, email, requestedFloorPlan);

    return newLease;

}
