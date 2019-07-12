//
// Created by Dawne on 2019/7/10.
//

#ifndef CPPIMPL_SORT_PATRICK_H
#define CPPIMPL_SORT_PATRICK_H
namespace patrick{
    template <class T>
    void insertionSort(T& sequence, int lengh, bool ascend=true);
    template <class T>
    void mergeSort(T& sequence,int startIndex,int endIndex, bool ascend=true);
}
#endif //CPPIMPL_SORT_PATRICK_H
