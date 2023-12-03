/* Prologue
 * Name: Application
 * Description: Application Entity class for storing long term info
 * Contributors: Scott Ward/LaShante StCyr
 * Date created: Nov 25 2023
 * Date last modified: Dec 3 2023
*/

#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>

using namespace std;

class Application {

private:
    string name;
    string email;
    string phoneNumber;
    string floorPlanRequested;
    string dateSubmitted;
    string status;
    int month;
    int day;
    int year;

public:

    Application(int m, int d, int y) : month(m), day(d), year(y) {}
    Application(string n, string e, string pn, string fp, int m, int d, int y) 
        : name(n), email(e), phoneNumber(pn), floorPlanRequested(fp), month(m), day(d), year(y) {}

    Application(string e) {
        email = e;
        readStatus(email);
    }

    bool isValidDate() const;

    string formatDate() const;
    string getEmail() const { return email; }
    void setEmail(const string& em) { email = em; }
    string getStatus() const { return status; }
    void setStatus(const string& st) { status = st; }
    void setFloorPlanRequested(const string& fp) { floorPlanRequested = fp; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    bool isApplicantAdult();

    void readStatus(string);
    void writeApplicationInfo();
    void writeUpdatedStatus(string, string);
};
#endif