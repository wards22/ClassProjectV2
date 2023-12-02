/* Prologue
 * Name: Manage Lease Class
 * Description: Allows tenants to view their current lease
 *              And allows staff to view/modify/create leases
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Nov 26 2023
*/

#pragma once
#ifndef MANAGE_LEASE_H
#define MANAGE_LEASE_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


class ManageLease {
    public:
    
    static void manageLeaseForTenant(int);

    static void manageLeaseForStaff(int);

};


#endif