#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct FloorPlan {
    std::string name;
};

struct RentPrices {
    int bedrooms;
    double price;
};

struct Vacancies {
    int bedrooms;
    bool available;
};

int main() {
    // Read floor plan information from a file
    std::ifstream floorPlanFile("ApartmentComplexInfo.txt");
    
    if (!floorPlanFile.is_open()) {
        std::cerr << "Error: Unable to open the floor plan file." << std::endl;
        return 1;
    }

    FloorPlan floorPlan;
    std::getline(floorPlanFile, floorPlan.name);
    floorPlanFile.close();

    // Display floor plan information
    std::cout << "Gator Apartment Information" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "Floor Plan: " << floorPlan.name << std::endl;

    // Read vacancies information from a CSV file
    std::ifstream vacanciesFile("ApartmentRecords.csv");
    
    if (!vacanciesFile.is_open()) {
        std::cerr << "Error: Unable to open the vacancies file." << std::endl;
        return 1;
    }

    std::vector<Vacancies> vacancies; // Store vacancies data
    
    std::string line;
    std::getline(vacanciesFile, line); // Skip header line
    
    while (std::getline(vacanciesFile, line)) {
        std::istringstream ss(line);
        std::string bedroomsStr, availableStr;
        
        std::getline(ss, bedroomsStr, ',');
        std::getline(ss, availableStr, ',');
        
        Vacancies vacancy;
        vacancy.bedrooms = std::stoi(bedroomsStr);
        vacancy.available = (availableStr == "true");
        
        vacancies.push_back(vacancy);
    }
    
    vacanciesFile.close(); // Close the file
    
    // Display vacancies
    std::cout << "\nVacancies:" << std::endl;
    for (const auto& vacancy : vacancies) {
        std::cout << vacancy.bedrooms << " Bedroom: " << (vacancy.available ? "Available" : "Not Available") << std::endl;
    }

    return 0;
}
