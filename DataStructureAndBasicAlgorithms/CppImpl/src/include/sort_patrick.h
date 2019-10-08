//
// Created by Dawne on 2019/7/10.
//

#ifndef CPPIMPL_SORT_PATRICK_H
#define CPPIMPL_SORT_PATRICK_H

#include <vector>
namespace patrick{

    template <class P>
    class CountingSortNum{
    public:
        virtual unsigned int getSortValue(P& param)=0;
    };

    class DigitNumber : public CountingSortNum<int>{
    private:
        bool isInteger;
        unsigned int intDigitLength;
        unsigned int decDigitLength;
        int* intDigitArray;
        int* decimalDigitArray;
    public:
        DigitNumber(long integer, unsigned int intLength);
        DigitNumber(double decimal, unsigned int intLength, unsigned int decLength);
        int getIntDigit(unsigned int index);
        int getDecDigit(unsigned int index);
        unsigned int getSortValue(int& index);
    };

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

    unsigned int* countingSort(unsigned int (&collection)[], unsigned int length, unsigned int max);

    template <class C>
    void hillSort(C& collection);
void radixSort(DigitNumber (&collection)[]);


}
#endif //CPPIMPL_SORT_PATRICK_H
