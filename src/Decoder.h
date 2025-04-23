#ifndef DECODER_H
#define DECODER_H

#include "Settings.h"

class Decoder {
    unsigned int tag, index, offset;

    public:
        Decoder();
        void decode(unsigned int);
        unsigned int getTag() const;
        unsigned int getIndex() const;
        unsigned int getOffset() const;
};

#endif