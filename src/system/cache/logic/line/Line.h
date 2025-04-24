#ifndef LINE_H
#define LINE_H

#include "settings/Settings.h"
#include "system/shared/Element.h"
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
        void replace(unsigned int, const vector<Element>&);
        bool isValid() const;
        unsigned int getTag() const;
        vector<Element>& getData();
        void print() const;
};

#endif