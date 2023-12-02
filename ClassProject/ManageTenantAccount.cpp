/* Prologue
 * Name: Manage Tenant Account Methods
 * Description: Implementation file for ManageTenantAccount
 * Contributors: Crischelle Polley/Scott Ward
 * Date created: Nov 16 2023
 * Date last modified: Dec 1 2023
*/

#include "ManageTenantAccount.h"
#include "Tenant.h"
#include "ViewTenantInfo.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


void ManageTenantAccount::manageTenantAccountForTenant(int uid, int option, string s) {
    Tenant tenant(uid);

    // [1] View Account Information
    // This will access ViewTenantAccount boundary class
    if (option == 1) {
        ViewTenantInfo::displayTenantAccount(tenant.getUsername(), tenant.getPassword(), tenant.getName(), 
                                             tenant.getPhoneNum(), tenant.getEmail(), tenant.getAptNum());

    }

    // [2] Change Username
    else if (option == 2) {
        tenant.setUsername(s);
        //cout << "This is username: " << tenant.getUsername() << endl;
    }

    // [3] Change Password
    else if (option == 3) {
        tenant.setPassword(s);
        //cout << "This is password: " << tenant.getPassword() << endl;
    }

    // [4] Change Phone Number
    else if (option == 4) {
        tenant.setPhoneNum(s);
        //cout << "This is phone num: " << tenant.getPhoneNum() << endl;
    }

    // [5] Change Email
    else if (option == 5) {
        tenant.setEmail(s);
        //cout << "This is email: " << tenant.getEmail() << endl;
    }

}


void ManageTenantAccount::manageTenantAccountForStaff(int option, int iD, string str) {
    Tenant tenant(iD);

    if (option == 1) {

        fstream inputFile;

        inputFile.open("UserRecords.csv", ios::in);

        vector<string> row;
        string line, data, temp;

        while (getline(inputFile, line)) {
            row.clear();
            stringstream s(line);

            while (getline(s, data, ',')) {
                row.push_back(data);
            }

            if (row[3] == "Tenant") {
                cout << "Tenant Name: " << row[4] << endl;
                cout << "\tUser ID: " << row[0] << endl;
                cout << "\tUsername: " << row[1] << endl;
                cout << "\tPassword: " << row[2] << endl;
                cout << "\tPhone Number: " << row[5] << endl;
                cout << "\tEmail: " << row[6] << endl;
                cout << "\tApartment Number: " << row[7] << endl << endl;
            }
        }
        inputFile.close();

    } else if (option == 2) {
        tenant.setUsername(str);
        tenant.writeTenantInfo(tenant.getUserID(), 1, tenant.getUsername());

    } else if (option == 3) {
        tenant.setPassword(str);
        tenant.writeTenantInfo(tenant.getUserID(), 2, tenant.getPassword());

    } else if (option == 4) {
        tenant.setPhoneNum(str);
        tenant.writeTenantInfo(tenant.getUserID(), 5, tenant.getPhoneNum());

    } else if (option == 5) {
        tenant.setEmail(str);
        tenant.writeTenantInfo(tenant.getUserID(), 6, tenant.getEmail());
    }
}