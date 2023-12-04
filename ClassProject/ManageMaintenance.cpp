#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Maintenance.h"
#include "ManageMaintenance.h"
#include "DisplayMaintenanceRequestInfo.h"

void ManageMaintenance::manageMaintenanceForTenant() {

}

void ManageMaintenance::manageMaintenanceForStaff(int n) {

	if (n == 1) {
		//display all maintenance requests
		DisplayMaintenanceRequestInfo::displayAllMaintenanceForStaff();
	} else if (n == 2) {
		//display maintenance requests marked as open
		DisplayMaintenanceRequestInfo::displayOpenMaintenceForStaff();
	} else if (n == 3) {
		//display all maintenance requests marked as closed
		DisplayMaintenanceRequestInfo::displayClosedMaintenanceForStaff();
	} else if (n == 4) {
		vector<string> maintenanceUpdates;
		//Show Open Requests
		//Allow Staff to pick one
		//Update that Request
		maintenanceUpdates = DisplayMaintenanceRequestInfo::updateMaintenanceStatusForStaff();
		cout << "Reference Number: " << maintenanceUpdates[0] << endl;
		cout << "New Status: " << maintenanceUpdates[1] << endl;
		MaintenanceRequest maintenance(maintenanceUpdates[0]);
		maintenance.setStatus(maintenanceUpdates[1]);
		maintenance.writeStatus(maintenance.getReferenceNum(), maintenance.getStatus());
	}
}