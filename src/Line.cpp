#include "Line.h"

Line::Line() {
    valid = false;
    tag = 0;
    data = vector<Element>(Settings::BLOCK_SIZE);
}
void Line::replace(const int newTag, const vector<Element> &newData) {
    valid = true;
    tag = newTag;
    data = newData;
}
bool Line::isValid() const {
    return valid;
}
int Line::getTag() const {
    return tag;
}
vector<Element>& Line::getData() {
    return data;
}
void Line::print() const {
    cout << "[ " << valid << " | " << tag << " | " << "data[";
    for(int i = 0; i < data.size(); i++) {
        data[i].print();
        if(i != data.size()-1) {
            cout << ", ";
        }
    }
    cout << "] ]" << endl;
}