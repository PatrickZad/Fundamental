//
// Created by pengcheng.zhang on 2019-07-10.
//

#ifndef CPPIMPL_OTHERS_PATRICK_H
#define CPPIMPL_OTHERS_PATRICK_H

#include <vector>
namespace patrick{
    template <class T>
    T maxSubArraySumImproved(const std::vector<T>& array);
    template <class T>
    T maxSubArraySumLinear(const std::vector<T>& array,T tZero);
    template <class T>
    T dqPower(T , int);
    template <class T>
    int binarySearch(std::vector<T> array, T value);
    long FibonacciNumDownTop(long n);
    long FibonacciNum(long n);
    template <class T>
    std::vector<std::vector<T>> strassenPower(std::vector<std::vector<T>> square, int power);

}
#endif //CPPIMPL_OTHERS_PATRICK_H
