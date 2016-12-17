//
// Created by Krzysiek on 2016-12-17.
//

#include "PiCalculator.h"
using namespace std;

double PiCalculator::f1(double x) {
    return x * x;
}

double PiCalculator::f(double x) {
    return 4 / (1 + (x * x));
}

void PiCalculator::monteCarlo() {
    long CIRCLE_POINTS = 0;
    srand((unsigned int) time(NULL));
    cout << "Count points " << endl;
    long POINTS = 100000000;
    for (long i = 0; i < POINTS; i++) {
        double x = ((double) rand() / (RAND_MAX + 1));
        double y = ((double) rand() / (RAND_MAX + 1));
        if (x * x + y * y <= 1)
            CIRCLE_POINTS++;
    }
    double result = (double) CIRCLE_POINTS / (double) POINTS;
    cout << " CIRCLE_POINTS : " << CIRCLE_POINTS << endl;
    cout << " POINTS : " << POINTS << endl;
    cout << "PI : " << 4 * result << endl;
}

void PiCalculator::monteCarloParallel() {
    long CIRCLE_POINTS = 0;
    srand((unsigned int) time(NULL));
    cout << "Count points " << endl;
    long POINTS = 100000000;
    int all[8];
    for (int i = 0; i < 8; i++) {
        all[i] = 0;
    }
#pragma omp parallel
    {
        int n = omp_get_thread_num();
        int k = omp_get_num_threads();
        long a = 0;


        double s = 0;
        for (long i = n; i < POINTS; i+=k) {

            double x = ((double) rand() / (RAND_MAX + 1));
            double y = ((double) rand() / (RAND_MAX + 1));
            if (x * x + y * y <= 1)
                a++;
        }
        all[n] += a;
    }
    for (int i = 0; i < 8; i++) {
        CIRCLE_POINTS += all[i];
    }
    double result = (double) CIRCLE_POINTS / (double) POINTS;
    cout << "PARALLEL CIRCLE_POINTS : " << CIRCLE_POINTS << endl;
    cout << "PARALLEL POINTS : " << POINTS << endl;
    cout << "PARALLEL PI : " << 4 * result << endl;
}

void PiCalculator::multiThread() {
    double s = 0;
#pragma omp parallel
    {

        double s = 0;
        int n = omp_get_thread_num();
        int k = omp_get_num_threads();
//        cout <<  n << "/" << k  << " " << endl;
        for (int x = n; x < l; x += k) {
            s += f(x * dx) * dx;
        }
        suma[n] += s;

    }
    double sum = 0;
    for (int i = 0; i < 8; i++) {
        sum += suma[i];
    }
    cout << "SUMA MULTITHREAD = " << sum << endl;

}

void PiCalculator::oneThread() {
    cout << "start one thread" << endl;
    double suma1 = 0;
    for (int x1 = 0; x1 < l; x1 += 1) {
        suma1 += f(x1 * dx) * dx;
    }
    cout << "SUM ONE THREAD = " << suma1 << endl;
}

void PiCalculator::useFor() {
//    double s2 = 0;
//    long x;
//#pragma omp parallel for reduction(+:s2)
//    for (x = 0; x < l; x++) {
//        s2 += f(x * dx) * dx;
//    }
//    cout << " new sum aftter reduction " << s2 << endl;


}
