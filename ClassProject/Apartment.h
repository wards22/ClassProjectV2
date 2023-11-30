#pragma once
#ifndef APARTMENT_H
#define APARTMENT_H

#include <iostream>
#include <string>

class Apartment {
private:
    std::string apartmentName;
    std::string apartmentAddress;
    int numBedrooms;
    int numBathrooms;
    double squareFootage;
    double rentAmount;
    std::string contactPhone;

public:
    Apartment(std::string name, std::string address, int bedrooms, int bathrooms, double sqFootage, double rent,
              std::string phone, std::string plan);

    void displayDetails() const;
};

#endif /* APARTMENT_H */
