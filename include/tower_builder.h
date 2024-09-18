#ifndef TOWER_H
#define TOWER_H

#include <vector>

#include "Person.h"

class TowerBuilder {
    public:
        TowerBuilder(const std::vector<Person>& people) : people_(people) {}
        void printTower(const std::vector<Person>& tower);
        size_t maxTowerHeight();
    private:
        std::vector<Person> people_;
};

#endif // TOWER_H