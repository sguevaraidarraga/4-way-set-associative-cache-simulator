#ifndef APP_H
#define APP_H

#include "cpu/CPU.h"
#include "utils/Constants.h"
#include "utils/Generator.h"
#include <iostream>

using std::exception;
using std::cin;
using std::cout;
using std::endl;

class App {
    CPU cpu;

    public:
        App();
        bool mainMenu();
        void initializeDRAMMenu();
        void initializeDRAMFromFile();
        void generateDRAM();
        void executeFromFile();
        void generateInstructions();
        void printCache();
        void exportFiles();
};

#endif