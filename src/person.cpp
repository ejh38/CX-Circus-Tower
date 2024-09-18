#include "Person.h"

#include <stdexcept>

Person::Person(int height, int weight) : height_(height), weight_(weight) {
    if (height < 0) {
        throw std::invalid_argument("Height cannot be negative.");
    }
    if (weight < 0) {
        throw std::invalid_argument("Weight cannot be negative.");
    }
}

int Person::getHeight() const {
    return height_;
}

int Person::getWeight() const {
    return weight_;
}