/* Prologue
 * Name: Tenant Class
 * Description: Creates and modifies Tenant's file
 * Contributors: Crischelle Polley
 * Date created: Nov 13 2023
 * Date last modified: Dec 2 2023
*/


#pragma once
#ifndef TENANT_H
#define TENANT_H

#include <string>
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
    Tenant();

    Tenant(int);

    //~Tenant();

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

    void setEmail(const string&);

    string getAptNum() const;

    void setAptNum(const string&);

    void readTenantInfo();

    void writeTenantInfo(int, int, string);

};

#endif
