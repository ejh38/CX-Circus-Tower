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

// Allows a certain amount of flwxibility with incorrect input. 
// Retry if a failure occurs like if a bad file name was provided.
std::vector<Person> FileDataParser::parseDataWithRetries(int maxRetries) {
    int retryCount = 0;
    while (retryCount < maxRetries) {
        try {
            return parseData();
        } catch (const std::runtime_error&) {
            retryCount++;
            if (retryCount < maxRetries) {
                // Optionally log the retry attempt
            }
        }
    }
    throw std::runtime_error("Error: Failed to read data after " + std::to_string(maxRetries) + " attempts.");
}