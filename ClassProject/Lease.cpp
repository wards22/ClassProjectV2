/* Prologue
 * Name: Lease Class Implementation
 * Description: Implemenation of Lease members
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Dec 1 2023
*/


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

#include "Lease.h"


void Lease::readLease(string refNum) {
    fstream inputFile;
    inputFile.open("LeaseRecords.csv", ios::in);

    string line, data, newModifiedDate;
    vector<string> row;

    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);

    newModifiedDate = to_string(1 + newtime.tm_mon) + "/" + to_string(newtime.tm_mday) + "/" + to_string(1900 + newtime.tm_year);

    while (getline(inputFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (refNum == row[2]) {
            this->tenantUserID = row[0];
            this->tenantName = row[1];
            this->referenceNum = row[2];
            this->beginningDate = row[3];
            this->endingDate = row[4];
            this->dateLastModified = newModifiedDate;
            this->aptNumber = row[6];
            this->rentAmt = row[7];
            this->leaseText = row[8];
            inputFile.close();
            break;
        }
    }
}

void Lease::writeLease(string refNum, string str) {
    fstream inputFile, outputFile;
    inputFile.open("LeaseRecords.csv", ios::in);
    outputFile.open("NewLeaseRecords.csv", ios::out);
    string line, data;
    int i;
    vector<string> row;

    while (getline(inputFile, line)) {

        row.clear();

        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        int row_size = row.size();

        if (refNum == row[2]) {

            row[4] = getEndingDate();
            row[5] = getDateLastModified();
            row[7] = getRentAmount();
            row[8] = str;

            if (!inputFile.eof()) {
                for (i = 0; i < row_size - 1; i++) {

                    // write the updated data 
                    // into a new file 'NewUserRecords.csv' 
                    // using fout 
                    outputFile << row[i] << ",";
                }

                outputFile << row[row_size - 1] << "\n";
            }
        } else {
            if (!inputFile.eof()) {
                for (i = 0; i < row_size - 1; i++) {

                    // writing other existing records 
                    // into the new file using fout. 
                    outputFile << row[i] << ",";
                }

                // the last column data ends with a '\n' 
                outputFile << row[row_size - 1] << "\n";
            }
        }
        if (inputFile.eof())
            break;
    }

    inputFile.close();
    outputFile.close();

    remove("LeaseRecords.csv");
    rename("NewLeaseRecords.csv", "LeaseRecords.csv");
}