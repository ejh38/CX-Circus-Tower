#include <iostream>
#include <stdexcept>
#include <vector>

#include "file_data_parser.h"
#include "tower_builder.h"

void printUsage(const char* programName) {
    std::cerr << "Usage: " << programName << " <file_path>" << std::endl;
    std::cerr << "  <file_path>: Path to the input file containing person data" << std::endl;
    std::cerr << std::endl;
    std::cerr << "If no file path is provided, you will be prompted to enter one." << std::endl;
}

std::string getFilePath(int argc, char* argv[]) {
    if (argc >= 2) return argv[1];
    std::string filePath;
    std::cout << "Please enter the path to the data file (or 'q' to quit): ";
    std::cin >> filePath;
    return filePath;
}

int main(int argc, char* argv[]) {
        std::vector<Person> people;
    std::string filePath;

    // Print usage if no arguments are provided.
    if (argc == 1) {
        printUsage(argv[0]);
    }

    while (true) {
        try {
            filePath = getFilePath(argc, argv);
            if (filePath == "q" || filePath == "Q") {
                std::cout << "Exiting program." << std::endl;
                return 0;
            }
            argc = 1;

            FileDataParser dataParser(filePath);
            people = dataParser.parseData();

            TowerBuilder towerBuilder(people);
            size_t maxHeight = towerBuilder.maxTowerHeight();
            std::cout << "Maximum number of people in the tower: " << maxHeight << std::endl;
            break;

        } catch (const std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
            people.clear();
        }
    }

    return 0;
}