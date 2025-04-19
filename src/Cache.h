#ifndef CACHE_H
#define CACHE_H

#include "Settings.h"
#include "Set.h"
#include <vector>

using std::vector;

class Cache {
    vector<Set> sets;
    
    public:
        Cache();
};

#endif