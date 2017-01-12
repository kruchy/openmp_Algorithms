//
// Created by Krzysiek on 2016-12-17.
//

#include <omp.h>
#include "Sort.h"

Sort::Sort() {}

using namespace std;


vector<int> Sort::merge(vector<int> &left, vector<int> &right) {
    vector<int> result;
    vector<int>::iterator leftIterator = left.begin();
    vector<int>::iterator rightIterator = right.begin();

    while (leftIterator != left.end() && rightIterator != right.end()) {
        if (*leftIterator < *rightIterator) {
            result.push_back(*leftIterator);
            leftIterator++;
        } else {
            result.push_back(*rightIterator);
            rightIterator++;
        }
    }
    while (leftIterator < left.end()) {
        result.push_back(*leftIterator);
        leftIterator++;
    }

    while (rightIterator < right.end()) {
        result.push_back(*rightIterator);
        rightIterator++;
    }

    return result;
}

vector<int> Sort::mergeSort(vector<int> vec, int threads) {

    if (vec.size() == 1) {
        return vec;
    }
    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());

    if (threads == 1) {
        left = mergeSort(left, 1);
        right = mergeSort(right, 1);
    } else {
#pragma omp parallel sections
        {
            omp_set_nested(1);
#pragma omp section
            {
//                cout << omp_get_thread_num() << endl;
                left = mergeSort(left, threads / 2);
            }
#pragma omp section
            {
//                cout << omp_get_thread_num() << endl;

                right = mergeSort(right, threads - threads / 2);
            }
        }
    }


    return merge(left, right);
}


