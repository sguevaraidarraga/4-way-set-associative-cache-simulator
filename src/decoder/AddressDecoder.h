#ifndef ADDRESSDECODER_H
#define ADDRESSDECODER_H

#include "settings/Settings.h"

class AddressDecoder {
    unsigned int baseAddress, tag, index, offset;

    AddressDecoder();

    public:
        static AddressDecoder& getInstance();
        void decode(unsigned int);
        unsigned int getBaseAddress() const;
        unsigned int getTag() const;
        unsigned int getIndex() const;
        unsigned int getOffset() const;
};

#endif