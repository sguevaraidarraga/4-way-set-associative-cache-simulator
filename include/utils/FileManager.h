#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "memory/type/ElementType.h"
#include "memory/type/Element.h"
#include "memory/dram/DRAM.h"
#include <string>
#include <fstream>

using std::string;
using std::ifstream;
using std::ofstream;

class FileManager {
    public:
        static void loadDRAMFromFile(DRAM&, const string&);
        static void generateDRAMFile(DRAM&, const string&);
};

#endif