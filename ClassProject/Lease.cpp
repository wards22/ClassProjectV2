/* Prologue
 * Name: Lease Class Implementation
 * Description: Implemenation of Lease members
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Dec 3 2023
*/


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

#include "Lease.h"


Lease::Lease() {
    cout << "This is the Lease's default constructor" << endl;
}

Lease::Lease(string refNum) {
    referenceNum = refNum;
    readLease(referenceNum);
}

Lease::~Lease() {
    cout << "This is the Lease's destructor" << endl;
}

string Lease::getBeginningDate() const 
    { return beginningDate; }

void Lease::setBeginningDate(const string& bd) 
    { beginningDate = bd; }

string Lease::getEndingDate() const 
    { return endingDate; }

void Lease::setEndingDate(const string& ed) 
    { endingDate = ed; }

string Lease::getDateLastModified() const 
    { return dateLastModified; }

void Lease::setDateLastModified(const string& dlm) 
    { beginningDate = dlm; }

string Lease::getReferenceNum() const 
    { return referenceNum; }

void Lease::setReferenceNum(const string& rn) 
    { referenceNum = rn; }

string Lease::getLeaseText() const 
    { return leaseText; }

void Lease::setLeaseText(const string& lt) 
    { leaseText = lt; }

string Lease::getTenantName() const 
    { return tenantName; }

void Lease::setTenantName(const string& tn) 
    { tenantName = tn; }

string Lease::getTenantUserID() const 
    { return tenantUserID; }

string Lease::getApartmentNum() const 
    { return aptNumber; }

void Lease::setApartmentNum(const string& apt) 
    { aptNumber = apt; }

string Lease::getRentAmount() const 
    { return rentAmt; }

void Lease::setRentAmount(const string& rnt) 
    { rentAmt = rnt; }

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
        }
        else {
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