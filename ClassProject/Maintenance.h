/* Prologue
 * Name: Maintenance Request Class
 * Description: Stores long term information pertatining to maintenance requests
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Dec 3 2023
*/

#pragma once
#ifndef MAINTENANCE_REQUEST_H
#define MAINTENANCE_REQUEST_H

#include <string>

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

    MaintenanceRequest();

    MaintenanceRequest(string);

    ~MaintenanceRequest();

    string getReferenceNum() const;

    void setReferenceNum(const string&);

    string getDescription() const;

    void setDescription(const string&);

    string getUserID() const;

    void setUserID(const int&);

    string getTenantName() const;

    void setTenantName(const string&);

    string getStatus() const;

    void setStatus(const string&);

    void readStatus(string);

    void writeStatus(string, string);
};

#endif