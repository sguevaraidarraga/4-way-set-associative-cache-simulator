#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "settings/Settings.h"
#include "stats/Logger.h"
#include "decoder/AddressDecoder.h"
#include "system/cache/logic/Cache.h"
#include "system/memory/DRAM.h"
#include "system/shared/Element.h"

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