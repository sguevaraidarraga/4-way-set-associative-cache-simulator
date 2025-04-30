#include "memory/cache/Set.h"

Set::Set() {
    indx = 0;
    lines = vector<Line>(Constants::SET_LINES);
}
bool Set::inCache(const unsigned int tag) const {
    bool ans = false;
    for(int i = 0; i < Constants::SET_LINES && !ans; i++) {
        if(lines[i].isValid() && lines[i].getTag() == tag) {
            ans = true;
        }
    }
    return ans;
}
void Set::replaceLine(const unsigned int tag, const vector<Element> &data) {
    lines[indx].setLine(tag, data);
    indx++;
    if(indx == Constants::SET_LINES) {
        indx = 0;
    }
}
void Set::updateElement(const unsigned int tag, const unsigned int offset, Element &datum) {
    bool f = false;
    for(int i = 0; i < Constants::SET_LINES && !f; i++) {
        if(lines[i].isValid() && lines[i].getTag() == tag) {
            lines[i].updateElement(tag, offset, datum);
            f = true;
        }
    }
}
void Set::print() const {
    for(const auto &line : lines) {
        line.print();
    }
}