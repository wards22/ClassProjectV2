/* Prologue
 * Name: View Apartment Info Class
 * Description: Implementation of ViewApartmentInfo.h
 * Contributors: Scott Ward
 * Date created: Nov 29 2023
 * Date last modified: Nov 29 2023
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "ViewApartmentInfo.h"

void ViewApartmentInfo::displayFloorPlans() {
	string data;

	fstream inputFile("FloorPlan.txt");

	while (getline(inputFile, data)) {
		cout << data;
	}

	inputFile.close();
}

void ViewApartmentInfo::displayApartmentComplexInfo() {

}