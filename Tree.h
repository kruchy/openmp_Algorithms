//
// Created by Krzysiek on 2016-12-19.
//

#ifndef OPENMP_TREE_H
#define OPENMP_TREE_H


class Tree {
    Tree *left;
    Tree *right;
    std::__cxx11::string value;
public:
    Tree(std::__cxx11::string value) : value(value) {}

    Tree(Tree *left, Tree *right) : left(left), right(right) {}

};


#endif //OPENMP_TREE_H
