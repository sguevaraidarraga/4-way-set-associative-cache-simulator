#ifndef LOGGER_H
#define LOGGER_H

class Logger {
    unsigned int totalAccesses, hits, misses;
    Logger();

    public:
        static Logger& getInstance();
        void logHit();
        void logMiss();
        unsigned int getTotalAccesses() const;
        unsigned int getHits() const;
        unsigned int getMisses() const;
        double getHitRate() const;
        double getMissRate() const;
};

#endif