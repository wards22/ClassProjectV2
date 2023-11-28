/* Prologue
 * Name: Manage Maintenance Request Class
 * Description: Allows tenants to submit a new maintenance requests
 *              And allows staff to view/manage requests of tenants
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Nov 26 2023
*/

#pragma once
#ifndef MANAGE_MAINTENANCE_H
#define MANAGE_MAINTENANCE_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


class ManageMaintenance {
public:
    void manageMaintenanceForTenant();

    void manageMaintenanceForStaff();

};


#endif