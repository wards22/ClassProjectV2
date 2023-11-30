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
    static void displayMainMenu(int user_ID);

    static void displayStaffAccountMenu(int user_ID);

    static void displayTenantInfoMenu();

    static void displayApartmentInfoMenu();

    static void displayRentMenu();

    static void displayMaintenanceRequestMenu();

    static void displayNotifications();

    static void displayLease();

    static void viewApplications();

    static void logout();
};

#endif