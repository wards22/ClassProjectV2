/* Prologue
 * Name: General UI Class
 * Description: Allows users to login which will direct them to different
 *              UIs based on their type (staff, tenant), or allows visitors
 *              to view apartment info and/or submit an application
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Nov 27 2023
*/

#pragma once
#ifndef GENERAL_UI_H
#define GENERAL_UI_H

#include <string>

using namespace std;

class GeneralUI {

public:

    static void displayGeneralUI();

    static bool validateUser(string username, string password);

    static int getUserID(string username);

    static string getUserType(int userID);

    static void viewFloorPlans();

    static void viewApplication();

    static void viewApartmentComplexInfo();
};

#endif