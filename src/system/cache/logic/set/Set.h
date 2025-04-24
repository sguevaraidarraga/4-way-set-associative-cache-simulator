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
        void set(unsigned int, const vector<Element>&);
        int getLineIndxByTag(unsigned int) const;
        Line& getLine(unsigned int);
        void print() const;
};

#endif