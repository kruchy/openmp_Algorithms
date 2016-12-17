#include <iostream>
#include <omp.h>
#include <chrono>
#include <cstdlib>

using namespace std;

double f1(double x) {
    return x * x;
}

double f(double x) {
    return 4 / (1 + (x * x));
}

double suma[] = {0, 0, 0, 0, 0, 0, 0, 0};
double dx = 0.000000003;
double l = 1 / dx;

void oneThread();

void multiThread();

void monteCarlo();

void monteCarloParallel();

int main() {


    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    oneThread();
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    cout << endl << "start parallel" << endl;
    start = std::chrono::system_clock::now();
    multiThread();
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

//    double s2 = 0;
//    long x;
//#pragma omp parallel for reduction(+:s2)
//    for (x = 0; x < l; x++) {
//        s2 += f(x * dx) * dx;
//    }
//    end = std::chrono::system_clock::now();
//    elapsed_seconds = end - start;
//    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
//    cout << " new sum aftter reduction " << s2;

    start = std::chrono::system_clock::now();
    monteCarlo();
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    start = std::chrono::system_clock::now();
    monteCarloParallel();
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

//    dodatkowo liczenie porpabilistycze jednoredzeniowo i zrownoleglic i ma byc szybciej
//     MA BYC SZYBCIEJ bo zmienne lokalne
    return 0;
}

void monteCarlo() {
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

void monteCarloParallel() {
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

void multiThread() {
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

void oneThread() {
    cout << "start one thread" << endl;
    double suma1 = 0;
    for (int x1 = 0; x1 < l; x1 += 1) {
        suma1 += f(x1 * dx) * dx;
    }
    cout << "SUM ONE THREAD = " << suma1 << endl;
}

