#ifndef ELEMENT_H
#define ELEMENT_H

#include "memory/type/ElementType.h"
#include <utility>
#include <string>
#include <iostream>

using std::pair;
using std::string;
using std::cout;

class Element {
    pair<unsigned char, unsigned char> element;
    ElementType type;

    public:
        Element();
        void replace(const pair<unsigned char, unsigned char>&, ElementType);
        void replaceFromLine(string);
        pair<unsigned char, unsigned char> getElement();
        ElementType& getType();
        void print() const;
};

#endif