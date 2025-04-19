#include "Cache.h"

Cache::Cache() {
    sets = vector<Set>(Settings::NUM_SETS);
}
void Cache::print() const {
    for(int i = 0; i < sets.size(); i++) {
        cout << "set " << i << ':' << endl;
        sets[i].print();
    }
}