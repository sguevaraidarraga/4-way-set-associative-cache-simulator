#include "Decoder.h"

Decoder::Decoder() {
    tag = index = offset = 0;
}
void Decoder::decode(unsigned int address) {
    offset = address & ((1 << Settings::OFFSET_BITS) - 1);
    index = (address >> Settings::OFFSET_BITS) & ((1 << Settings::INDEX_BITS) - 1);
    tag = address >> (Settings::OFFSET_BITS + Settings::INDEX_BITS);
}
unsigned int Decoder::getTag() const {
    return tag;
}
unsigned int Decoder::getIndex() const {
    return index;
}
unsigned int Decoder::getOffset() const {
    return offset;
}