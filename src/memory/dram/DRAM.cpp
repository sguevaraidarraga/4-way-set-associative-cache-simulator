#include "memory/dram/DRAM.h"

DRAM::DRAM() {
    data = vector<Element>(Constants::MEMORY_SIZE);
}
const Element& DRAM::read(unsigned int address) const {
    return data[address];
}
void DRAM::write(unsigned int address, Element& datum) {
    data[address] = datum;
}
vector<Element> DRAM::getBlock(const unsigned int address) {
    vector<Element> ans(Constants::WORDS_PER_BLOCK);
    unsigned int baseAddress = AddressFieldsDecomposer::getInstance().getBaseAddress();
    for(int offset = 0; offset < Constants::WORDS_PER_BLOCK; offset++) {
        ans[offset] = data[baseAddress + offset];
    }
    return ans;
}
void DRAM::print() {
    for(int i = 0; i < Constants::MEMORY_SIZE; i++) {
        cout << i << ' ';
        data[i].print();
        cout << endl;
    }
}