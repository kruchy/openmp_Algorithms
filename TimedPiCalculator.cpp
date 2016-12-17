//
// Created by Krzysiek on 2016-12-17.
//

#include "TimedPiCalculator.h"

void TimedPiCalculator::monteCarlo() {
    start = std::chrono::_V2::system_clock::now();
    PiCalculator::monteCarlo();
    end = std::chrono::_V2::system_clock::now();
    elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n" << std::endl;
}

void TimedPiCalculator::monteCarloParallel() {
    start = std::chrono::_V2::system_clock::now();
    PiCalculator::monteCarloParallel();
    end = std::chrono::_V2::system_clock::now();
    elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n" << std::endl;
}

void TimedPiCalculator::multiThread() {
    start = std::chrono::_V2::system_clock::now();
    PiCalculator::multiThread();
    end = std::chrono::_V2::system_clock::now();
    elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n" << std::endl;
}

void TimedPiCalculator::oneThread() {
    start = std::chrono::_V2::system_clock::now();
    PiCalculator::oneThread();
    end = std::chrono::_V2::system_clock::now();
    elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n" << std::endl;
}

void TimedPiCalculator::useFor() {
    start = std::chrono::_V2::system_clock::now();
    PiCalculator::useFor();
    end = std::chrono::_V2::system_clock::now();
    elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
