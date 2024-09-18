#include <iostream>
#include <stdexcept>

#include "file_data_parser.h"
#include "tower_builder.h"

void validateArguments(int argc) {
    if (argc < 2) {
        throw std::runtime_error("Usage: <program> <file_path>");
    }
}

int main(int argc, char* argv[]) {
    try {
        validateArguments(argc);
        const std::string filePath = argv[1];
        
        FileDataParser dataParser(filePath);

        // Sticking with default maxRetries of 3
        std::vector<Person> people = dataParser.parseDataWithRetries();
            
        TowerBuilder towerBuilder(people);
        size_t maxHeight = towerBuilder.maxTowerHeight();
        std::cout << "Maximum number of people in the tower: " << maxHeight << std::endl;

    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0; // Return 0 to indicate success
}