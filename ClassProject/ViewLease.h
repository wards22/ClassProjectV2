/* Prologue
 * Name: View Staff Info Class
 * Description: Displays information about leases
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Nov 26 2023
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#pragma once
#ifndef VIEW_LEASE_H
#define VIEW_LEASE_H

class ViewLease {

    public:

    static void displayLeaseForTenant(int);

    static vector<string> modifyLease();

    static vector<string> createLease();
};

#endif