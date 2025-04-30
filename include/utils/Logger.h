#ifndef LOGGER_H
#define LOGGER_H

class Logger {
    unsigned int totalAccesses, totalHits, totalMisses,
                 totalReadAccesses, readHits, readMisses,
                 totalWriteAccesses, writeHits, writeMisses;
    
    Logger() = default;

    public:
        static Logger& getInstance();
        void logReadHit();
        void logReadMiss();
        void logWriteHit();
        void logWriteMiss();
        unsigned int getTotalAccesses() const;
        unsigned int getTotalHits() const;
        unsigned int getTotalMisses() const;
        unsigned int getTotalReadAccesses() const;
        unsigned int getReadHits() const;
        unsigned int getReadMisses() const;
        unsigned int getTotalWriteAccesses() const;
        unsigned int getWriteHits() const;
        unsigned int getWriteMisses() const;
        double getTotalHitRate() const;
        double getTotalMissRate() const;
        double getReadHitRate() const;
        double getReadMissRate() const;
        double getWriteHitRate() const;
        double getWriteMissRate() const;
};

#endif