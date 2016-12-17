//
// Created by Krzysiek on 2016-12-17.
//

#ifndef OPENMP_TIMEDPICALCULATOR_H
#define OPENMP_TIMEDPICALCULATOR_H


#include "PiCalculator.h"
#include <chrono>
#include <iostream>

class TimedPiCalculator : public PiCalculator {
    std::chrono::time_point<std::chrono::_V2::system_clock> start, end;
    std::chrono::duration<double> elapsed_seconds;

public:
    TimedPiCalculator() {}

private:

    virtual void monteCarlo() override;

    virtual void monteCarloParallel() override;

    virtual void multiThread() override;

    virtual void oneThread() override;

    virtual void useFor() override;

};


#endif //OPENMP_TIMEDPICALCULATOR_H
