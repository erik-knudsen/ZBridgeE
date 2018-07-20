#ifndef SLEEPSIMULATOR_H
#define SLEEPSIMULATOR_H

#include <QMutex>
#include <QWaitCondition>

class SleepSimulator{
     QMutex localMutex;
     QWaitCondition sleepSimulator;
public:
    SleepSimulator()
    {
        localMutex.lock();
    }
    void sleep(unsigned long sleepMS)
    {
        sleepSimulator.wait(&localMutex, sleepMS);
    }
    void CancelSleep()
    {
        sleepSimulator.wakeAll();
    }
};
#endif // SLEEPSIMULATOR_H
