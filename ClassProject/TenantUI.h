/* Prologue
 * Name: Tenant UI Class
 * Description: Directs tenant to different
 *              features of the Apartment Services System
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Dec 1 2023
*/

#pragma once
#ifndef TENANT_UI_H
#define TENANT_UI_H

using namespace std;


static class TenantUI {
    public:
    static void displayTenantMenu(int);

    static void displayTenantAccountMenu(int);

    static void displayRentMenu(int);

    static void displayMaintenanceMenu(int);

    static void displayNotificationsMenu(int);

    static void displayLeaseMenu(int);

    static void displayApplicationMenu(int);

    static void exit();
};

#endif