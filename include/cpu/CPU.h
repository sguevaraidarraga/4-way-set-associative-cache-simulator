#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "utils/Constants.h"
#include "utils/Logger.h"
#include "utils/AddressFieldsDecomposer.h"
#include "memory/cache/Cache.h"
#include "memory/dram/DRAM.h"
#include "memory/type/Element.h"

class Controller {
    Cache cache;
    DRAM dram;

    const vector<Element> getBlock() const;

    public:
        Controller();
        void read(unsigned int);
        void write(unsigned int, Element&);
        void printCache();
        void printDRAM();
};

#endif