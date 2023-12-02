/* Prologue
 * Name: Tenant Class
 * Description: Creates and modifies Tenant's file
 * Contributors: Crischelle Polley
 * Date created: Nov 13 2023
 * Date last modified: Dec 1 2023
*/


#pragma once
#ifndef TENANT_H
#define TENANT_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Tenant {
    private:
    string username;
    string password;
    string userType;        // Cannot be changed by tenant
    int userID;             // Cannot be changed by tenant
    string name;            // Cannot be changed by tenant
    string phoneNum;
    string email;
    string aptNum;             // Cannot be changed by tenant


    public:
    Tenant() {
        username = "";
        password = "";
        userType = "";
        userID = -1;
        name = "";
        phoneNum = "";
        email = "";
        aptNum = "";
    }

    // Constructor will call readTenantInfo and
    // set all attributes to tenant info in 
    // sample-data-file based on username and 
    // password entered from user login 
    Tenant(int uid) {
        userID = uid;
        readTenantInfo();
    }

    // Destructor will call writeTenantInfo and write all
    // attributes to sample-data-file and is evoked by 
    // exitMenu() in TenantUI::displayTenantAccountMenu
    ~Tenant() {
        cout << "This is Tenant destructor\n";
        writeTenantInfo();
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

    string getAptNum() const
    {
        return aptNum;
    }

    string setAptNum(const string& an)
    {
        aptNum = an;
    }

    void readTenantInfo();

    void writeTenantInfo();

};

#endif
