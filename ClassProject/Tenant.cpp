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

void Tenant::writeTenantInfo(int user_ID, int index, string str) {

    fstream inputFile, outputFile;
    inputFile.open("UserRecords.csv", ios::in);
    outputFile.open("NewUserRecords.csv", ios::out);
    string line, data;
    int user_ID_in_file, i;
    vector<string> row;

    while (getline(inputFile, line)) {

        row.clear();

        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        user_ID_in_file = stoi(row[0]);
        int row_size = row.size();

        if (user_ID == user_ID_in_file) {

            row[index] = str;

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

    remove("UserRecords.csv");
    rename("NewUserRecords.csv", "UserRecords.csv");

}