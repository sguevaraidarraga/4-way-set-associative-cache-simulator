#include "utils/FileManager.h"

void FileManager::loadDRAMFromFile(DRAM &dram, const string filename) {
    ifstream file(filename);
    if(!file.is_open()) {
        throw std::runtime_error("Error: Couldn't open file at" + filename);
    }
    unsigned int address = 0;
    string line;
    while(getline(file, line)) {
        Element datum;
        datum.replaceFromLine(line);
        dram.write(address++, datum);
    }
    file.close();
}