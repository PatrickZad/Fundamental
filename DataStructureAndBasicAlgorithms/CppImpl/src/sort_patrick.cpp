//
// Created by Dawne on 2019/7/10.
//
#include "include/sort_patrick.h"
template <class T>
void patrick::insertionSort(T& sequence, int length, bool ascend){
    for(int i=1;i<length;i++){
        for(int j=i-1;j>=0;j--){
            auto temp=sequence[i];
            if(ascend){
                if (sequence[i]>temp){
                    sequence[j]=sequence[i];
                    sequence[i]=temp;
                } else{
                    break;
                }
            } else{
                if(sequence[i]<temp){
                    sequence[i]=sequence[j];
                    sequence[i]=temp;
                } else{
                    break;
                }
            }
        }
    }
}
template <class T>
inline void merge(T& sequence, int start0, int end0, int start1, int end1){

}
template <class T>
void patrick::mergeSort(T& sequence, int startIndex, int endIndex){

}

