#include <gtest/gtest.h>

#include "Person.h"

TEST(PersonTest, GetHeightAndWeight) {
    Person person(180, 75);
    EXPECT_EQ(person.getHeight(), 180);
    EXPECT_EQ(person.getWeight(), 75);
}

TEST(PersonTest, InvalidHeight) {
    EXPECT_THROW(Person(-1, 75), std::invalid_argument);
}

TEST(PersonTest, InvalidWeight) {
    EXPECT_THROW(Person(180, -1), std::invalid_argument);
}

TEST(PersonTest, InvalidHeightAndWeight) {
    EXPECT_THROW(Person(-1, -1), std::invalid_argument);
}