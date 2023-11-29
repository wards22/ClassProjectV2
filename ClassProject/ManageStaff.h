/* Prologue
 * Name: Manage Staff Class
 * Description: Allows staff to make changes to some parts
 *              of their account
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Nov 26 2023
*/

#pragma once
#ifndef MANAGE_STAFF_H
#define MANAGE_STAFF_ACCOUNT_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class ManageStaff {
public:
    void manageStaff(int n, int user_ID, string str);

};


#endif