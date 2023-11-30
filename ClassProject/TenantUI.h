/* Prologue
 * Name: Tenant UI Class
 * Description: Directs tenant to different
 *              features of the Apartment Services System
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Nov 29 2023
*/

#pragma once
#ifndef TENANT_UI_H
#define TENANT_UI_H

#include <string>
#include <iostream>

using namespace std;


static class TenantUI {
public:
<<<<<<< HEAD
    static void displayTenantMenu(int);

    static void displayTenantAccountMenu(int);

    static void displayRentMenu(int);

    static void displayMaintenanceMenu(int);

    static void displayNotificationsMenu(int);

    static void displayLeaseMenu(int);

    static void displayApplicationMenu(int);
=======
    static void displayMainMenu();

    static void displayTenantAccountMenu();

    static void displayRentMenu();

    static void displayMaintenanceRequestMenu();

    static void displayNotifications();

    static void displayLease();

    static void displayApplication();
>>>>>>> 6c5d6ac1803db2a95e4cf9291e1cbfcc573f85e2

    static void exit();
};

#endif