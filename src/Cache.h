#ifndef CACHE_H
#define CACHE_H

#include "Settings.h"
#include "Decoder.h"
#include "Set.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Cache {
    Decoder info;
    vector<Set> sets;
    
    public:
        Cache();
        int read(unsigned int);
        void print() const;
};

#endif