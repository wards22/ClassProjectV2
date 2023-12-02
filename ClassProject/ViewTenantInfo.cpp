/* Prologue
 * Name: View Tenant Info Class
 * Description: Creates and modifies tenant's Rent file
 * Contributors: Crischelle Polley
 * Date created: Dec 2 2023
 * Date last modified: Dec 2 2023
*/

#include "ViewTenantInfo.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void ViewTenantInfo::displayTenantAccount(const string& un, const string& pw, const string& n,
									const string& pn, const string& e, const string& an)
{
	cout << left << setw(40) << "Tenant Account Information " << endl;
	cout << left << setw(40) << "-------------------------------" << endl;
	cout << left << setw(10) << "Username:    " << setw(30) << un << endl;
	cout << left << setw(10) << "Password:    " << setw(30) << pw << endl;
	cout << left << setw(10) << "Name:        " << setw(30) << n << endl;
	cout << left << setw(10) << "Phone #:     " << setw(30) << pn << endl;
	cout << left << setw(10) << "Email:       " << setw(30) << e << endl;
	cout << left << setw(10) << "Apt #:       " << setw(30) << an << endl;

	cout << endl;
}