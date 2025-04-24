#ifndef ELEMENT_H
#define ELEMENT_H

#include "system/shared/type/ElementType.h"
#include <utility>
#include <iostream>

using std::pair;
using std::cout;

class Element {
    pair<unsigned char, unsigned char> element;
    ElementType type;

    public:
        Element();
        void replace(const pair<unsigned char, unsigned char>&, ElementType);
        pair<unsigned char, unsigned char> getElement();
        ElementType& getType();
        void print() const;
};

#endif