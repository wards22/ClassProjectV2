/* Prologue
 * Name: Staff UI Class
 * Description: Allows staff to view various information concerning tenants
 *              and directs them to make changes to tenant, apartments, or
 *              fellow staff account
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Nov 26 2023
*/

#pragma once
#ifndef STAFF_UI_H
#define STAFF_UI_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

#include "TenantUI.h"
#include "ManageStaff.h"


class StaffUI {
    public:
    static void displayMainMenu(int);

    static void displayStaffAccountMenu(int);

    static void displayTenantInfoMenu(int);

    static void displayApartmentInfoMenu(int);

    static void displayRentMenu(int);

    static void displayMaintenanceRequestMenu(int);

    static void displayNotifications(int);

    static void displayLease(int);

    static void viewApplications(int);

    static void logout();
};

#endif