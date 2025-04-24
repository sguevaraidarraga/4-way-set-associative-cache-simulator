#include "Set.h"

Set::Set() {
    indx = 0;
    lines = vector<Line>(Settings::SET_LINES);
}
void Set::set(const unsigned int tag, const vector<Element> &data) {
    lines[indx].replace(tag, data);
    indx++;
    if(indx == Settings::SET_LINES) {
        indx = 0;
    }
}
int Set::getLineIndxByTag(const unsigned int tag) const {
    int i;
    bool found = false;
    for(i = 0; i < Settings::SET_LINES && !found; i++) {
        if(lines[i].isValid() && lines[i].getTag() == tag) {
            found = true;
        }
    }
    return (found == true) ? i : -1;
}
Line& Set::getLine(const unsigned int idx) {
    return lines[idx];
}
void Set::print() const {
    for(const auto &line : lines) {
        line.print();
    }
}