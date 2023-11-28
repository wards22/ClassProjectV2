/* Prologue
 * Name: Staff Class
 * Description: Staff class for holiding long term info on staff
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Nov 25 2023
*/

#pragma once
#ifndef STAFF_H
#define STAFF_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;



class Staff {
    // Should probably use one of these as superclass for inheritance
private:
    string username;
    string password;
    string userType;
    int userID;
    string name;
    string phoneNum;
    string email;


public:
    //Modeled after tenant constructor/destructor. Need to figure out how to build one
    //from information in spreadsheet. May need to pull something from when the user logins
    Staff() {
        cout << "This is Staff's default constructor" << endl;
        readStaffInfo();
    }

    ~Staff() {
        cout << "This is Staff destructor\n";
        writeStaffInfo();
    }

    string getUsername() const
    {
        return username;
    }

    void setUsername(const string& un)
    {
        username = un;
    }

    string getPassword() const
    {
        return password;
    }

    void setPassword(const string& pw)
    {
        password = pw;
    }

    string getUserType() const
    {
        return userType;
    }

    void setUserType(const string& ut)
    {
        userType = ut;
    }

    int getUserID() const
    {
        return userID;
    }

    void setUserID(const int& uid)
    {
        userID = uid;
    }

    string getName() const
    {
        return name;
    }

    void setName(const string& n)
    {
        name = n;
    }

    string getPhoneNum() const
    {
        return phoneNum;
    }

    void setPhoneNum(const string& pn)
    {
        phoneNum = pn;
    }

    string getEmail() const
    {
        return email;
    }

    void setEmail(const string& e)
    {
        email = e;
    }

    void readStaffInfo() {
    }

    void writeStaffInfo() {

    }

};

#endif