#ifndef LINE_H
#define LINE_H

#include "utils/Constants.h"
#include "memory/type/Element.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Line {
    bool valid;
    unsigned int tag;
    vector<Element> data;
    
    public:
        Line();
        void setLine(unsigned int, const vector<Element>&);
        void updateElement(unsigned int, unsigned int, Element&);
        bool isValid() const;
        unsigned int getTag() const;
        Element getElement(unsigned int);
        void print() const;
};

#endif