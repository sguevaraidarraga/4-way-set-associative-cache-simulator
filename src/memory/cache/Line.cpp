#include "memory/cache/Line.h"

Line::Line() {
    valid = false;
    tag = 0;
    data = vector<Element>(Settings::WORDS_PER_BLOCK);
}
bool Line::isValid() const {
    return valid;
}
unsigned int Line::getTag() const {
    return tag;
}
void Line::setLine(const unsigned int newTag, const vector<Element> &newData) {
    valid = true;
    tag = newTag;
    data = newData;
}
void Line::updateElement(const unsigned int newTag, const unsigned int offset, Element &datum) {
    valid = true;
    tag = newTag;
    data[offset] = datum;
}
void Line::print() const {
    cout << "| " << "Valid : " <<  valid << " | Tag: " << tag << " | Data: " << '[';
    for(size_t i = 0; i < data.size(); i++) {
        data[i].print();
        if(i != data.size()-1) {
            cout << ", ";
        }
    }
    cout << "] |" << endl;
}