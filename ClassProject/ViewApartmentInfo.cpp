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
