/* Prologue
 * Name: View Application Info Class
 * Description: Allows a user to enter information
 *				to submit an application
 * Contributors: Scott Ward
 * Date created: Dec 3 2023
 * Date last modified: Dec 3 2023
*/

#pragma once
#ifndef VIEW_APPLICATION_INFO_H
#define VIEW_APPLICATION_INFO_H

class ViewApplicationInfo {

public:

	static void submitApplication();
	static void reviewAllApplications();
	static void reviewOpenApplications();
	static void reviewClosedApplications();
	static vector<string> updateApplicationStatus();

};

#endif