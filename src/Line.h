#ifndef LINE_H
#define LINE_H

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Line {
    bool valid;
    int tag;
    vector<int> data;
    
    public:
        Line();
        void replace(int, const vector<int>&);
        bool isValid() const;
        int getTag() const;
        vector<int>& getData();
        void print() const;
};

#endif