#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Maintenance.h"
#include "ManageMaintenance.h"
#include "DisplayMaintenanceRequestInfo.h"

void ManageMaintenance::manageMaintenanceForTenant(int n, int uID) {
	if (n == 1) {
		DisplayMaintenanceRequestInfo::displayMaintenanceForTenant(uID);
	}
	else if (n == 2) {
		//create maintenance request
		vector<string> maintenanceUpdates;
		maintenanceUpdates = DisplayMaintenanceRequestInfo::createMaintenanceRequest(uID);
		MaintenanceRequest maintenance(maintenanceUpdates[2]);
		maintenance.setTenantUserID(maintenanceUpdates[0]);
		maintenance.setTenantName(maintenanceUpdates[1]);
		maintenance.setReferenceNum(maintenanceUpdates[2]);
		maintenance.setDate(maintenanceUpdates[3]);
		maintenance.setDescription(maintenanceUpdates[4]);
		maintenance.setStatus(maintenanceUpdates[5]);
		maintenance.writeStatus(maintenance.getTenantUserID(), maintenance.getTenantName(), maintenance.getReferenceNum(),
			maintenance.getDate(), maintenance.getDescription(), maintenance.getStatus());

	}
	else if (n == 3) {
		//Cancel maintenance requests
		vector<string> maintenanceUpdates;
		maintenanceUpdates = DisplayMaintenanceRequestInfo::editMaintenanceRequest(uID);
		MaintenanceRequest maintenance(maintenanceUpdates[0]);
		maintenance.setStatus(maintenanceUpdates[1]);
		maintenance.writeStatus(maintenance.getReferenceNum(), maintenance.getStatus());
	}
}

void ManageMaintenance::manageMaintenanceForStaff(int n) {

	if (n == 1) {
		//display all maintenance requests
		DisplayMaintenanceRequestInfo::displayAllMaintenanceForStaff();
	}
	else if (n == 2) {
		//display maintenance requests marked as open
		DisplayMaintenanceRequestInfo::displayOpenMaintenceForStaff();
	}
	else if (n == 3) {
		//display all maintenance requests marked as closed
		DisplayMaintenanceRequestInfo::displayClosedMaintenanceForStaff();
	}
	else if (n == 4) {
		vector<string> maintenanceUpdates;
		//Show Open Requests
		//Allow Staff to pick one
		//Update that Request
		maintenanceUpdates = DisplayMaintenanceRequestInfo::updateMaintenanceStatusForStaff();
		cout << "Refernce Number: " << maintenanceUpdates[0] << endl;
		cout << "New Status: " << maintenanceUpdates[1] << endl;
		MaintenanceRequest maintenance(maintenanceUpdates[0]);
		maintenance.setStatus(maintenanceUpdates[1]);
		maintenance.writeStatus(maintenance.getReferenceNum(), maintenance.getStatus());
	}
}