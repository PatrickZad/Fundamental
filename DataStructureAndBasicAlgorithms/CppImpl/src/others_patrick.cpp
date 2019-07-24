//
// Created by pengcheng.zhang on 2019-07-10.
//
#include "others_patrick.h"
#include <vector>

template<class T>
T patrick::maxSubArraySumImproved(const std::vector <T> &array) {
    T sum = array[0];
    std::vector <T> subStartSum = new std::vector <T>{array.size()};
    subStartSum[0] = array[0];
    for (int i = 1; i < array.size(); i++) {
        subStartSum[i] = subStartSum[i - 1] + array[i];
    }
    for (int i = 1; i < array.size(); i++) {
        for (int j = i; j < array.size(); j++) {
            if (subStartSum[j] - subStartSum[i - 1] > sum) {
                sum=subStartSum[j]-subStartSum[i-1];
            }
        }
    }
    return sum;
}

template<class T>
T patrick:: maxSubArraySumLinear(const std::vector <T> &array, T tZero) {
    T sum=tZero;
    std::vector<T> subPostfixSum = new std::vector<T>{array.size()};
    subPostfixSum[0]=array[0]>tZero ? array[0] : tZero;
    for (int i = 1; i <array.size() ; i++) {
        subPostfixSum[i] = (subPostfixSum[i-1]+array[i])>tZero ?
                (subPostfixSum[i-1]+array[i]) : tZero ;
    }
    for (int j = 0; j < subPostfixSum.size(); ++j) {
        if (subPostfixSum[j]>sum){
            sum=subPostfixSum[j];
        }
    }
    return sum;
}

