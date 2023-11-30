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

    inputFile.open("ApartmentRecords.csv", ios::in);

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
