//
// Created by Krzysiek on 2016-12-17.
//

#ifndef OPENMP_SORT_H
#define OPENMP_SORT_H


#include <vector>
#include <chrono>
#include <iostream>

class Sort {
public:
    Sort();

    std::vector<int> mergesort(std::vector<int> &vec, int threads);

    std::vector<int> merge(const std::vector<int> &left, const std::vector<int> &right);
};


#endif //OPENMP_SORT_H
