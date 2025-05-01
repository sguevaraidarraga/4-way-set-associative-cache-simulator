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
        throw std::runtime_error("Error: Couldn't open file at " + path);
    }
    Element elem;
    pair<unsigned char, unsigned char> val;
    for(unsigned int address = 0; address < Constants::MEMORY_SIZE; address++) {
        elem = dram.read(address);
        val = elem.getElement();
        if(elem.getType() == ElementType::COMBINATION) {
            file << val.first << val.second << '\n';
        } else {
            file << val.first << '\n';
        }
    }
}
void FileManager::generateLogFile() {
    ofstream file(Constants::LOG_PATH);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Couldn't open file for writing at " + Constants::LOG_PATH);
    }
    file << "Metric,Total,Read,Write\n";
    file << "Accesses," << Logger::getInstance().getTotalAccesses() << ","
         << Logger::getInstance().getTotalReadAccesses() << ","
         << Logger::getInstance().getTotalWriteAccesses() << "\n";
    file << "Hits," << Logger::getInstance().getTotalHits() << ","
         << Logger::getInstance().getReadHits() << ","
         << Logger::getInstance().getWriteHits() << "\n";
    file << "Misses," << Logger::getInstance().getTotalMisses() << ","
         << Logger::getInstance().getReadMisses() << ","
         << Logger::getInstance().getWriteMisses() << "\n";
    file << "Hit Rate," << Logger::getInstance().getTotalHitRate() << ","
         << Logger::getInstance().getReadHitRate() << ","
         << Logger::getInstance().getWriteHitRate() << "\n";
    file << "Miss Rate," << Logger::getInstance().getTotalMissRate() << ","
         << Logger::getInstance().getReadMissRate() << ","
         << Logger::getInstance().getWriteMissRate() << "\n";
}