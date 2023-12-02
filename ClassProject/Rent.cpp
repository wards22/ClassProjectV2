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

using namespace std;
using chrono::system_clock;


string Rent::getDate() const {
    // Read current date and time from system
    system_clock::time_point tp = system_clock::now();


    // Convert system_clock object to ctime object to format dateTime
    time_t tt = system_clock::to_time_t(tp);

    // char * of size 26 to fit date and time of tt
    const int dSize = 26;
    char d[dSize];

    // ctime_s(char *, char * size, time_t *)
    // when only dt is used, it acts as char *
    // string of tt will be stored in dt
    ctime_s(d, dSize, &tt);

    return formatDate(d);
}

string Rent::formatDate(const char* d) const {
    // Copy char * to string
    string s = d;

    // Remove null terminator
    s = s.substr(0, 24);

    // Format dt to WWW MMM DD YYYY HH:MM:SS
    s = s.substr(0, 11) + s.substr(20, 24);

    return s;
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
            receipt = row[2];
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

}

void Rent::editRentReceipt() {

}

void Rent::deleteRentReceipt() {

}