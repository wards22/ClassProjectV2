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

private:
    string username = "Default";
    string password = "password";
    string userType = "Staff";
    int userID = 0;
    string name = "My Name";
    string phoneNum = "123-456-7890";
    string email = "johndoe@uhdapartments.com";


public:
    
    Staff() {
        cout << "This is Staff's default constructor" << endl;
    }
    //pulls user ID upon login, passes it to constructor and uses read
    //staff info to construct a staff object
    Staff(int user_ID) {
        userID = user_ID;
        readStaffInfo(userID);
    }
    
    ~Staff() {
        cout << "This is Staff destructor" << endl;
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

    void writeStaffInfo(int user_ID, int index, string str);

    void readStaffInfo(int user_ID);

};

#endif