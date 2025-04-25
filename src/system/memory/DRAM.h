#ifndef DRAM_H
#define DRAM_H

#include "settings/Settings.h"
#include "system/shared/Element.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class DRAM {
    vector<Element> data;

    public:
        DRAM();
        const Element& read(unsigned int) const;
        void write(unsigned int, Element&);
        void print();
};

#endif