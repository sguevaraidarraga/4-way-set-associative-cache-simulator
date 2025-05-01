#include "cpu/CPU.h"

int main() {
    CPU c;
    c.initialize("C:\\Users\\Santiago\\Documents\\4-way-set-associative-cache\\test\\in.txt");
    c.chao("C:\\Users\\Santiago\\Documents\\4-way-set-associative-cache\\test\\out.txt");
    //c.printCache();
    //c.printDRAM();
    return 0;
}