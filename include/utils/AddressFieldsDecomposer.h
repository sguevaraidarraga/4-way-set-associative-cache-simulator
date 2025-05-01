#ifndef ADDRESSFIELDSDECOMPOSER_H
#define ADDRESSFIELDSDECOMPOSER_H

#include "utils/Constants.h"

class AddressFieldsDecomposer {
    unsigned int baseAddress, tag, index, offset;

    AddressFieldsDecomposer();

    public:
        static AddressFieldsDecomposer& getInstance();
        void decompose(unsigned int);
        unsigned int getBaseAddress() const;
        unsigned int getTag() const;
        unsigned int getIndex() const;
        unsigned int getOffset() const;
};

#endif