#include "Element.h"

Element::Element() {
    element = {'0', '0'};
    type = ElementType::DIGIT;
}
void Element::replace(const pair<unsigned char, unsigned char> &newElement, ElementType newType) {
    element = newElement;
    type = newType;
}
pair<unsigned char, unsigned char> Element::getElement() {
    return element;
}
ElementType Element::getType() const {
    return type;
}
void Element::print() const {
    if(type == ElementType::DIGIT || type == ElementType::LETTER) {
        cout << element.second;
    }
    else {
        cout << element.first << element.second;
    }
}