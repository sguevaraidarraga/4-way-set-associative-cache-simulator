#include "utils/FileManager.h"
#include "cpu/CPU.h"

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
void FileManager::executeInstructionsFromFile(CPU &cpu, const string &path) {
    ifstream file(Constants::FILES_PATH + path);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Couldn't open instructions file at " + Constants::FILES_PATH + path);
    }
    std::string line;
    while (std::getline(file, line)) {
        istringstream iss(line);
        string op;
        iss >> op;
        if (op == "READ") {
            unsigned int address;
            iss >> address;
            cpu.read(address);
        } else if (op == "WRITE") {
            unsigned int address;
            string datumStr;
            iss >> address >> datumStr;
            Element datum;
            datum.replaceFromLine(datumStr);
            cpu.write(address, datum);
        }
    }
}
void FileManager::generateDRAMFile(DRAM &dram) {
    ofstream file(Constants::OUT_PATH);
    if(!file.is_open()) {
        throw std::runtime_error("Error: Couldn't write file at " + Constants::OUT_PATH);
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
        throw std::runtime_error("Error: Couldn't write file for writing at " + Constants::LOG_PATH);
    }
    file << "Metric" << Constants::DELIMITER << "Total" << Constants::DELIMITER << "Read" << Constants::DELIMITER << "Write\n";
    file << "Accesses" << Constants::DELIMITER << Logger::getInstance().getTotalAccesses() << Constants::DELIMITER
         << Logger::getInstance().getTotalReadAccesses() << Constants::DELIMITER
         << Logger::getInstance().getTotalWriteAccesses() << "\n";
    file << "Hits" << Constants::DELIMITER << Logger::getInstance().getTotalHits() << Constants::DELIMITER
         << Logger::getInstance().getReadHits() << Constants::DELIMITER
         << Logger::getInstance().getWriteHits() << "\n";
    file << "Misses" << Constants::DELIMITER << Logger::getInstance().getTotalMisses() << Constants::DELIMITER
         << Logger::getInstance().getReadMisses() << Constants::DELIMITER
         << Logger::getInstance().getWriteMisses() << "\n";
    file << "Hit Rate" << Constants::DELIMITER << Logger::getInstance().getTotalHitRate() << Constants::DELIMITER
         << Logger::getInstance().getReadHitRate() << Constants::DELIMITER
         << Logger::getInstance().getWriteHitRate() << "\n";
    file << "Miss Rate" << Constants::DELIMITER << Logger::getInstance().getTotalMissRate() << Constants::DELIMITER
         << Logger::getInstance().getReadMissRate() << Constants::DELIMITER
         << Logger::getInstance().getWriteMissRate() << "\n";
}