/* Prologue
 * Name: Tenant Class
 * Description: Creates and modifies Tenant's file
 * Contributors: Crischelle Polley
 * Date created: Nov 13 2023
 * Date last modified: Nov 21 2023
*/


#pragma once
#ifndef TENANT_H
#define TENANT_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


// Should class be rewritten to read and write directly to 
// file?
class Tenant {
    // Default values for the attributes can also be set here. That or constructor?
private:
    string username;
    string password;
    string userType;        // Cannot be changed by tenant
    int userID;             // Cannot be changed by tenant
    string name;            // Cannot be changed by tenant
    string phoneNum;
    string email;
    int aptNum;             // Cannot be changed by tenant


public:
    // Constructor will call readTenantInfo and
    // set all attributes to tenant info in 
    // sample-data-file based on username and 
    // password entered from user login 
    Tenant() {
        cout << "This is Tenant constructor\n";
        readTenantInfo();
    }

    // Destructor will call writeTenantInfo and write all
    // attributes to sample-data-file and is evoked by 
    // exitMenu() in TenantUI::displayTenantAccountMenu
    ~Tenant() {
        cout << "This is Tenant destructor\n";
        writeTenantInfo();
    }

    string getUsername() const
    {
        return username;
    }

    void setUsername(const string& un)
    {
        username = un;
    }

    string getPassword() const
    {
        return password;
    }

    void setPassword(const string& pw)
    {
        password = pw;
    }

    string getUserType() const
    {
        return userType;
    }

    void setUserType(const string& ut)
    {
        userType = ut;
    }

    int getUserID() const
    {
        return userID;
    }

    void setUserID(const int& uid)
    {
        userID = uid;
    }

    string getName() const
    {
        return name;
    }

    void setName(const string& n)
    {
        name = n;
    }

    string getPhoneNum() const
    {
        return phoneNum;
    }

    void setPhoneNum(const string& pn)
    {
        phoneNum = pn;
    }

    string getEmail() const
    {
        return email;
    }

    void setEmail(const string& e)
    {
        email = e;
    }

    int getAptNum() const
    {
        return aptNum;
    }

    void setAptNum(const int& an)
    {
        aptNum = an;
    }

    void readTenantInfo() {
        ifstream readFile;
        readFile.open("../../../ClassProject/Sample-data-file.csv");

        if (readFile) {
            cout << "File was opened\n\n";

            // Hard coding username and password into function
            // until User Login implementation done
            setUsername("tenant2");
            setPassword("afdak!121");

            // Create 2d vector to store sample data
            vector<vector<string>> sampleData;
            vector<string> str;
            string line;
            string s;

            // Read Sample-data-file into vector 
            while (getline(readFile, line, '\n')) {

                // Convert line to istream to use getline
                istringstream iss(line);

                while (getline(iss, s, ',')) {
                    str.push_back(s);
                }

                sampleData.push_back(str);
                str.clear();
            }

            // Display sampleData vector
            /*for(int i = 0; i < sampleData.size(); i++) {
                for(int j = 0; j < sampleData[i].size(); j++) {
                    if(sampleData[i][j] == username) {
                        cout << endl << "Found you, " << sampleData[i][j] << endl;
                    }
                    cout << sampleData[i][j] << "\t";
                }
                cout << endl << endl;
            }*/

        }
        else {
            cout << "File could not open\n";
        }

        cout << "File is closing\n\n";
        readFile.close();
    }

    void writeTenantInfo() {
        cout << "This is writeTenantInfo\n";
    }

};

#endif