/* Prologue
 * Name: Rent Class
 * Description: Creates and modifies tenant's Rent file
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Dec 1 2023
 */

#pragma once
#ifndef RENT_H
#define RENT_H

#include <string>
#include <vector>

using namespace std;

class Rent {
    private:
    string paymentMethod;
    string month;
    string day;
    string year;
    string date;
    string referenceNum;
    string description;
    float amount;
    float balanceDue;
    float remainingBalanceDue;
    bool isInProgress;
    vector<vector<string>> rentReceipts;

    string formatDate(const string&, const string&, const string&);

    float formatMoney(float m) const;


    public:
    Rent() {
        paymentMethod = "";
        date = "";
        referenceNum = "";
        description = "";
        // Set to NULL because it can be negative
        amount = NULL;
        // Set to NULL because it can be negative
        balanceDue = NULL;
        // Set to NULL because it can be negative
        remainingBalanceDue = NULL;
        isInProgress = false;
    }

    Rent(int uid) {
        balanceDue = -32.65;
        readRentReceipt(uid);
    }

    string getPaymentMethod() const
    {
        return paymentMethod;
    }

    void setPaymentMethod(const string& pm)
    {
        paymentMethod = pm;
    }

    void setMonth(const string& mm) {
        month = mm;
    }

    void setDay(const string& dd) {
        day = dd;
    }

    void setYear(const string& yyyy) {
        year = yyyy;
    }

    string getDate() const {
        return date;
    }

    void setDate(const string& mm, const string& dd, const string& yyyy) {
        date = formatDate(mm, dd, yyyy);
    }

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

    float getAmount() const {
        return formatMoney(amount);
    }

    void setAmount(const float& a) {
        amount = a;
    }

    float getBalanceDue() const {
        return formatMoney(balanceDue);
    }

    void setBalanceDue(const float& bd) {
        balanceDue = bd;
    }

    bool getProgressStatus() const {
        return isInProgress;
    }

    vector<vector<string>> getRentReceipts() const {
        return rentReceipts;
    }

    void setRentReceipts(const vector<vector<string>>& rr) {
        rentReceipts = rr;
    }

    float payRentReceipt(const float&);

    void readRentReceipt(int);

    void writeRentReceipt(int);

    void createRentReceipt();

    void editRentReceipt();

    void deleteRentReceipt();

    void submitReceipt();
};

#endif