#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Lease.h"
#include "ManageLease.h"
#include "ViewLease.h"

void ManageLease::manageLeaseForTenant(int uid) {
	int id = uid;
	ViewLease::displayLeaseForTenant(id);
}

void ManageLease::manageLeaseForStaff(int n) {

	if (n == 1) {
		vector<string> leaseUpdate;
		//Show Open Requests
		//Allow Staff to pick one
		//Update that Request
		leaseUpdate = ViewLease::modifyLease();
		cout << "Refernce Number: " << leaseUpdate[0] << endl;
		cout << "Lease Text: " << leaseUpdate[3] << endl;
		Lease lease(leaseUpdate[0]);
		lease.setEndingDate(leaseUpdate[1]);
		lease.setRentAmount(leaseUpdate[2]);
		lease.setLeaseText(leaseUpdate[3]);
		lease.writeLease(lease.getReferenceNum(), lease.getLeaseText());
	}
}