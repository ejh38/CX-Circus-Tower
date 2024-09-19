#include <gtest/gtest.h>

#include "file_data_parser.h"
#include "Person.h"
#include <fstream>

// Create a file for testing.
void createTempFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    file << content;
    file.close();
}

TEST(FileDataParserTest, ValidFileParsing) {
    createTempFile("valid_data.txt", "180 75\n160 60\n170 65\n182 75\n162 60\n176 65\n187 75\n166 60\n171 65\n");
    FileDataParser parser("valid_data.txt");
    std::vector<Person> people = parser.parseData();
    EXPECT_EQ(people.size(), 9); // Ensure that we have parsed three people
}

TEST(FileDataParserTest, InvalidFile) {
    FileDataParser parser("invalid_file.txt");
    EXPECT_THROW(parser.parseData(), std::runtime_error); // Should throw an error
}

TEST(FileDataParserTest, InvalidDataFormat) {
    createTempFile("invalid_data.txt", "180 75\ninvalid_line\n160 60\n");
    FileDataParser parser("invalid_data.txt");
    EXPECT_THROW(parser.parseData(), std::runtime_error); // Should throw an error
}