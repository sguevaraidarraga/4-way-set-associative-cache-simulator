#ifndef CACHE_H
#define CACHE_H

#include "settings/Settings.h"
#include "decoder/AddressDecoder.h"
#include "system/cache/logic/set/Set.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Cache {
    AddressDecoder info;
    vector<Set> sets;
    
    public:
        Cache();
        int read(unsigned int);
        void print() const;
};

#endif