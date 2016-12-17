#include <iostream>
#include <chrono>
#include <stdlib.h>
#include "PiCalculator.h"
#include "Sort.h"

void Apply(PiCalculator *c, void (PiCalculator::*func)());


using namespace std;

int main() {

    srand((unsigned int) time(NULL));
    PiCalculator *piCalculator = new PiCalculator();
    Apply(piCalculator, &PiCalculator::oneThread);
    Apply(piCalculator, &PiCalculator::multiThread);
    Apply(piCalculator, &PiCalculator::useFor);
    Apply(piCalculator, &PiCalculator::monteCarlo);
    Apply(piCalculator, &PiCalculator::monteCarloParallel);
//    Sort sort = Sort();
//
//    vector<long> v(1000);
//    for (long i=0; i<1000000; ++i)
//        v[i] = (i * i) % 1000000;


    return 0;
}

void Apply(PiCalculator *c, void (PiCalculator::*func)()) {
    std::chrono::time_point<std::chrono::_V2::system_clock> start, end;
    std::chrono::duration<double> elapsed_seconds;
    start = std::chrono::_V2::system_clock::now();
    (c->*func)();  // call user specified function
    end = std::chrono::_V2::system_clock::now();
    elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n" << std::endl;
}
