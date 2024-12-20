/* Prologue
 * Name: Staff Class
 * Description: Staff class for holiding long term info on staff
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Dec 3 2023
*/

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

#include "Staff.h"


//Modeled after tenant constructor/destructor. Need to figure out how to build one
   //from information in spreadsheet. May need to pull something from when the user logins
Staff::Staff() {
    cout << "This is Staff's default constructor" << endl;
}

Staff::Staff(int user_ID) {
    userID = user_ID;
    readStaffInfo(userID);
}

Staff::~Staff() {

}

string Staff::getUsername() const
{
    return username;
}

void Staff::setUsername(const string& un)
{
    username = un;
}

string Staff::getPassword() const
{
    return password;
}

void Staff::setPassword(const string& pw)
{
    password = pw;
}

string Staff::getUserType() const
{
    return userType;
}

void Staff::setUserType(const string& ut)
{
    userType = ut;
}

int Staff::getUserID() const
{
    return userID;
}

void Staff::setUserID(const int& uid)
{
    userID = uid;
}

string Staff::getName() const
{
    return name;
}

void Staff::setName(const string& n)
{
    name = n;
}

string Staff::getPhoneNum() const
{
    return phoneNum;
}

void Staff::setPhoneNum(const string& pn)
{
    phoneNum = pn;
}

string Staff::getEmail() const
{
    return email;
}

void Staff::setEmail(const string& e)
{
    email = e;
}

void Staff::readStaffInfo(int user_ID) {

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

        if (user_ID == user_ID_in_file) {
            this->username = row[1];
            this->password = row[2];
            this->userType = row[3];
            this->name = row[4];
            this->phoneNum = row[5];
            this->email = row[6];
            inputFile.close();
            break;
        }
    }
}

void Staff::writeStaffInfo(int user_ID, int index, string str) {

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

void Staff::createNewTenantFromLease(string user_ID, string tenantName, string tenantPhone, 
    string tenantEmail, string tenantApartment) {

    fstream outputFile;

    outputFile.open("UserRecords.csv", ios::out | ios::app);

    vector<string> row;
    
    row.push_back(user_ID);
    row.push_back(tenantName + "1");
    row.push_back("Ch@nGeMeNoW1");
    row.push_back("Tenant");
    row.push_back(tenantName);
    row.push_back(tenantPhone);
    row.push_back(tenantEmail);
    row.push_back(tenantApartment);

    outputFile << row[0] << "," << row[1] << "," << row[2] << "," << row[3] << "," << row[4] << ","
        << row[5] << "," << row[6] << "," << row[7] << "\n";

    outputFile.close();
}