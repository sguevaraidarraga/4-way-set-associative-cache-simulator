#ifndef CACHESETTINGS_H
#define CACHESETTINGS_H

#include <cmath>

using std::log2;

struct Settings {
    const int BYTE_ADDRESS = log2(2048);
    const int BLOCK_SIZE = 16;                                          // Tamaño de bloque (en Bytes)
    const int NUM_BLOCKS = 32;                                          // Total de bloques
    const int SET_LINES = 4;
    const int NUM_SETS = NUM_BLOCKS/SET_LINES;
    const int WORD_SIZE = 1;                                            // Palabras por bloque (en Bytes)
    const int OFFSET_BITS = log2(BLOCK_SIZE);
    const int INDEX_BITS = log2(CACHE_SIZE);
    const int TAG_BITS = BYTE_ADDRESS - (INDEX_BITS + OFFSET_BITS);
    const int CACHE_SIZE = 2*INDEX_BITS;
    const int MUX_SELECTOR = log2(WORD_SIZE);
};

#endif