/* Prologue
 * Name: Lease Class
 * Description: Stores long term information pertatining to leases
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Dec 3 2023
*/

#pragma once
#ifndef LEASE_H
#define LEASE_H

#include <string>

using namespace std;

class Lease {
    private:
    string beginningDate = "11/11/11";
    string endingDate = "11/11/11";
    string dateLastModified = "11/11/11/";
    string referenceNum = "6969";
    string leaseText = "Stuff's broke";
    string tenantName = "John Doe";
    string tenantUserID = "0";
    string aptNumber = "A1";
    string rentAmt = "100";

    public:

    Lease();

    Lease(string);

    ~Lease();

    string getBeginningDate() const;

    void setBeginningDate(const string&);

    string getEndingDate() const;

    void setEndingDate(const string&);

    string getDateLastModified() const;

    void setDateLastModified(const string&);

    string getReferenceNum() const;

    void setReferenceNum(const string&);

    string getLeaseText() const;

    void setLeaseText(const string&);

    string getTenantName() const;

    void setTenantName(const string&);

    string getTenantUserID() const;

    string getApartmentNum() const;

    void setApartmentNum(const string&);

    string getRentAmount() const;

    void setRentAmount(const string&);

    void readLease(string);

    void writeLease(string, string);
};

#endif