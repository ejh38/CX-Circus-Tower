#include <gtest/gtest.h>

#include "tower_builder.h"
#include "Person.h"

TEST(TowerBuilderTest, MaxHeightTestAllValid) {
    std::vector<Person> people = {
        Person(160, 50),
        Person(161, 60),
        Person(174, 70),
        Person(180, 79),
        Person(181, 80),
    };
    
    TowerBuilder towerBuilder(people);
    EXPECT_EQ(towerBuilder.maxTowerHeight(), 5);
}

TEST(TowerBuilderTest, MaxHeightTestDiffWeightWithSameHeight) {
    std::vector<Person> people = {
        Person(160, 50),
        Person(160, 60), // Same height, cannot stack
        Person(174, 70),
        Person(180, 79),
        Person(181, 80),
    };
    
    TowerBuilder towerBuilder(people);
    EXPECT_EQ(towerBuilder.maxTowerHeight(), 4);
}

TEST(TowerBuilderTest, MaxHeightTestDiffHeightWithSameWeight) {
    std::vector<Person> people = {
        Person(160, 50),
        Person(164, 50), // Same weight, cannot stack
        Person(174, 70),
        Person(180, 79),
        Person(181, 80),
    };
    
    TowerBuilder towerBuilder(people);
    EXPECT_EQ(towerBuilder.maxTowerHeight(), 4);
}

TEST(TowerBuilderTest, NoPeopleTest) {
    std::vector<Person> people;
    TowerBuilder towerBuilder(people);
    EXPECT_EQ(towerBuilder.maxTowerHeight(), 0);
}