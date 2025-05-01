#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cmath>
#include <string>

using std::log2;
using std::string;

struct Constants {
    static constexpr int MEMORY_SIZE = 2048;
    static constexpr int ADDRESS_BITS = static_cast<int>(log2(MEMORY_SIZE));
    static constexpr int WORD_SIZE = 1;
    static constexpr int BLOCK_SIZE = 16;
    static constexpr int TOTAL_BLOCKS = 32;
    static constexpr int SET_LINES = 4;
    static constexpr int NUM_SETS = TOTAL_BLOCKS/SET_LINES;
    static constexpr int CACHE_SIZE = NUM_SETS;
    static constexpr int INDEX_BITS = static_cast<int>(log2(NUM_SETS));
    static constexpr int OFFSET_BITS = static_cast<int>(log2(BLOCK_SIZE));
    static constexpr int TAG_BITS = ADDRESS_BITS - (INDEX_BITS + OFFSET_BITS);
    static constexpr int WORDS_PER_BLOCK = BLOCK_SIZE/WORD_SIZE;
    static constexpr int MUX_SELECTOR = static_cast<int>(log2(WORDS_PER_BLOCK));
    static string FILES_PATH;
    static string OUT_PATH;
    static string LOG_PATH;
};

#endif