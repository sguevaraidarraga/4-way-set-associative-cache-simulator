#include "memory/dram/DRAM.h"

DRAM::DRAM() {
    data = vector<Element>(Settings::MEMORY_SIZE);
}
const Element& DRAM::read(unsigned int address) const {
    return data[address];
}
void DRAM::write(unsigned int address, Element& datum) {
    data[address] = datum;
}
void DRAM::print() {
    for(int i = 0; i < Settings::MEMORY_SIZE; i++) {
        cout << i << ' ';
        data[i].print();
        cout << endl;
    }
}