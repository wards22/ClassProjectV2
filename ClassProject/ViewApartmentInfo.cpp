/* Prologue
 * Name: View Apartment Info Class
 * Description: Implementation of ViewApartmentInfo.h
 * Contributors: Scott Ward
 * Date created: Nov 29 2023
 * Date last modified: Nov 29 2023
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#include "ViewApartmentInfo.h"
#include "Apartment.h"

void ViewApartmentInfo::displayFloorPlans() {
    fstream inputFile;

    inputFile.open("FloorPlanRecords.csv", ios::in);

    vector<string> row;
    string line, data, temp;

    while (getline(inputFile, line)) {
        stringstream s(line);

        row.clear();
        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        cout << row[0] << " Floor Plan:" << endl;
        cout << "\tBedroom: " << row[1] << endl;
        cout << "\tBathroom: " << row[2] << endl;
        cout << "\tSquare Footage: " << row[3] << " sq. ft" << endl;
        cout << "\tRent Amount: $" << row[4] << " per month" << endl;
        cout << "\tAmenities: " << row[5] << endl << endl;

    }
    inputFile.close();
}

void ViewApartmentInfo::displayApartmentComplexInfo() {
    fstream inputFile;

    inputFile.open("ApartmentComplexInfo.txt", ios::in);

    vector<string> row;
    string line, data;

    while (getline(inputFile, line)) {
        stringstream s(line);

        row.clear();
        while (getline(s, data, '\n')) {
            row.push_back(data);
        }

        cout << row[0] << endl;
    }
    inputFile.close();
    cout << endl;
}

void ViewApartmentInfo::displayVacantApartments() {
    fstream apartmentFile;

    apartmentFile.open("ApartmentRecords.csv", ios::in);

    vector<string> row;
    string line, data, temp;

    while (getline(apartmentFile, line)) {
        stringstream s(line);

        row.clear();
        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (row[6] == "Y") {
            cout << "Apartment Number: " << row[0] << row[1] << endl;
            cout << "\tBedrooms: " << row[2] << endl;
            cout << "\tBathrooms: " << row[3] << endl;
            cout << "\tSquare Footage: " << row[4] << " sq. ft" << endl;
            cout << "\tRent Amount: $" << row[5] << " per month" << endl;
        }

    }
    apartmentFile.close();
}

void ViewApartmentInfo::displayInhabitedApartments() {
    fstream apartmentFile;

    apartmentFile.open("ApartmentRecords.csv", ios::in);

    vector<string> row;
    string line, data;

    while (getline(apartmentFile, line)) {
        stringstream s(line);

        row.clear();
        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (row[6] == "N") {

            fstream userFile;
            userFile.open("UserRecords.csv", ios::in);

            vector<string> user;
            string line1, data1;

            while (getline(userFile, line1)) {
                stringstream s1(line1);
                user.clear();
                while (getline(s1, data1, ',')) {
                    user.push_back(data1);
                }

                if (user[7] == row[0] + row[1])
                {
                    cout << "Apartment Number: " << user[7] << endl;
                    cout << "\tTenant Name: " << user[4] << endl;
                    cout << "\tBedrooms: " << row[2] << endl;
                    cout << "\tBathrooms: " << row[3] << endl;
                    cout << "\tSquare Footage: " << row[4] << " sq. ft" << endl;
                    cout << "\tRent Amount: $" << row[5] << " per month" << endl;
                }
            }
            userFile.close();
        }
        
    }
    apartmentFile.close();
}

void ViewApartmentInfo::createNewApartment() {
    int option = 0;
    int aptNumber = 0;
    string floorPlan, numBeds, numBaths, sqFoot, rentAmount, vacancy;

    cout << "Please enter in the following information for the new Apartment: " << endl;
    cout << "Choose a Floor Plan: " << endl;
    cout << "\t[1] A - 1 Bedroom | 1 Bathroom" << endl;
    cout << "\t[2] B - 2 Bedroom | 2 Bathroom" << endl;
    cout << "\t[3] C - 3 Bedroom | 3 Bathroom" << endl;
    cout << "Please choose an option between [1] - [3]: ";
    cin >> option;
    while (option < 1 || option > 3) {
        cout << "Invalid option. Please choose an option between [1] - [3]: ";
        cin >> option;
    }
    cout << endl;
    cout << "Please enter the apartment number (1-70): ";
    cin >> aptNumber;
    while (aptNumber < 1 || aptNumber > 70) {
        cout << "Invalid Number. Please enter the apartment number (1-70): ";
        cin >> aptNumber;
    }
    if (option == 1) {
        floorPlan = "A";
        numBeds = "1";
        numBaths = "1";
        sqFoot = "600";
        rentAmount = "700";
        vacancy = "Y";
    }
    else if (option == 2) {
        floorPlan = "B";
        numBeds = "2";
        numBaths = "2";
        sqFoot = "1100";
        rentAmount = "1200";
        vacancy = "Y";
    }
    else if (option == 3) {
        floorPlan = "C";
        numBeds = "3";
        numBaths = "3";
        sqFoot = "1350";
        rentAmount = "1600";
        vacancy = "Y";
    }
    Apartment newApartment(floorPlan, to_string(aptNumber), numBeds, numBaths, sqFoot, rentAmount, vacancy);
    newApartment.writeApartmentInfo();
}

void ViewApartmentInfo::removeVacantApartment() {
    cout << "Choose from the below list of vacant apartments: " << endl << endl;

    fstream apartmentFile;

    apartmentFile.open("ApartmentRecords.csv", ios::in);

    vector<string> row, vacantNumber, vacantFloorPlan;
    string line, data;
    char response;
    int count = 0, choice = 0;

    while (getline(apartmentFile, line)) {
        stringstream s(line);

        row.clear();
        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (row[6] == "Y") {
            cout << "[" << count + 1 << "]" << endl;
            cout << "\tApartment Number: " << row[0] << row[1] << endl;
            cout << "\tBedrooms: " << row[2] << endl;
            cout << "\tBathrooms: " << row[3] << endl;
            cout << "\tSquare Footage: " << row[4] << " sq. ft" << endl;
            cout << "\tRent Amount: $" << row[5] << " per month" << endl;
            vacantFloorPlan.push_back(row[0]);
            vacantNumber.push_back(row[1]);
            count++;
        }

    }
    apartmentFile.close();

    do {
        cout << "Which vacant apartment would you like to remove? Choose an option from [1] - ";
        cout << "[" << vacantNumber.size() << "]";
        cin >> choice;

        while (choice < 1 || choice > vacantNumber.size()) {
            cin.clear();
            cin.ignore();
            cout << endl;
            cout << "Invalid option. Please choose an option from [1] -" << " [" << vacantNumber.size() << "]: ";
            cin >> choice;
        }

        cout << "You chose the following apartment to remove: " << endl << endl;

        apartmentFile.open("ApartmentRecords.csv", ios::in);
        while (getline(apartmentFile, line)) {
            row.clear();
            stringstream s(line);

            while (getline(s, data, ',')) {
                row.push_back(data);
            }

            if (vacantFloorPlan[choice - 1] == row[0] && vacantNumber[choice - 1] == row[1]) {
                cout << "\tApartment Number: " << row[0] << row[1] << endl;
                cout << "\tBedrooms: " << row[2] << endl;
                cout << "\tBathrooms: " << row[3] << endl;
                cout << "\tSquare Footage: " << row[4] << " sq. ft" << endl;
                cout << "\tRent Amount: $" << row[5] << " per month" << endl;
            }
        }
        apartmentFile.close();
        cout << "Is this correct? (y/Y): ";
        cin >> response;
    } while (!(response == 'y' || response == 'Y'));

    apartmentFile.open("ApartmentRecords.csv", ios::in);
    fstream newApartmentFile;
    newApartmentFile.open("NewApartmentRecords.csv", ios::out);

    string newAptLine, newAptData;
    vector<string> newAptRow;
    while (getline(apartmentFile, newAptLine)) {

        newAptRow.clear();
        stringstream s(newAptLine);


        while (getline(s, newAptData, ',')) {
            newAptRow.push_back(newAptData);
        }

        if (newAptRow[1] != vacantNumber[choice - 1]) {
            if (!apartmentFile.eof()) {
                for (int i = 0; i < newAptRow.size(); i++) {
                    newApartmentFile << newAptRow[i] << ",";
                }
                newApartmentFile << newAptRow[newAptRow.size() - 1] << "\n";
            }
            if (apartmentFile.eof())
                break;
        }
    }
    apartmentFile.close();
    newApartmentFile.close();
    remove("ApartmentRecords.csv");
    rename("NewApartmentRecords.csv", "ApartmentRecords.csv");

    cout << "The Apartment Records have been updated!" << endl << endl;
}


