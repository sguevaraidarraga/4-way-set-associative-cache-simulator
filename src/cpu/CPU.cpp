#include "cpu/CPU.h"

CPU::CPU() {
    cache = Cache();
    dram = DRAM();
}
void CPU::loadDRAMFromFile(const string& path) {
    FileManager::loadDRAMFromFile(dram, path);
}
void CPU::generateDRAMFile(const string& path) {
    FileManager::generateDRAMFile(dram, path);
}
void CPU::read(unsigned int address) {
    AddressFieldsDecomposer::getInstance().decompose(address);
    unsigned int tag = AddressFieldsDecomposer::getInstance().getTag(),
                 index = AddressFieldsDecomposer::getInstance().getIndex();
    if(cache.read(tag, index)) {
        Logger::getInstance().logReadHit();
    } else {
        Logger::getInstance().logReadMiss();
        cache.writeLine(tag, index, dram.getBlock(address));
    }
}
void CPU::write(unsigned int address, Element &datum) {
    AddressFieldsDecomposer::getInstance().decompose(address);
    unsigned int tag = AddressFieldsDecomposer::getInstance().getTag(),
                 index = AddressFieldsDecomposer::getInstance().getIndex(),
                 offset = AddressFieldsDecomposer::getInstance().getOffset();
    dram.write(address, datum);
    if(cache.read(tag, index)) {
        Logger::getInstance().logWriteHit();
        cache.updateElement(tag, index, offset, datum);
    } else {
        Logger::getInstance().logWriteMiss();
        cache.writeLine(tag, index, dram.getBlock(address));
    }
}
void CPU::printCache() {
    cache.print();
}
void CPU::printDRAM() {
    dram.print();
}