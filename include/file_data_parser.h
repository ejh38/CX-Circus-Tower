#ifndef FILE_DATA_PARSER_H
#define FILE_DATA_PARSER_H

#include <fstream>
#include <sstream>
#include <vector>

#include "person.h"

class FileDataParser {
    public:
        FileDataParser(const std::string& filename);
        std::vector<Person> parseDataWithRetries(int maxRetries = 3);
    private:
        std::vector<Person> parseData();
        std::string filename_;

};

#endif // FILE_DATA_PARSER_H