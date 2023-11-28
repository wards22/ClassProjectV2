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


class StaffUI {
public:
    void displayMainMenu();

    void displayStaffAccountMenu();

    void displayTenantInfoMenu();

    void displayApartmentInfoMenu();

    void displayRentMenu();

    void displayMaintenanceRequestMenu();

    void displayNotifications();

    void displayLease();

    void viewApplications();

    void exitMenu();
};

#endif