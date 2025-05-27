#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "memory/type/ElementType.h"
#include "memory/type/Element.h"
#include "memory/dram/DRAM.h"
#include "utils/Constants.h"
#include "utils/Logger.h"
#include <string>
#include <fstream>
#include <sstream>
#include <utility>

using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;

class CPU;

struct FileManager {
    static void loadDRAMFromFile(DRAM&, const string&);
    static void executeInstructionsFromFile(CPU&, const string&);
    static void generateDRAMFile(DRAM&);
    static void generateLogFile();
};

#endif