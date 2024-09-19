#include "tower_builder.h"

#include <algorithm>
#include <iostream>

// Compare Person objects.
// Returns true if a can be below b if b is shorter and lighter than b.
bool canPlaceBelow(const Person& a, const Person& b) {
    return a.getHeight() > b.getHeight() && a.getWeight() > b.getWeight();
}

size_t TowerBuilder::maxTowerHeight() {
    std::vector<Person> sortedPeople = people_;

    // Lambda to sort the people by height first then weight.
    std::sort(sortedPeople.begin(), sortedPeople.end(), [](const Person& a, const Person& b) {
        return a.getHeight() > b.getHeight() || 
           (a.getHeight() == b.getHeight() && a.getWeight() > b.getWeight());
    });

    std::vector<Person> tower;

    // Iterate through each person to build the tower.
    for (const Person& person : sortedPeople) {
        if (!tower.empty() && 
            (tower.back().getHeight() == person.getHeight() || 
             tower.back().getWeight() == person.getWeight())) {
            continue; // Skip this person if they are the same height or weight as another in order.
        }

        // Add person to tower if possible
        if (tower.empty() || canPlaceBelow(tower.back(), person)) {
            tower.push_back(person);
        }
    }

    // This was added for easier verification that logic is correct.
    printTower(tower);
    return tower.size();
}

void TowerBuilder::printTower(const std::vector<Person>& tower) {
    std::cout << "Tower Configuration (from top to bottom):" << std::endl;
    for (auto it = tower.rbegin(); it != tower.rend(); ++it) {
        std::cout << "Height: " << it->getHeight() << " cm, Weight: " << it->getWeight() << " kg" << std::endl;
    }
}