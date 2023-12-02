/* Prologue
 * Name: Lease Class
 * Description: Stores long term information pertatining to leases
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Dec 1 2023
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

        Lease() {
            cout << "This is the Lease's default constructor" << endl;
        }

        Lease(string refNum) {
            referenceNum = refNum;
            readLease(referenceNum);
        }

        ~Lease() {
            cout << "This is the Lease's destructor" << endl;
        }

        string getBeginningDate() const { return beginningDate; }

        void setBeginningDate(const string& bd) { beginningDate = bd; }

        string getEndingDate() const { return endingDate; }

        void setEndingDate(const string& ed) { endingDate = ed; }

        string getDateLastModified() const { return dateLastModified; }

        void setDateLastModified(const string& dlm) { beginningDate = dlm; }

        string getReferenceNum() const { return referenceNum; }

        void setReferenceNum(const string& rn) { referenceNum = rn; }

        string getLeaseText() const { return leaseText; }

        void setLeaseText(const string& lt) { leaseText = lt; }

        string getTenantName() const { return tenantName; }

        void setTenantName(const string& tn) { tenantName = tn; }

        string getTenantUserID() const { return tenantUserID; }

        string getApartmentNum() const { return aptNumber; }

        void setApartmentNum(const string& apt) { aptNumber = apt; }

        string getRentAmount() const { return rentAmt; }

        void setRentAmount(const string& rnt) { rentAmt = rnt; }

        void readLease(string);

        void writeLease(string, string);
};

#endif