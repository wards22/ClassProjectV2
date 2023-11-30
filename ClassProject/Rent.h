/* Prologue
 * Name: Rent Class
 * Description: Creates and modifies tenant's Rent file
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Nov 29 2023
*/

#pragma once
#ifndef RENT_H
#define RENT_H

#include <string>

using namespace std;

class Rent {
    private:
    string paymentMethod;
    string date;
    string referenceNum;
    string description;
    float amount;
    float balanceDue;
    float remainingBalanceDue;

    string getDate() const;

    string formatDate(const char* d) const;

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

    float payRentReceipt(const float&);

    // Need to create files for this to get understanding
    // of how to code
    void readRentReceipt(int);

    void writeRentReceipt(int);
};

#endif