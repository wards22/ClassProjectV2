/* Prologue
 * Name: Apartment.h
 * Description: Apartment Entity class for storing long term info
 * Contributors: Scott Ward/LaShante StCyr
 * Date created: Nov 25 2023
 * Date last modified: Dec 3 2023
*/

#pragma once
#ifndef APARTMENT_H
#define APARTMENT_H

#include <iostream>
#include <string>
using namespace std;

class Apartment {
    private:
    string apartmentName;
    string apartmentNumber;
    string numBedrooms;
    string numBathrooms;
    string squareFootage;
    string rentAmount;
    string vacancy;

    public:
    Apartment(string name, string number, string bedrooms, string bathrooms, string sqFootage, string rent, string vacant)
        : apartmentName(name), apartmentNumber(number), numBedrooms(bedrooms), numBathrooms(bathrooms), 
        squareFootage(sqFootage), rentAmount(rent), vacancy(vacant) {}


    void writeApartmentInfo();
};

#endif /* APARTMENT_H */