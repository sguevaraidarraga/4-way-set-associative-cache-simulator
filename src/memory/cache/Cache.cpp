#include "memory/cache/Cache.h"

Cache::Cache() {
    sets = vector<Set>(Constants::NUM_SETS);
}
bool Cache::read(const unsigned int tag, const unsigned int index) {
    return sets[index].inCache(tag);
}
void Cache::writeLine(const unsigned int tag, const unsigned int index, const vector<Element> &data) {
    sets[index].replaceLine(tag, data);
}
Element Cache::getElement(const unsigned int tag, const unsigned int index, const unsigned int offset) {
    return sets[index].getElement(tag, offset);
}
void Cache::updateElement(const unsigned int tag, const unsigned int index, const unsigned int offset, Element &datum) {
    sets[index].updateElement(tag, offset, datum);
}
void Cache::print() const {
    for(int i = 0; i < sets.size(); i++) {
        cout << "set " << i << ':' << endl;
        sets[i].print();
    }
}