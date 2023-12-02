/* Prologue
 * Name: View Tenant Info Class
 * Description: Creates and modifies tenant's Rent file
 * Contributors: Crischelle Polley
 * Date created: Dec 1 2023
 * Date last modified: Dec 2 2023
*/

#pragma once
#ifndef VIEW_TENANT_INFO_H
#define VIEW_TENANT_INFO_H

#include <string>

using namespace std;


class ViewTenantInfo {
	public:
	static void displayTenantAccount(const string& un, const string& pw, const string& n, 
									 const string& pn, const string& e, const string& an);

};

#endif