/* Prologue
 * Name: Manage Tenant Account Methods
 * Description: Implementation file for ManageTenantAccount
 * Contributors: Crischelle Polley
 * Date created: Nov 27 2023
 * Date last modified: Nov 28 2023
*/

#pragma once
#ifndef MANAGE_RENT_H
#define MANAGE_RENT_H

#include <string>

using namespace std;

class ManageRent {

    public:
        static void manageRentForTenant(int, int, string);

        static void manageRentForStaff(int, int);

};

#endif