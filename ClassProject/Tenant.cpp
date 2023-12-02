#include "Tenant.h"
#include <fstream>
#include <sstream>

void Tenant::readTenantInfo() {

    fstream inputFile;
    inputFile.open("UserRecords.csv", ios::in);

    string line, data;
    int user_ID_in_file;
    vector<string> row;

    while (getline(inputFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        user_ID_in_file = stoi(row[0]);

        if (userID == user_ID_in_file) {
            this->username = row[1];
            this->password = row[2];
            this->userType = row[3];
            this->name = row[4];
            this->phoneNum = row[5];
            this->email = row[6];
            this->aptNum = row[7];
            inputFile.close();
            break;
        }
    }
}

void Tenant::writeTenantInfo() {

}