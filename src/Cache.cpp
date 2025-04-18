#include "Cache.h"

Cache::Cache() {
    sets = vector<Set>(Settings::NUM_SETS);
}