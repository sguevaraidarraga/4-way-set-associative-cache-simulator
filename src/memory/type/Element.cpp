#include "memory/type/Element.h"

Element::Element() {
    element = {'0', '0'};
    type = ElementType::DIGIT;
}
void Element::replace(const pair<unsigned char, unsigned char> &newElement, const ElementType newType) {
    element = newElement;
    type = newType;
}
void Element::replaceFromLine(const string line) {
    if(line.size() == 1) {
        if(std::isdigit(line[0])) {
            replace({line[0], '0'}, ElementType::DIGIT);
        } else {
            replace({line[0], '0'}, ElementType::LETTER);
        }
    } else {
        replace({line[0], line[1]}, ElementType::COMBINATION);
    }
}
pair<unsigned char, unsigned char> Element::getElement() {
    return element;
}
ElementType& Element::getType() {
    return type;
}
void Element::print() const {
    if(type == ElementType::DIGIT || type == ElementType::LETTER) {
        cout << element.first;
    }
    else {
        cout << element.first << element.second;
    }
}