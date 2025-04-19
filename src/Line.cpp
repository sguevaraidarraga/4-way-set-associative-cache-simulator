#include "Line.h"

Line::Line() {
    valid = false;
    tag = 0;
    data = vector<int>();
}
void Line::replace(const int newTag, const vector<int> &newData) {
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
vector<int>& Line::getData() {
    return data;
}
void Line::print() const {
    cout << "[ " << valid << " | " << tag << " | " << "data[";
    for(int i = 0; i < data.size(); i++) {
        cout << data[i];
        if(i != data.size()-1) {
            cout << ", ";
        }
    }
    cout << "] ]" << endl;
}