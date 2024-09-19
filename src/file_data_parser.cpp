#include "file_data_parser.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

FileDataParser::FileDataParser(const std::string& filename) : filename_(filename) {}

std::vector<Person> FileDataParser::parseData() {
    std::vector<Person> people;
    std::ifstream file(filename_);

    // Check if the file was opened successfully, else show err.
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file " + filename_);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int height, weight;

        // Make sure information was parsed successfully from file.
        if (iss >> height >> weight) {
            people.emplace_back(height, weight);
        } else {
            throw std::runtime_error("Error: Invalid line format: " + line);
        }
    }

    // Make sure that we have people as a last resort. File could be empty.
    if (people.empty()) {
        throw std::runtime_error("Error: No valid data found in file " + filename_);
    }

    return people;
}