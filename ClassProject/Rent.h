/* Prologue
 * Name: Rent Class
 * Description: Creates and modifies tenant's Rent file
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Dec 3 2023
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

    float formatMoney(float) const;


    public:
    Rent();

    Rent(int);

    string getPaymentMethod() const;

    void setPaymentMethod(const string&);

    void setMonth(const string&);

    void setDay(const string&);

    void setYear(const string&);

    string getDate() const;

    void setDate(const string&, const string&, const string&);

    string getReferenceNum() const;

    void setReferenceNum(const string&);

    string getDescription() const;

    void setDescription(const string&);

    float getAmount() const;

    void setAmount(const float&);

    float getBalanceDue() const;

    void setBalanceDue(const float&);

    bool getProgressStatus() const;

    vector<vector<string>> getRentReceipts() const;

    void setRentReceipts(const vector<vector<string>>&);

    float payRentReceipt(const float&);

    void readRentReceipt(int);

    void writeRentReceipt(int);

};

#endif