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
            }
            else {
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

bool isApplicantAdult(const Application& dob) {
    
    auto const now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
#pragma warning(suppress : 4996)
    tm current_time = *localtime(&now_c);

    int currentMonth = current_time.tm_mon + 1;
    int currentDay = current_time.tm_mday;
    int currentYear = current_time.tm_year + 1900;

    int age = currentYear - dob.getYear();
    if (currentMonth < dob.getMonth() || (currentMonth == dob.getMonth() && currentDay < dob.getDay())) {
        age--;
    }
    return age >= 18;
}
/*
int main() {
    string name, phoneNumber, email;
    int year, month, day;

    cout << "Welcome to the apartment application!" << endl;

    cout << "Please enter your name: ";
    getline(cin, name);

    cout << "Please provide your phone number: ";
    cin >> phoneNumber;

    // Validate phone number length
    while (phoneNumber.length() != 10) {
        cout << "Invalid phone number length. Please enter a 10-digit number: ";
        cin >> phoneNumber;
    }

    cout << "Please enter your email address: ";
    cin >> email;

    bool dobValid = false;
    while (!dobValid) {
        cout << "Please enter your date of birth in the format MM/DD/YYYY: ";
        string dobInput;
        cin >> dobInput;

        // Extract month, day, and year from input string
        istringstream(dobInput.substr(0, 2)) >> month;
        istringstream(dobInput.substr(3, 2)) >> day;
        istringstream(dobInput.substr(6, 4)) >> year;

        // Create DateOfBirth object and validate the date
        DateOfBirth dob(year, month, day);

        if (!dob.isValidDate()) {
            cout << "Invalid date of birth. Please try again: " << endl;
        }
        else {
            dobValid = true;
            if (!isApplicantAdult(dob)) {
                cout << "Sorry, only individuals that are 18 years of age and older can apply." << endl;
                return 1; // Exit the program due to age restriction
            }
        }
    }

    cout << "Thank you for your application, " << name << "!" << endl;
    // Review of the application
    cout << "Here is a review of your application:" << endl;
    cout << "------------------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Email Address: " << email << endl;
    cout << "Date of Birth: " << setw(2) << setfill('0') << month << "/" << setw(2) << day << "/" << setw(4) << year << endl;

    // Further processing of the application...

    return 0;
}
*/