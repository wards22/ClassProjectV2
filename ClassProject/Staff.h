/* Prologue
 * Name: Staff Class
 * Description: Staff class for holiding long term info on staff
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Dec 2 2023
*/

#pragma once
#ifndef STAFF_H
#define STAFF_H

#include <string>

using namespace std;



class Staff {

private:
    string username = "Default";
    string password = "password";
    string userType = "Staff";
    int userID = 0;
    string name = "My Name";
    string phoneNum = "123-456-7890";
    string email = "johndoe@uhdapartments.com";


public:

    Staff();
    Staff(int user_ID);

    ~Staff();

    string getUsername() const;

    void setUsername(const string&);

    string getPassword() const;

    void setPassword(const string&);

    string getUserType() const;

    void setUserType(const string&);

    int getUserID() const;

    void setUserID(const int&);

    string getName() const;

    void setName(const string&);

    string getPhoneNum() const;

    void setPhoneNum(const string&);

    string getEmail() const;

    void setEmail(const string& e);

    void writeStaffInfo(int, int, string);

    void readStaffInfo(int);

    static void createNewTenantFromLease(string, string, string, string, string);
};

#endif