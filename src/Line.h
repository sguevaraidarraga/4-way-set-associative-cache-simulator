#ifndef LINE_H
#define LINE_H

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Line {
    private:
        bool valid;
        int tag;
        vector<int> data;
    
    public:
        Line();
        void replace(int, vector<int>&);
        bool isValid();
        int getTag();
        vector<int>& getData();
        void print();
};

#endif