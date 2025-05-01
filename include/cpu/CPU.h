#ifndef CPU_H
#define CPU_H

#include "utils/Constants.h"
#include "utils/Logger.h"
#include "utils/AddressFieldsDecomposer.h"
#include "utils/FileManager.h"
#include "memory/cache/Cache.h"
#include "memory/dram/DRAM.h"
#include "memory/type/Element.h"
#include <string>

using std::string;

class CPU {
    Cache cache;
    DRAM dram;

    public:
        CPU();
        void loadDRAMFromFile(const string&);
        void generateDRAMFile(const string&);
        void read(unsigned int);
        void write(unsigned int, Element&);
        void printCache();
        void printDRAM();
};

#endif