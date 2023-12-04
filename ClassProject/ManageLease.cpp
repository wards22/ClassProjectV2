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
		//Show all leases
		//Allow Staff to pick one
		//Update that lease
		
		vector<string> leaseUpdate;
		leaseUpdate = ViewLease::modifyLease();

		Lease lease(leaseUpdate[0]);
		lease.setEndingDate(leaseUpdate[1]);
		lease.setRentAmount(leaseUpdate[2]);
		lease.setLeaseText(leaseUpdate[3]);
		lease.writeLease(lease.getReferenceNum(), lease.getLeaseText());
	}
	else if (n == 2) {
		//show approved applicants
		//show vacant apartments
		//assign that applicant to the apartment

		vector<string> newLease;
		newLease = ViewLease::createLease();

		Lease lease(newLease);
		lease.createNewlease();
	}
}