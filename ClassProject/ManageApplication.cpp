#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Application.h"
#include "ManageApplication.h"
#include "ViewApplication.h"

void ManageApplication::manageApplicationForStaff(int n) {
	if (n == 1) {
		//display all applications
		ViewApplicationInfo::reviewAllApplications();
	}
	else if (n == 2) {
		//display applications marked as 'pending review'
		ViewApplicationInfo::reviewOpenApplications();
	}
	else if (n == 3) {
		//display applications marked as 'approved' or 'denied
		ViewApplicationInfo::reviewClosedApplications();
	}
	else if (n == 4) {
		//update open applications
		vector<string> applicationUpdates;
		//Show Open Requests
		//Allow Staff to pick one
		//Update that Request
		applicationUpdates = ViewApplicationInfo::updateApplicationStatus();

		Application application(applicationUpdates[0]);
		application.setStatus(applicationUpdates[1]);
		application.writeUpdatedStatus(application.getEmail(), application.getStatus());
	}
}
