/* Prologue
 * Name: Rent Class
 * Description: Creates and modifies tenant's Rent file
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Nov 29 2023
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

float Rent::payRentReceipt(const float& r) {
    remainingBalanceDue = balanceDue - r;
    return formatMoney(remainingBalanceDue);
}

void Rent::readRentReceipt(int uid) {
    fstream inputFile;
    inputFile.open("RentReceipts.csv", ios::in);

    string line, data, receipt, record, field;
    int user_ID_in_file;
    vector<string> row, rent;

    while (getline(inputFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        user_ID_in_file = stoi(row[0]);

        if (uid == user_ID_in_file) {
            this->paymentMethod = row[1];
            if(row[2] == "true")
                this->isInProgress = true;
            else
                this->isInProgress = false;

            receipt = row[3];
            stringstream r(receipt);

            // Get each rent receipt and store it in rentReceipts vector
            while(getline(r, record, '&')) {
                rent.clear();
                stringstream rec(record);

                while(getline(rec, field, ';')) {
                    rent.push_back(field);
                }

                rentReceipts.push_back(rent);

            }

            inputFile.close();
            break;
        }
    }
}

void Rent::writeRentReceipt(int uid) {

}

void Rent::createRentReceipt() {
    // Check if rent receipt is in progress
    if(isInProgress == true) {
        cout << "A rent receipt is waiting to be posted.\n"
            << "Go to Edit Rent Receipt to edit current rent receipt.\n\n";
    } else {
        date = "";
        referenceNum = "";
        description = "";
        amount = -1;

        cout << "Enter the current month (MM): ";
        cin >> month;
        cout << "Enter the current month (DD): ";
        cin >> day;
        cout << "Enter the current month (YYYY): ";
        cin >> year;
        setDate(month, day, year);

        cout << "Enter the reference number (LLL NNNN): ";
        getline(cin, referenceNum);

        cout << "Enter the description: ";
        getline(cin, description);

        cout << "Enter the amount: $";
        string temp;
        getline(cin, temp);
        amount = stof(temp);

        //cout << 
    }
}

void Rent::editRentReceipt() {
    // Code to edit receipt here

    cout << "Would you like to submit receipt?";
}

void Rent::deleteRentReceipt() {

}

void Rent::submitReceipt() {

}