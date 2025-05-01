#ifndef GENERATOR_H
#define GENERATOR_H

#include "cpu/CPU.h"
#include <random>
#include <string>

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

struct Generator {
    static void generateInstructions(CPU&, unsigned int);
};

#endif