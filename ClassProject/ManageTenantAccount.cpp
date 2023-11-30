/* Prologue
 * Name: Manage Tenant Account Methods
 * Description: Implementation file for ManageTenantAccount
 * Contributors: Crischelle Polley
 * Date created: Nov 16 2023
 * Date last modified: Nov 22 2023
*/

#include "ManageTenantAccount.h"
#include "Tenant.h"

using namespace std;

void ManageTenantAccount::manageTenantAccountForTenant(int uid, int option, string s) {
    Tenant tenant(uid);

    // [1] View Account Information
    // This will access ViewTenantAccount boundary class
    if (option == 1) {
        // Print TenantAccount
    }

    // [2] Change Username
    else if (option == 2) {
        tenant.setUsername(s);
        //cout << "This is username: " << tenant.getUsername() << endl;
    }

    // [3] Change Password
    else if (option == 3) {
        tenant.setPassword(s);
        //cout << "This is password: " << tenant.getPassword() << endl;
    }

    // [4] Change Phone Number
    else if (option == 4) {
        tenant.setPhoneNum(s);
        //cout << "This is phone num: " << tenant.getPhoneNum() << endl;
    }

    // [5] Change Email
    else if (option == 5) {
        tenant.setEmail(s);
        //cout << "This is email: " << tenant.getEmail() << endl;
    }

}

void ManageTenantAccount::manageTenantAccountForStaff(int uid, int option) {

}