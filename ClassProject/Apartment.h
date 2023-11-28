#pragma once
#ifndef APARTMENT_H
#define APARTMENT_H

#include <iostream>
#include <string>
using namespace std;

class Apartment {
private:
    std::string apartmentName = " ";
    int apartmentNumber = 0;
    int numBedrooms = 0;
    int numBathrooms = 0;
    double squareFootage = 0;
    double rentAmount = 0;

public:
    Apartment(std::string name, int number, int bedrooms, int bathrooms, double sqFootage, double rent) {
        apartmentName = name;
        apartmentNumber = number;
        numBedrooms = bedrooms;
        numBathrooms = bathrooms;
        squareFootage = sqFootage;
        rentAmount = rent;
    }

    static void displayDetails() {
    }
};

#endif