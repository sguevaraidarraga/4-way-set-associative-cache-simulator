#ifndef CACHE_H
#define CACHE_H

#include "Settings.h"
#include "Set.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Cache {
    vector<Set> sets;
    
    public:
        Cache();
        void print() const;
};

#endif