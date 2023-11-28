/* Prologue
 * Name: Tenant UI Class
 * Description: Directs tenant to different
 *              features of the Apartment Services System
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Nov 16 2023
*/

#pragma once
#ifndef TENANT_UI_H
#define TENANT_UI_H

#include <string>
#include <iostream>

using namespace std;


class TenantUI {
public:
    void displayMainMenu();

    void displayTenantAccountMenu();

    void displayRentMenu();

    void displayMaintenanceRequestMenu();

    void displayNotifications();

    void displayLease();

    void displayApplication();

    void exit();
};

#endif