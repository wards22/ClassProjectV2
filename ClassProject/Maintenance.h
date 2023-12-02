/* Prologue
 * Name: Maintenance Request Class
 * Description: Stores long term information pertatining to maintenance requests
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Nov 26 2023
*/

#pragma once
#ifndef MAINTENANCE_REQUEST_H
#define MAINTENANCE_REQUEST_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class MaintenanceRequest {
    private:
    string date = "11/11/11";
    string referenceNum = "6969";
    string description = "Stuff's broke";
    string tenantName = "John Doe";
    string status = "Status Goes Here";
    string tenantUserID = "0";

    public:

    MaintenanceRequest() {
        cout << "This is Maintenance Request's default constructor" << endl;
    }

    MaintenanceRequest(string refNum) {
        referenceNum = refNum;
        readStatus(referenceNum);
    }

    ~MaintenanceRequest() {
        cout << "This is Maintenance Request's destructor" << endl;
    }

    string getReferenceNum() const { return referenceNum; }

    void setReferenceNum(const string& rn) { referenceNum = rn; }

    string getDescription() const { return description; }

    void setDescription(const string& d) { description = d; }

    string getUserID() const { return tenantUserID; }

    void setUserID(const int& uid) { tenantUserID = uid; }

    string getTenantName() const { return tenantName; }

    void setTenantName(const string& n) { tenantName = n; }

    string getStatus() const { return status; }

    void setStatus(const string& st) { status = st; }

    void readStatus(string);

    void writeStatus(string, string);
};

#endif