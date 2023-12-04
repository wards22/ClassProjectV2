/* Prologue
 * Name: Apartment.cpp
 * Description: Implemention file for apartments.h
 * Contributors: Scott Ward/LaShante StCyr
 * Date created: Nov 25 2023
 * Date last modified: Dec 3 2023
*/

#include <iostream>
#include <fstream>

#include "Apartment.h"

using namespace std;


void Apartment::writeApartmentInfo() {
    fstream apartmentFiles;

    apartmentFiles.open("ApartmentRecords.csv", ios::out | ios::app);

    apartmentFiles << this->apartmentName << "," << this->apartmentNumber << "," << this->numBedrooms << ","
        << this->numBathrooms << "," << this->squareFootage << "," << this->rentAmount << ","
        << this->vacancy << "\n";

    apartmentFiles.close();
}
