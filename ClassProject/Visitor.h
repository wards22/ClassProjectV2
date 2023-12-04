#ifndef VISITOR_H
#define VISITOR_H

#include <string>
#include <vector>

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

std::vector<Vacancies> readVacanciesFromFile(const std::string& filename);
FloorPlan readFloorPlanFromFile(const std::string& filename);

#endif // VISITOR_H
