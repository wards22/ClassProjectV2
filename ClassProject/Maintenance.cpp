/* Prologue
 * Name: Staff Class
 * Description: Staff class for holiding long term info on staff
 * Contributors: Scott Ward
 * Date created: Dec 1 2023
 * Date last modified: Dec 3 2023
*/

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

#include "Maintenance.h"

MaintenanceRequest::MaintenanceRequest() {
    cout << "This is Maintenance Request's default constructor" << endl;
}

MaintenanceRequest::MaintenanceRequest(string refNum) {
    referenceNum = refNum;
    readStatus(referenceNum);
}

MaintenanceRequest::~MaintenanceRequest() {
    cout << "This is Maintenance Request's destructor" << endl;
}

string MaintenanceRequest::getReferenceNum() const 
    { return referenceNum; }

void MaintenanceRequest::setReferenceNum(const string& rn) 
    { referenceNum = rn; }

string MaintenanceRequest::getDescription() const 
    { return description; }

void MaintenanceRequest::setDescription(const string& d) 
    { description = d; }

string MaintenanceRequest::getUserID() const 
    { return tenantUserID; }

void MaintenanceRequest::setUserID(const int& uid) 
    { tenantUserID = uid; }

string MaintenanceRequest::getTenantName() const 
    { return tenantName; }

void MaintenanceRequest::setTenantName(const string& n) 
    { tenantName = n; }

string MaintenanceRequest::getStatus() const
    { return status; }

void MaintenanceRequest::setStatus(const string& st)
    { status = st; }

void MaintenanceRequest::readStatus(string refID) {
    fstream inputFile;
    inputFile.open("MaintenanceRecords.csv", ios::in);

    string line, data, ref_ID_in_file;
    vector<string> row;

    while (getline(inputFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (refID == row[2]) {
            this->tenantUserID = row[0];
            this->tenantName = row[1];
            this->referenceNum = row[2];
            this->date = row[3];
            this->description = row[4];
            this->status = row[5];
            inputFile.close();
            break;
        }
    }
}

void MaintenanceRequest::writeStatus(string refNum, string str) {
    fstream inputFile, outputFile;
    inputFile.open("MaintenanceRecords.csv", ios::in);
    outputFile.open("NewMaintenanceRecords.csv", ios::out);
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



            row[5] = str;



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

    remove("MaintenanceRecords.csv");
    rename("NewMaintenanceRecords.csv", "MaintenanceRecords.csv");
}