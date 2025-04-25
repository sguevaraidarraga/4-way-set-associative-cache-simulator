#ifndef SET_H
#define SET_H

#include "settings/Settings.h"
#include "system/cache/logic/line/Line.h"
#include "system/shared/Element.h"
#include <vector>

using std::vector;

class Set {
    unsigned int indx;
    vector<Line> lines;

    public:
        Set();
        void replaceLine(unsigned int, const vector<Element>&);
        void updateElement(unsigned int, unsigned int, Element&);
        bool inCache(unsigned int) const;
        void print() const;
};

#endif