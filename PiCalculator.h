//
// Created by Krzysiek on 2016-12-17.
//
#include <iostream>

#include <chrono>
#include <stdlib.h>
#include "omp.h"
#ifndef OPENMP_PICALCULATOR_H
#define OPENMP_PICALCULATOR_H
class PiCalculator
{
    double f1(double x) ;

    double f(double x) ;
public:
    double suma[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    double dx = 0.000000003;
    double l = 1 / dx;

    virtual void monteCarlo();

    virtual void monteCarloParallel();

    virtual void multiThread();

    virtual void oneThread();

    virtual void useFor();

};
#endif //OPENMP_PICALCULATOR_H
