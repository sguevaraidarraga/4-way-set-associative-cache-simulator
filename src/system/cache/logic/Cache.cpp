#include "Cache.h"

Cache::Cache() {
    info = AddressDecoder();
    sets = vector<Set>(Settings::NUM_SETS);
}
void Cache::print() const {
    for(int i = 0; i < sets.size(); i++) {
        cout << "set " << i << ':' << endl;
        sets[i].print();
    }
}
int Cache::read(const unsigned int address) {
    info.decode(address);
    unsigned int tag = info.getTag(), index = info.getIndex(), offset = info.getOffset();
    if(sets[index].getLineIndxByTag(tag) != -1) {
        // Line = sets[index].getLine(tag);
    }
    return 0;
}