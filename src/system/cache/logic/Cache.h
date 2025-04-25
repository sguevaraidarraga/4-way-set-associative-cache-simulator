#ifndef CACHE_H
#define CACHE_H

#include "settings/Settings.h"
#include "system/cache/logic/set/Set.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Cache {
    vector<Set> sets;
    
    public:
        Cache();
        bool read(unsigned int, unsigned int);
        void writeLine(unsigned int, unsigned int, const vector<Element>&);
        void updateElement(unsigned int, unsigned int, unsigned int, Element&);
        void print() const;
};

#endif