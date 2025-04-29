#include "utils/AddressFieldsDecomposer.h"

AddressFieldsDecomposer::AddressFieldsDecomposer() {
    tag = index = offset = 0;
}
AddressFieldsDecomposer& AddressFieldsDecomposer::getInstance() {
    static AddressFieldsDecomposer instance;
    return instance;
}
void AddressFieldsDecomposer::decode(const unsigned int address) {
    offset = address & ((1 << Settings::OFFSET_BITS) - 1);
    index = (address >> Settings::OFFSET_BITS) & ((1 << Settings::INDEX_BITS) - 1);
    tag = address >> (Settings::OFFSET_BITS + Settings::INDEX_BITS);
    baseAddress = address - offset;
}
unsigned int AddressFieldsDecomposer::getBaseAddress() const {
    return baseAddress;
}
unsigned int AddressFieldsDecomposer::getTag() const {
    return tag;
}
unsigned int AddressFieldsDecomposer::getIndex() const {
    return index;
}
unsigned int AddressFieldsDecomposer::getOffset() const {
    return offset;
}