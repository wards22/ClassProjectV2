/* Prologue
 * Name: Manage Tenant Account Class
 * Description: Controls which features of the Apartment
 *              Services System that a user can access
 *              depending on userType
 * Contributors: Crischelle Polley
 * Date created: Nov 16 2023
 * Date last modified: Nov 28 2023
*/

#pragma once
#ifndef MANAGE_TENANT_ACCOUNT_H
#define MANAGE_TENANT_ACCOUNT_H

#include <string>

using namespace std;

class ManageTenantAccount {
public:
    static void manageTenantAccountForTenant(int, int, string);

<<<<<<< HEAD
    static void manageTenantAccountForStaff(int, int);
=======
    void manageTenantAccountForStaff(int, int, string);
>>>>>>> 6c5d6ac1803db2a95e4cf9291e1cbfcc573f85e2

};

#endif