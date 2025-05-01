#include "cpu/CPU.h"

CPU::CPU() {
    cache = Cache();
    dram = DRAM();
}
void CPU::loadDRAMFromFile(const string& path) {
    FileManager::loadDRAMFromFile(dram, path);
}
void CPU::generateDRAMFile() {
    FileManager::generateDRAMFile(dram);
}
void CPU::read(unsigned int address) {
    AddressFieldsDecomposer::getInstance().decompose(address);
    unsigned int tag = AddressFieldsDecomposer::getInstance().getTag(),
                 index = AddressFieldsDecomposer::getInstance().getIndex(),
                 offset = AddressFieldsDecomposer::getInstance().getOffset();
    if(cache.read(tag, index)) {
        Logger::getInstance().logReadHit();
        cout << "[READ] Cache hit! Dirección: 0x" << std::hex << address << std::dec << ", Dato: ";
        cache.getElement(tag, index, offset).print();
        cout << endl;
    } else {
        Logger::getInstance().logReadMiss();
        cout << "[READ] Cache miss! Dirección: 0x" << std::hex << address << std::dec << ". Cargando bloque desde DRAM." << endl;
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
        cout << "[WRITE] Cache hit! Dirección: 0x" << std::hex << address << std::dec << ", Dato: ";
        datum.print();
        cout << endl;
        cache.updateElement(tag, index, offset, datum);
    } else {
        Logger::getInstance().logWriteMiss();
        cout << "[WRITE] Cache miss! Dirección: 0x" << std::hex << address << std::dec << ", Dato: ";
        datum.print();
        cout << ". Cargando bloque desde DRAM." << endl;
        cache.writeLine(tag, index, dram.getBlock(address));
    }
}
void CPU::printCache() {
    cache.print();
}
void CPU::printDRAM() {
    dram.print();
}