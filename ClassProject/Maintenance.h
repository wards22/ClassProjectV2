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
    string date;
    string referenceNum;
    string description;
    string getDate() const;
    void setDate(const string& d);
    string formatDate(const string& d);

public:

    string getReferenceNum() const
    {
        return referenceNum;
    }

    void setReferenceNum(const string& rn)
    {
        referenceNum = rn;
    }

    string getDescription() const
    {
        return description;
    }

    void setDescription(const string& d)
    {
        description = d;
    }

    void viewTenantRequest();

    void changeStatus();

    void readStatus();

    void writeStatus();
};

#endif