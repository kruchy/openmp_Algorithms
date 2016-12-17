//
// Created by Krzysiek on 2016-12-17.
//

#include "Sort.h"

Sort::Sort() {}
using namespace std;

vector<int> Sort::merge(const vector<int>& left, const vector<int>& right)
{
    vector<int> result;
    unsigned left_it = 0, right_it = 0;

    while(left_it < left.size() && right_it < right.size())
    {
        if(left[left_it] < right[right_it])
        {
            result.push_back(left[left_it]);
            left_it++;
        }
        else
        {
            result.push_back(right[right_it]);
            right_it++;
        }
    }

    // Push the remaining data from both vectors onto the resultant
    while(left_it < left.size())
    {
        result.push_back(left[left_it]);
        left_it++;
    }

    while(right_it < right.size())
    {
        result.push_back(right[right_it]);
        right_it++;
    }

    return result;
}

vector<int> Sort::mergesort(vector<int>& vec, int threads)
{
    // Termination condition: List is completely sorted if it
    // only contains a single element.
    if(vec.size() == 1)
    {
        return vec;
    }

    // Determine the location of the middle element in the vector
    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());

    // Perform a merge sort on the two smaller vectors

    if (threads > 1)
    {
#pragma omp parallel sections
        {
#pragma omp section
            {
                left = mergesort(left, threads/2);
            }
#pragma omp section
            {
                right = mergesort(right, threads - threads/2);
            }
        }
    }
    else
    {
        left = mergesort(left, 1);
        right = mergesort(right, 1);
    }

    return merge(left, right);
}