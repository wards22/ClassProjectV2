/* Prologue
 * Name: Manage Apartment Class
 * Description: Implmentation of Manage Apartments
 * Contributors: Scott Ward
 * Date created: Nov 29 2023
 * Date last modified: Dec 3 2023
*/

#include "ManageApartment.h"
#include "ViewApartmentInfo.h"


void ManageApartment::addVacantApartment() {
}

void ManageApartment::removeVacantApartment() {
}

void ManageApartment::displayApartments(int n) {

	if (n == 1) {
		ViewApartmentInfo::displayFloorPlans();
	}
	else if (n == 2) {
		ViewApartmentInfo::displayVacantApartments();
	}
	else if (n == 3) {
		ViewApartmentInfo::displayInhabitedApartments();
	}

}
