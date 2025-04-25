#include "system/cache/Controller.h"

Controller::Controller() {
    cache = Cache();
    dram = DRAM();
}
const vector<Element> Controller::getBlock() const {
    vector<Element> ans(Settings::WORDS_PER_BLOCK);
    unsigned int baseAddress = AddressDecoder::getInstance().getBaseAddress();
    for(int offset = 0; offset < ans.size(); offset++) {
        ans[offset] = dram.read(baseAddress + offset);
    }
    return ans;
}
void Controller::read(unsigned int address) {
    AddressDecoder::getInstance().decode(address);
    unsigned int tag = AddressDecoder::getInstance().getTag(), index = AddressDecoder::getInstance().getIndex();
    if(cache.read(tag, index)) {
        Logger::getInstance().logHit();
    } else {
        Logger::getInstance().logMiss();
        cache.writeLine(tag, index, getBlock());
    }
}
void Controller::write(unsigned int address, Element &datum) {
    AddressDecoder::getInstance().decode(address);
    unsigned int tag = AddressDecoder::getInstance().getTag(), index = AddressDecoder::getInstance().getIndex(), offset = AddressDecoder::getInstance().getOffset();
    dram.write(address, datum);
    if(cache.read(tag, index)) {
        Logger::getInstance().logHit();
        cache.updateElement(tag, index, offset, datum);
    } else {
        Logger::getInstance().logMiss();
        cache.writeLine(tag, index, getBlock());
    }
}
void Controller::printCache() {
    cache.print();
}
void Controller::printDRAM() {
    dram.print();
}