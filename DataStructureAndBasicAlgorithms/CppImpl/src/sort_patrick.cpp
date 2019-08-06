//
// Created by Dawne on 2019/7/10.
//
#include "include/sort_patrick.h"
template <class C>
void patrick::insertionSort(C& sequence, int length, bool ascend){
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
template <class C>
void patrick::selectionSort(C& collection) {
    for (int i = 0; i < collection.size(); ++i) {
        int min=i;
        for (int j = i+1;j<collection.size();j++){
            if (collection[j]<collection[i]){
                min=j;
            }
        }
        auto temp=collection[i];
        collection[i]=collection[min];
        collection[min]=temp;
    }
}
template <class C>
void patrick::bubbleSort(C &collection) {
    for (int i = collection.size()-1; i > 0 ; i--) {
        for (int j = 0; j <i ; ++j) {
            if (collection[j]>collection[j+1]){
                auto temp=collection[j];
                collection[j]=collection[j+1];
                collection[j+1]=temp;
            }
        }
    }
}
template <class C>
inline void merge(C& sequence, int start, int end0, int end1, bool ascend){
    C result=C{end1-start+1};
    if(ascend){
        int i=start,j=start+1;
        int k=start;
        if (ascend){
            while (i<=end0 && j<=end1){
                if (sequence[j]<sequence[i]){
                    result[k]=sequence[j];
                    j++;
                    k++;
                } else{
                    result[k]=sequence[i];
                    i++;
                    k++;
                }
            }
        } else{
            while (i<=end0 && j<=end1){
                if (sequence[j]>sequence[i]){
                    result[k]=sequence[j];
                    j++;
                    k++;
                } else{
                    result[k]=sequence[i];
                    i++;
                    k++;
                }
            }
        }
        while (i<=end0){
            result[k]=sequence[i];
            i++;
            k++;
        }
        while (j<=end1){
            result[k]=sequence[j];
            j++;
            k++;
        }
        for (int i = 0; i < result.size(); i++) {
            sequence[start+i]=result[i];
        }
    }
}
template <class C>
void patrick::mergeSort(C& sequence, int startIndex, int endIndex, bool ascend){
    if (endIndex==startIndex){
        return;
    }
    int medium=(startIndex+endIndex)/2;
    patrick::mergeSort(sequence,startIndex,medium,ascend);
    patrick::mergeSort(sequence,medium+1,endIndex,ascend);
    merge(sequence,startIndex,medium,endIndex,ascend);
}
template <class C>
void patrick::quickSort(C& array,int start,int end) {
    if (start==end){
        return;
    }
    int i =0,j=array.size()-1;
    while(i<j){
        while(array[i]<=array[0]){
            i++;
        }
        while (array[j]>array[0]){
            j--;
        }
        auto temp=array[i];
        array[i]=array[j];
        array[j]=array[i];
        i++;
        j--;
    }
    auto temp=array[j];
    array[j]=array[0];
    array[0]=temp;
    patrick::quickSort(array,start,j-1);
    patrick::quickSort(array,i,end);
}
