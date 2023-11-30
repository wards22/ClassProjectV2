/* Prologue
 * Name: Manage Tenant Account Class
 * Description: Controls which features of the Apartment
 *              Services System that a user can access
 *              depending on userType
 * Contributors: Crischelle Polley
 * Date created: Nov 16 2023
 * Date last modified: Nov 21 2023
*/

#pragma once
#ifndef MANAGE_TENANT_ACCOUNT_H
#define MANAGE_TENANT_ACCOUNT_H

#include <string>

using namespace std;

class ManageTenantAccount {
public:
    void manageTenantAccountForTenant(int, string);

    void manageTenantAccountForStaff(int, int, string);

};

#endif