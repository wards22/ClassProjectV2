/* Prologue
 * Name: Manage Staff Class
 * Description: Allows to staff to make changes to data
 * Contributors: Scott Ward
 * Date created: Nov 25 2023
 * Date last modified: Nov 29 2023
*/

#include <iostream>

#include "ManageStaff.h"
#include "Staff.h"

void ManageStaff::manageStaff(int n, int user_ID, string str) {

	Staff staff(user_ID);

	if (n == 1) {
		cout << "User ID: " << staff.getUserID() << endl;
		cout << "Username: " << staff.getUsername() << endl;
		cout << "Password: " << staff.getPassword() << endl;
		cout << "Account Type: " << staff.getUserType() << endl;
		cout << "Name: " << staff.getName() << endl;
		cout << "Phone Number: " << staff.getPhoneNum() << endl;
		cout << "Email: " << staff.getEmail() << endl;
	} else if (n == 2) {
		staff.setUsername(str);
		staff.writeStaffInfo(staff.getUserID(), 1, staff.getUsername());
	} else if (n == 3) {
		staff.setPassword(str);
		staff.writeStaffInfo(staff.getUserID(), 2, staff.getPassword());
	} else if (n == 4) {
		staff.setPhoneNum(str);
		staff.writeStaffInfo(staff.getUserID(), 5, staff.getPhoneNum());
	} else if (n == 5) {
		staff.setEmail(str);
		staff.writeStaffInfo(staff.getUserID(), 6, staff.getEmail());
	}
}