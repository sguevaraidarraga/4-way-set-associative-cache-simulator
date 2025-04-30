#ifndef CPU_H
#define CPU_H

#include "utils/Constants.h"
#include "utils/Logger.h"
#include "utils/AddressFieldsDecomposer.h"
#include "memory/cache/Cache.h"
#include "memory/dram/DRAM.h"
#include "memory/type/Element.h"

class CPU {
    Cache cache;
    DRAM dram;

    public:
        CPU();
        void read(unsigned int);
        void write(unsigned int, Element&);
        void printCache();
        void printDRAM();
};

#endif