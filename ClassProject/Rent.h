/* Prologue
 * Name: Rent Class
 * Description: Creates and modifies tenant's Rent file
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Nov 15 2023
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

    void setDate(const string& d);

    string formatDate(const string& d);

    float formatMoney(const float& m);


public:
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

    float getAmount() const
    {
        return amount;
    }

    void setAmount(const float& a)
    {
        amount = a;
    }

    float getBalanceDue() const
    {
        return balanceDue;
    }

    void setBalanceDue(const float& bd)
    {
        balanceDue = bd;
    }

    float payRentReceipt(const float& r) {
        remainingBalanceDue = balanceDue - r;
        formatMoney(remainingBalanceDue);
        return remainingBalanceDue;
    }

    // Need to create files for this to get understanding
    // of how to code
    void readRentReceipt();

    void writeRentReceipt();
};

#endif