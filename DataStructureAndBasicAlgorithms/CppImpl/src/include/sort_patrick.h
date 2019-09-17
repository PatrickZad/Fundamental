//
// Created by Dawne on 2019/7/10.
//

#ifndef CPPIMPL_SORT_PATRICK_H
#define CPPIMPL_SORT_PATRICK_H

#include <vector>
namespace patrick{
    template <class C>
    void insertionSort(C& sequence, int lengh, bool ascend=true);

    template <class C>
    void selectionSort(C& collection);

    template <class C>
    void bubbleSort(C& collection);

    template <class C>
    void mergeSort(C& sequence,int startIndex,int endIndex, bool ascend=true);
    template <class C>
    void quickSort(C& array,int start,int end);

    template <class C>
    void randQuickSort(C& array);
    template <class C>

    void heapSort(C& collection);

    unsigned int[] countingSort(unsigned int (&collection)[], unsigned int length, unsigned int max);

    template <class C>
    void hillSort(C& collection);

}
#endif //CPPIMPL_SORT_PATRICK_H
