#include <iostream>
#include <chrono>
#include <stdlib.h>
#include "PiCalculator.h"
#include "TimedPiCalculator.h"

using namespace std;


int main() {

    srand((unsigned int) time(NULL));
    PiCalculator *piCalculator = new TimedPiCalculator();
    piCalculator->multiThread();
    piCalculator->useFor();
    piCalculator->monteCarlo();
    piCalculator->monteCarloParallel();

//    dodatkowo liczenie porpabilistycze jednoredzeniowo i zrownoleglic i ma byc szybciej
//     MA BYC SZYBCIEJ bo zmienne lokalne
    return 0;
}

