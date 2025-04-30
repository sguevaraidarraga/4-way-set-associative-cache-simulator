#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "memory/type/ElementType.h"
#include "memory/type/Element.h"
#include "memory/dram/DRAM.h"
#include <string>
#include <fstream>

using std::string;
using std::ifstream;

class FileManager {
    public:
        static void loadDRAMFromFile(DRAM&, string);
        static void generateDRAMFile(DRAM&);
};

#endif