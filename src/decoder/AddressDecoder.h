#ifndef ADDRESSDECODER_H
#define ADDRESSDECODER_H

#include "settings/Settings.h"

class AddressDecoder {
    unsigned int tag, index, offset;

    public:
        AddressDecoder();
        void decode(unsigned int);
        unsigned int getTag() const;
        unsigned int getIndex() const;
        unsigned int getOffset() const;
};

#endif