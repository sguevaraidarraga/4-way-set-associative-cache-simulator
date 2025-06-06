#ifndef DRAM_H
#define DRAM_H

#include "utils/Constants.h"
#include "utils/AddressFieldsDecomposer.h"
#include "memory/type/Element.h"
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
        vector<Element> getBlock(unsigned int address);
        void print();
        
};

#endif