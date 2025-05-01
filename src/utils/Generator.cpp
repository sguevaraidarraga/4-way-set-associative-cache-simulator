#include "utils/Generator.h"

void Generator::generateInstructions(CPU &cpu, const unsigned int numInstr) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<unsigned int> addrDist(0, Constants::MEMORY_SIZE - 1);
    uniform_int_distribution<int> opDist(0, 1); // 0: read, 1: write
    uniform_int_distribution<int> typeDist(0, 2); // 0: digit, 1: letter, 2: combination
    uniform_int_distribution<int> digitDist('0', '9');
    uniform_int_distribution<int> letterDist('A', 'Z');
    unsigned int address;
    int op, type;
    Element elem;
    for(int i = 0; i < numInstr; i++) {
        address = addrDist(gen);
        op = opDist(gen);
        if(op == 0) {
            cpu.read(address);
        } else {
            type = typeDist(gen);
            if (type == 0) {
                elem.replace({digitDist(gen), '0'}, ElementType::DIGIT);
            } else if (type == 1) {
                elem.replace({letterDist(gen), '0'}, ElementType::LETTER);
            } else {
                elem.replace({digitDist(gen), letterDist(gen)}, ElementType::COMBINATION);
            }
            cpu.write(address, elem);
        }
    }
}