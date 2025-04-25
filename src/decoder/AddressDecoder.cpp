#include "AddressDecoder.h"

AddressDecoder::AddressDecoder() {
    tag = index = offset = 0;
}
AddressDecoder& AddressDecoder::getInstance() {
    static AddressDecoder instance;
    return instance;
}
void AddressDecoder::decode(const unsigned int address) {
    offset = address & ((1 << Settings::OFFSET_BITS) - 1);
    index = (address >> Settings::OFFSET_BITS) & ((1 << Settings::INDEX_BITS) - 1);
    tag = address >> (Settings::OFFSET_BITS + Settings::INDEX_BITS);
    baseAddress = address - offset;
}
unsigned int AddressDecoder::getBaseAddress() const {
    return baseAddress;
}
unsigned int AddressDecoder::getTag() const {
    return tag;
}
unsigned int AddressDecoder::getIndex() const {
    return index;
}
unsigned int AddressDecoder::getOffset() const {
    return offset;
}