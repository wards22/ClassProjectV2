/* Prologue
 * Name: Lease Class
 * Description: Stores long term information pertatining to leases
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Nov 26 2023
*/

#pragma once
#ifndef LEASE_H
#define LEASE_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Lease {
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

    void createNewLease();

    void modifyExistingLease();

    void updateTenantLease();

    void readLease();

    void writeLease();
};

#endif