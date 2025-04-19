#ifndef SET_H
#define SET_H

#include "Settings.h"
#include "Line.h"
#include <vector>

using std::vector;

class Set {
    int indx;
    vector<Line> lines;

    public:
        Set();
        void set(int, const vector<int>&);
        int getLineIndxByTag(int) const;
        Line& getLine(int);
        void print() const;
};

#endif