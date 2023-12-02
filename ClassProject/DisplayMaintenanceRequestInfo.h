/* Prologue
 * Name: Display Maintenance Request Infor
 * Description: Displays information about Maintenance Requests based on user type
 * Contributors: Scott Ward
 * Date created: Dec 1 2023
 * Date last modified: Dec 1 2023
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#pragma once
#ifndef DISPLAY_MAINTENANCE_REQUEST_INFO_H
#define DISPLAY_MAINTENANCE_REQUEST_INFO_H

class DisplayMaintenanceRequestInfo {

    public:

    static void displayMaintenanceForTenant(int);

    static vector<string> createMaintenanceRequest(int);

    static vector<string> editMaintenanceRequest(int);

    static void displayAllMaintenanceForStaff();

    static void displayOpenMaintenceForStaff();

    static void displayClosedMaintenanceForStaff();

    static vector<string> updateMaintenanceStatusForStaff();

};

#endif