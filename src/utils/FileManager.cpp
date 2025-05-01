#include "utils/FileManager.h"

void FileManager::loadDRAMFromFile(DRAM &dram, const string &path) {
    ifstream file(path);
    if(!file.is_open()) {
        throw std::runtime_error("Error: Couldn't open file at" + path);
    }
    unsigned int address = 0;
    string line;
    Element datum;
    while(getline(file, line)) {
        datum.replaceFromLine(line);
        dram.write(address++, datum);
    }
}
void FileManager::generateDRAMFile(DRAM &dram, const string &path) {
    ofstream file(path);
    if(!file.is_open()) {
        throw std::runtime_error("Error: Couldn't open file at" + path);
    }
    for(unsigned int address = 0; address < Constants::MEMORY_SIZE; ++address) {
        Element elem = dram.read(address);
        if(elem.getType() == ElementType::COMBINATION) {
            auto val = elem.getElement();
            file << val.first << val.second << '\n';
        } else {
            auto val = elem.getElement();
            file << val.first << '\n';
        }
    }
}