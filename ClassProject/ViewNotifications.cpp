/* Prologue
 * Name: View Notifications Implementation file
 * Description: Creates and modifies tenant's Rent file
 * Contributors: Crischelle Polley
 * Date created: Dec 1 2023
 * Date last modified: Dec 3 2023
*/


#include "ViewNotifications.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void ViewNotifications::displayNotifications(const vector<vector<string>>& notifications)
{
	cout << left << setw(40) << "Notifications" << endl;
	cout << left << setw(40) << "-------------------------------" << endl;

	for (auto i = notifications.begin(); i != notifications.end(); i++) {
		for (auto j = i->begin(); ;) {
			cout << left << setw(16) << "UserID:" << setw(30) << *j << endl;
			// Date Posted
			cout << left << setw(16) << "Date Posted: " << setw(30) << *(j + 4) << endl << endl;
			// Title
			cout << left << *(j + 2) << endl << endl;
			// Content
			cout << left << setw(100) << *(j + 3) << endl << endl;
			cout << left << setw(40) << "-------------------------------" << endl;
			break;
		}
		cout << endl;
	}

}