#include <iostream>
#include <string>
#include "Apartment.h"

using namespace std;


/*

class Apartment {
private:
    string apartmentName;
    string apartmentAddress;
    int numBedrooms;
    int numBathrooms;
    double squareFootage;
    double rentAmount;
    string contactPhone;

public:
    Apartment(string name, string address, int bedrooms, int bathrooms, double sqFootage, double rent,
              string phone, string plan)
        : apartmentName(name), apartmentAddress(address), contactPhone(phone) {
        // Set number of bedrooms within the range of 1 to 3
        if (bedrooms >= 1 && bedrooms <= 3) {
            numBedrooms = bedrooms;
        } else {
            numBedrooms = 1; 
        }

        // Set number of bathrooms within the range of 1 to 3
        if (bathrooms >= 1 && bathrooms <= 3) {
            numBathrooms = bathrooms;
        } else {
            numBathrooms = 1; 
        }

        // Set square footage within the range of 600 to 1375
        if (sqFootage >= 600 && sqFootage <= 1375) {
            squareFootage = sqFootage;
        } else {
            squareFootage = 600; 
        }

        // Set rent amount within the range of 700 to 1700
        if (rent >= 700 && rent <= 1700) {
            rentAmount = rent;
        } else {
            rentAmount = 700; 
        }
    }

    void displayDetails() const {
        cout << "Apartment Name: " << apartmentName << endl;
        cout << "Apartment Address: " << apartmentAddress << endl;
        cout << "Bedrooms: 1, 2, 3 available" << endl;
        cout << "Bathrooms: 1, 2, 3 available" << endl;
        cout << "Square Footage: 600 - 1375 sq.ft." << endl;
        cout << "Rent Amount: $700 - $1700 per month" << endl;
        cout << "Contact Phone: " << contactPhone << endl;
        cout << "---------------------------------------------\n";
    }

};

int main() {
    
    Apartment apt("Gator Apartment", "123 Main St", 2, 2, 1000, 1200, "123-456-7890", "Floor plan description...");

    // Display apartment details
    apt.displayDetails();

    // View floor plan option
    cout << "Would you like to view the floor plan? (Y/N): ";
    char choice;
    cin >> choice;

}
*/
