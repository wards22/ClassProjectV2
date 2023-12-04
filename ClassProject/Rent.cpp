/* Prologue
 * Name: Rent Class
 * Description: Creates and modifies tenant's Rent file
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Dec 3 2023
*/

#include "Rent.h"
#include <chrono>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;


string Rent::formatDate(const string& mm, const string& dd, const string& yyyy) {
    // Format month, day, and year to date
    date = mm + "/" + dd + "/" + yyyy;

    return date;
}

float Rent::formatMoney(float m) const {
    // Convert float to string to format money
    // Conversion from float to string shortens leading zeros (test case: 00000.98765434, 01000.98765434)
    string s = to_string(m);

    // Create string to store formatted money
    string money = "";


    int i = 0;
    /* If m is negative
    if(s[0] == '-') {
        money += '-';
        i++;
    } */

    // Concatenate all digits before decimal to money
    while (s[i] != '.') {
        money += s[i];
        i++;
    }

    // Concatenate decimal and 2 decimal places to money
    for (int j = 0; j < 3; j++) {
        if ((i + j) < s.length())
            money += s[i + j];
        else
            break;
    }

    // Convert money to float
    m = stof(money);

    return m;
}

Rent::Rent() {
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
    inProgress = false;
}

Rent::Rent(int uid) {
    balanceDue = -32.65;
    readRentReceipt(uid);
}

Rent::Rent(int uid, string ip) {
    balanceDue = -32.65;
    readRentReceipt(uid, ip);
}

string Rent::getPaymentMethod() const
{
    return paymentMethod;
}

void Rent::setPaymentMethod(const string& pm)
{
    paymentMethod = pm;
}

void Rent::setMonth(const string& mm) {
    month = mm;
}

void Rent::setDay(const string& dd) {
    day = dd;
}

void Rent::setYear(const string& yyyy) {
    year = yyyy;
}

string Rent::getDate() const {
    return date;
}

void Rent::setDate(const string& mm, const string& dd, const string& yyyy) {
    date = formatDate(mm, dd, yyyy);
}

string Rent::getReferenceNum() const
{
    return referenceNum;
}

void Rent::setReferenceNum(const string& rn)
{
    referenceNum = rn;
}

string Rent::getDescription() const
{
    return description;
}

void Rent::setDescription(const string& d)
{
    description = d;
}

float Rent::getAmount() const {
    return formatMoney(amount);
}

void Rent::setAmount(const float& a) {
    amount = formatMoney(a);
}

float Rent::getBalanceDue() const {
    return formatMoney(balanceDue);
}

void Rent::setBalanceDue(const float& bd) {
    balanceDue = bd;
}

bool Rent::getProgressStatus() const {
    return inProgress;
}

vector<vector<string>> Rent::getRentReceipts() const {
    return rentReceipts;
}

void Rent::setRentReceipts(const vector<vector<string>>& rr) {
    rentReceipts = rr;
}

float Rent::payRentReceipt(const float& r) {
    remainingBalanceDue = balanceDue - r;
    return formatMoney(remainingBalanceDue);
}




void Rent::readRentReceipt(int uid) {
    fstream inputFile;
    inputFile.open("RentReceipts.csv", ios::in);

    string line, data;
    vector<string> row;
    int user_ID_in_file;
    string receipt, record, field;
    vector<string> rent;
    int i;            // Keep track of which field is rent receipts


    // If tenant, read only this tenant into rentReceipts
    while (getline(inputFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) 
            row.push_back(data);

        user_ID_in_file = stoi(row[0]);

        if(uid == user_ID_in_file) {
            rentReceipts.clear();

            this->paymentMethod = row[1];

            if (row[2] == "true")
                this->inProgress = true;
            else
                this->inProgress = false;

            // Store rent receipts in string to format and remove all but user ID from vector row
            receipt = row[3];
            row.pop_back();
            row.pop_back();
            row.pop_back();

            stringstream r(receipt);
            while(getline(r, record, '&')) {
                stringstream rec(record);

                while (getline(rec, field, ';')) {
                    row.push_back(field);
                }
            }

            inputFile.close();

            // Push row to rentReceipts and return
            // rentReceipts will contain only 1 vector
            rentReceipts.push_back(row);
            return;
        }
    }


    // If staff, read all tenants' rent receipts into rentReceipts

    rentReceipts.clear();

    // Clear eof flag and send read position back to beginning of file
    inputFile.clear();
    inputFile.seekg(0);

    // Read through file and store tenants' rent receipts in rentReceipts
    while (getline(inputFile, line)) {
        row.clear();
        stringstream s(line);

        i = 0;
        while (getline(s, data, ',')) {
            i++;
            
            if(i == 1) {        // Store user ID
                row.push_back(data);

            } else if(i == 4) {             // Store all rent receipts for one tenant in one row
                stringstream d(data);

                while (getline(d, record, '&')) {
                    stringstream rec(record);

                    while (getline(rec, field, ';')) {
                        row.push_back(field);
                    }                    
                }

                rentReceipts.push_back(row);

            } else {
                continue;
            }
        } 
    }
    
    inputFile.close();
}




void Rent::readRentReceipt(int uid, string ip) {
    fstream inputFile;
    inputFile.open("RentReceipts.csv", ios::in);

    string line, data;
    vector<string> row;
    int user_ID_in_file;
    string receipt, record, field;
    vector<string> rent;
    int i;            // Keep track of which field is rent receipts


    // If tenant, read only this tenant into rentReceipts
    while (getline(inputFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ','))
            row.push_back(data);

        user_ID_in_file = stoi(row[0]);

        if (uid == user_ID_in_file) {
            rentReceipts.clear();

            this->paymentMethod = row[1];

            if (row[2] == "true") {
                this->inProgress = true;

                // Store rent receipts in string to format and remove all but user ID from vector row
                receipt = row[3];
                // Largest element must be erased first, otherwise vector size changes and erase goes out of bounds
                row.erase(row.begin() + 3);
                row.erase(row.begin() + 1);

                stringstream r(receipt);
                while (getline(r, record, '&')) {
                    stringstream rec(record);

                    while (getline(rec, field, ';')) {
                        row.push_back(field);
                    }
                }

                inputFile.close();

                // Delete all rent receipts from row except most recent
                row.erase(row.begin()+2, row.end()-4);

                // Push row to rentReceipts and return
                // rentReceipts will contain only 1 vector
                rentReceipts.push_back(row);
                return;
            
            } else {        // Come back to this for letting staff know that there is no receipt in progress or just check inProgress value
                this->inProgress = false;
                inputFile.close();
                return;
            }
        }
    }

    /*
    // If staff, read all tenants' rent receipts into rentReceipts

    rentReceipts.clear();

    // Clear eof flag and send read position back to beginning of file
    inputFile.clear();
    inputFile.seekg(0);

    // Read through file and store tenants' rent receipts in rentReceipts
    while (getline(inputFile, line)) {
        row.clear();
        stringstream s(line);

        i = 0;
        while (getline(s, data, ',')) {
            i++;

            if(i == 1) {        // Store user ID
                row.push_back(data);

            } else if(i == 3) {
                if(data == "true") {
                    row.push_back(data);
                } else {
                    break;
                }

            } else if(i == 4) {             // Store all rent receipts for one tenant in one row
                stringstream d(data);

                while (getline(d, record, '&')) {
                    stringstream rec(record);

                    while (getline(rec, field, ';')) {
                        row.push_back(field);
                    }


                }

                rentReceipts.push_back(row);

            } else {
                continue;
            }
        }
    }

    inputFile.close(); */
}






void Rent::writeRentReceipt(int uid, float amount, string refNum) {
    
    fstream inputFile, outputFile;
    inputFile.open("RentReceipts.csv", ios::in);
    outputFile.open("Test.csv", ios::out);

    string str, data, receipt, field;
    int i, j, user_ID_in_file;

    while(getline(inputFile, str)) {
        stringstream s(str);

        i = 0;
        while (getline(s, data, ',')) {
            // Tenant ID
            if(i == 0) {
                user_ID_in_file = stoi(data);
                outputFile << data << ",";
                i++;
            
            } else if(i < 3) {              //Payment method, inProgress status
                outputFile << data << ",";
                i++;

            } else {
                if(uid == user_ID_in_file) {
                    int pos = data.find_last_of("&");

                    string d = data.substr(0, (pos + 1));
                    outputFile << d;                    


                    string strpos = data.substr((pos + 1));

                    stringstream sp(strpos);

                    j = 0;
                    while (getline(sp, receipt, ';')) {
                        j++;

                        if(j == 2)
                            outputFile << refNum << ";";
                        else if(j == 4)
                            outputFile << to_string(formatMoney(amount)) << "\n";
                        else 
                            outputFile << receipt << ";";
                    }

                } else {
                    outputFile << data << "\n";
                }                
            }

        }
    }

    inputFile.close();
    outputFile.close();
}

