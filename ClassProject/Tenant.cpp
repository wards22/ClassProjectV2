/* Prologue
 * Name: Tenant Implementation File
 * Description: Creates and modifies Tenant's file
 * Contributors: Crischelle Polley
 * Date created: Nov 13 2023
 * Date last modified: Dec 2 2023
*/

#include "Tenant.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>


Tenant::Tenant() {
    username = "";
    password = "";
    userType = "";
    userID = -1;
    name = "";
    phoneNum = "";
    email = "";
    aptNum = "";
}

// Constructor will call readTenantInfo and
// set all attributes to tenant info in 
// sample-data-file based on username and 
// password entered from user login 
Tenant::Tenant(int uid) {
    userID = uid;
    readTenantInfo();
}

// Destructor will call writeTenantInfo and write all
// attributes to sample-data-file and is evoked by 
// exitMenu() in TenantUI::displayTenantAccountMenu
/*
Tenant::~Tenant() {
    cout << "This is Tenant destructor\n";
    writeTenantInfo(int, int, string);
}
*/

string Tenant::getUsername() const
{
    return username;
}

void Tenant::setUsername(const string& un)
{
    username = un;
}

string Tenant::getPassword() const
{
    return password;
}

void Tenant::setPassword(const string& pw)
{
    password = pw;
}

string Tenant::getUserType() const
{
    return userType;
}

void Tenant::setUserType(const string& ut)
{
    userType = ut;
}

int Tenant::getUserID() const
{
    return userID;
}

void Tenant::setUserID(const int& uid)
{
    userID = uid;
}

string Tenant::getName() const
{
    return name;
}

void Tenant::setName(const string& n)
{
    name = n;
}

string Tenant::getPhoneNum() const
{
    return phoneNum;
}

void Tenant::setPhoneNum(const string& pn)
{
    phoneNum = pn;
}

string Tenant::getEmail() const
{
    return email;
}

void Tenant::setEmail(const string& e)
{
    email = e;
}

string Tenant::getAptNum() const
{
    return aptNum;
}

void Tenant::setAptNum(const string& an)
{
    aptNum = an;
}

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

    remove("UserRecords.csv");
    rename("NewUserRecords.csv", "UserRecords.csv");

}