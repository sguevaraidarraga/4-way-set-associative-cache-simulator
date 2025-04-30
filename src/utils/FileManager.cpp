#include "utils/FileManager.h"

void FileManager::loadDRAMFromFile(DRAM &dram, const string filename) {
    ifstream file(filename);
    unsigned int address = 0;
    string line;
    while(getline(file, line)) {
        Element datum;
        datum.replaceFromLine(line);
        dram.write(address++, datum);
    }
}