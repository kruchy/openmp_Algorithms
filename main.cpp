#include <iostream>
#include <chrono>
#include <stdlib.h>
#include "PiCalculator.h"
#include "Sort.h"
#include "Input.h"

#include <map>

void Apply(PiCalculator *c, void (PiCalculator::*func)());

using namespace std;

string isSorted(vector<int> vec);

string huffman(string input) ;

int main() {

//    srand((unsigned int) time(NULL));
//    PiCalculator *piCalculator = new PiCalculator();
//    Apply(piCalculator, &PiCalculator::oneThread);
//    Apply(piCalculator, &PiCalculator::multiThread);
//    Apply(piCalculator, &PiCalculator::useFor);
//    Apply(piCalculator, &PiCalculator::monteCarlo);
//    Apply(piCalculator, &PiCalculator::monteCarloParallel);
//    Sort sort = Sort();
//    unsigned int number = 10000000;
//    vector<int> v(number), u(number);
//    for (int i = 0; i < number; ++i) {
//        v[i] = (i * i) % number;
//        u[i] = (i * i) % number;
//    }
//
//    std::chrono::time_point<std::chrono::_V2::system_clock> start, end;
//    std::chrono::duration<double> elapsed_seconds;
//
//
//    cout << "8 thread " << endl;
//    start = std::chrono::_V2::system_clock::now();
//    vector<int> a = sort.mergeSort(v, 8);
//    end = std::chrono::_V2::system_clock::now();
//    elapsed_seconds = end - start;
//    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n" << std::endl;
//    cout << "8 thread ended" << endl;
//
//    cout << "ONE thread " << endl;
//    start = std::chrono::_V2::system_clock::now();
//    vector<int> b = sort.mergeSort(u, 1);
//    end = std::chrono::_V2::system_clock::now();
//    elapsed_seconds = end - start;
//    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n" << std::endl;
//
//    cout << "ONE thread ended" << endl;
//
//    start = std::chrono::_V2::system_clock::now();
//    end = std::chrono::_V2::system_clock::now();
//    elapsed_seconds = end - start;
//    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n" << std::endl;

    huffman("ABABAABAACDDE");
    return 0;
}

void Apply(PiCalculator *c, void (PiCalculator::*func)()) {
    std::chrono::time_point<std::chrono::_V2::system_clock> start, end;
    std::chrono::duration<double> elapsed_seconds;
    start = std::chrono::_V2::system_clock::now();
    (c->*func)();
    end = std::chrono::_V2::system_clock::now();
    elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n" << std::endl;
}

string huffman(string input) {


    std::map<char, int> hufmans;
    vector<Input> inputs;
    for (char &c : input) {
        if(inputs.)
    }
    for(auto p : hufmans)
    {
        cout << p.first <<  " " << p.second << endl;
    }
    return input;
}


string isSorted(vector<int> vec) {
    bool res = true;
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i] > vec[i + 1]) {
            res = false;
        }
    }
    return res ? "TRUE" : "FALSE";
}
