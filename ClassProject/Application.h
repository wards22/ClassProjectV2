#pragma once
#ifndef APARTMENT_APPLICATION_H
#define APARTMENT_APPLICATION_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;

class Application {
    private:
    int month;
    int day;
    int year;

    public:
    Application(int m, int d, int y) : month(m), day(d), year(y) {}

    bool isValidDate() const {
        if (year > 2006 || year < 0 || month < 1 || month > 12)
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

    string formatDate() const {
        ostringstream oss;
        oss << setfill('0') << setw(2) << month << "/" << setw(2) << day << "/" << setw(4) << year;
        return oss.str();
    }

    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }
};

bool isApplicantAdult(const DateOfBirth& dob);

#endif