#include "utils/Logger.h"

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}
void Logger::logReadHit() {
    totalAccesses++; totalReadAccesses++; readHits++; totalHits++;
}
void Logger::logReadMiss() {
    totalAccesses++; totalReadAccesses++; readMisses++; totalMisses++;
}
void Logger::logWriteHit() {
    totalAccesses++; totalWriteAccesses++; writeHits++; totalHits++;
}
void Logger::logWriteMiss() {
    totalAccesses++; totalWriteAccesses++; writeMisses++; totalMisses++;
}
unsigned int Logger::getTotalAccesses() const {
    return totalAccesses;
}
unsigned int Logger::getTotalHits() const {
    return totalHits;
}
unsigned int Logger::getTotalMisses() const {
    return totalMisses;
}
unsigned int Logger::getTotalReadAccesses() const {
    return totalReadAccesses;
}
unsigned int Logger::getReadHits() const {
    return readHits;
}
unsigned int Logger::getReadMisses() const {
    return readMisses;
}
unsigned int Logger::getTotalWriteAccesses() const {
    return totalWriteAccesses;
}
unsigned int Logger::getWriteHits() const {
    return writeHits;
}
unsigned int Logger::getWriteMisses() const {
    return writeMisses;
}
double Logger::getTotalHitRate() const {
    return (totalAccesses == 0) ? 0.0 : static_cast<double>(totalHits)/totalAccesses;
}
double Logger::getTotalMissRate() const {
    return (totalAccesses == 0) ? 0.0 : static_cast<double>(totalMisses)/totalAccesses;
}
double Logger::getReadHitRate() const {
    return (totalReadAccesses == 0) ? 0.0 : static_cast<double>(readHits)/totalReadAccesses;
}
double Logger::getReadMissRate() const {
    return (totalReadAccesses == 0) ? 0.0 : static_cast<double>(readMisses)/totalReadAccesses;
}
double Logger::getWriteHitRate() const {
    return (totalWriteAccesses == 0) ? 0.0 : static_cast<double>(writeHits)/totalWriteAccesses;
}
double Logger::getWriteMissRate() const {
    return (totalWriteAccesses == 0) ? 0.0 : static_cast<double>(writeMisses)/totalWriteAccesses;
}