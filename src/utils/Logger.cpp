#include "utils/Logger.h"

Logger::Logger() {
    totalAccesses = hits = misses = 0;
}
Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}
void Logger::logHit() {
    hits++, totalAccesses++;
}
void Logger::logMiss() {
    misses++, totalAccesses++;
}
unsigned int Logger::getTotalAccesses() const {
    return totalAccesses;
}
unsigned int Logger::getHits() const {
    return hits;
}
unsigned int Logger::getMisses() const {
    return misses;
}
double Logger::getHitRate() const {
    return (totalAccesses == 0) ? 0.0 : static_cast<double>(hits)/totalAccesses;
}
double Logger::getMissRate() const {
    return (totalAccesses == 0) ? 0.0 : static_cast<double>(misses)/totalAccesses;
}