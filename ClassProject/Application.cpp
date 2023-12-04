/* Prologue
 * Name: Application
 * Description: Implementation of App.h
 * Contributors: Scott Ward/LaShante StCyr
 * Date created: Nov 25 2023
 * Date last modified: Dec 3 2023
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

#include "Application.h"

bool Application::isValidDate() const {

    if (year < 0 || month < 1 || month > 12)
        return false;

    if (day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            if (day > 29)
                return false;
        } else {
            if (day > 28)
                return false;
        }
    }
    return true;
}

string Application::formatDate() const {
    ostringstream oss;
    
    oss << setfill('0') << setw(2) << month << "/" << setw(2) << day << "/" << setw(4) << year;
    
    return oss.str();
}


bool Application::isApplicantAdult() {

    struct tm current_time;
    time_t now = time(0);
    localtime_s(&current_time, &now);

    int currentMonth = current_time.tm_mon + 1;
    int currentDay = current_time.tm_mday;
    int currentYear = current_time.tm_year + 1900;

    int age = currentYear - year;
    if (currentMonth < month || (currentMonth == month && currentDay < day)) {
        age--;
    }
    
    return age >= 18;
}

void Application::readStatus(string e) {
    fstream applicationFile;
    applicationFile.open("Applications.csv", ios::in);

    string line, data, ref_ID_in_file;
    vector<string> row;

    while (getline(applicationFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (e == row[1]) {
            this->name = row[0];
            this->email = row[1];
            this->phoneNumber = row[2];
            this->floorPlanRequested = row[3];
            this->dateSubmitted = row[4];
            this->status = row[5];
            applicationFile.close();
            break;
        }
    }
}
void Application::writeApplicationInfo() {
    fstream outputFile;

    outputFile.open("Applications.csv", ios::out | ios::app);
    
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);

    dateSubmitted = to_string(1 + newtime.tm_mon) + "/" + to_string(newtime.tm_mday) + "/" + to_string(1900 + newtime.tm_year);

    outputFile << "\n" << name << "," << email << "," << phoneNumber << "," << floorPlanRequested << "," << dateSubmitted << "," << status;

    outputFile.close();
}

void Application::writeUpdatedStatus(string eMail, string str) {
    fstream applicationFile, newApplicationFile;
    applicationFile.open("Applications.csv", ios::in);
    newApplicationFile.open("NewApplications.csv", ios::out);
    string line, data;
    int i;
    vector<string> row;

    while (getline(applicationFile, line)) {

        row.clear();

        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        int row_size = row.size();

        if (eMail == row[1]) {



            row[5] = str;



            if (!applicationFile.eof()) {
                for (i = 0; i < row_size - 1; i++) {

                    // write the updated data 
                    // into a new file 'NewUserRecords.csv' 
                    // using fout 
                    newApplicationFile << row[i] << ",";
                }

                newApplicationFile << row[row_size - 1] << "\n";
            }
        }
        else {
            if (!applicationFile.eof()) {
                for (i = 0; i < row_size - 1; i++) {

                    // writing other existing records 
                    // into the new file using fout. 
                    newApplicationFile << row[i] << ",";
                }

                // the last column data ends with a '\n' 
                newApplicationFile << row[row_size - 1] << "\n";
            }
        }
        if (applicationFile.eof())
            break;


    }

    applicationFile.close();
    newApplicationFile.close();

    remove("Applications.csv");
    rename("NewApplications.csv", "Applications.csv");
}
