#ifndef SET_H
#define SET_H

#include "Settings.h"
#include "Line.h"
#include <vector>

using std::vector;

class Set {
    private:
        int indx;
        vector<Line> lines;

    public:
        Set();
        void set(int, vector<int>&);
        int getLineIndxByTag(int);
        Line& getLine(int);
        void print();
};

#endif