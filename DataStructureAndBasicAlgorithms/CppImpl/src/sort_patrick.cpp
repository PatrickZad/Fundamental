//
// Created by Dawne on 2019/7/10.
//
#include "include/sort_patrick.h"
using namespace patrick;
template <class C>
void insertionSort(C& sequence, int length, bool ascend){
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
void selectionSort(C& collection) {
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
void bubbleSort(C &collection) {
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
void mergeSort(C& sequence, int startIndex, int endIndex, bool ascend){
    if (endIndex==startIndex){
        return;
    }
    int medium=(startIndex+endIndex)/2;
    mergeSort(sequence,startIndex,medium,ascend);
    mergeSort(sequence,medium+1,endIndex,ascend);
    merge(sequence,startIndex,medium,endIndex,ascend);
}
template <class C>
void quickSort(C& array,int start,int end) {
    if (start==end){
        return;
    }
    int i =start,j=end;
    while(i<j){
        while(array[i]<=array[start]){
            i++;
        }
        while (array[j]>array[end]){
            j--;
        }
        auto temp=array[i];
        array[i]=array[j];
        array[j]=array[i];
        i++;
        j--;
    }
    auto temp=array[j];
    array[j]=array[start];
    array[start]=temp;
    quickSort(array,start,j-1);
    quickSort(array,i,end);
}

template <class C>
void randQuickSort(C& array, int start, int end){
    if (start==end){
        return;
    }
    int base=rand()%(end-start+1);
    auto t=array[base];
    array[base]=array[start];
    array[start]=t;
    int i =start,j=end;
    while(i<j){
        while(array[i]<=array[start]){
            i++;
        }
        while (array[j]>array[end]){
            j--;
        }
        auto temp=array[i];
        array[i]=array[j];
        array[j]=array[i];
        i++;
        j--;
    }
    auto temp=array[j];
    array[j]=array[start];
    array[start]=temp;
    randQuickSort(array,start,j-1);
    randQquickSort(array,i,end);
}

template <class C>
void heapSort(C& collection){

}


unsigned int [] countingSort(unsigned int (&collection)[], unsigned int length, unsigned int max){
    unsigned int* out=new unsigned int[length];
    unsigned int* temp=new unsigned int[max+1];
    for (unsigned int i=0;i<max;i++){
        temp[i]=0;
    }
    for (unsigned int i=0;i<length;i++){
        temp[collection[i]]++;
    }
    for (unsigned int i=1;i<max;i++){
        temp[i]+=temp[i-1];
    }
    for (int i=length-1;i>=0;i--){
        out[temp[collection[i]]-1]=collection[i];
        temp[collection[i]]--;
    }
}

template <class C>
void hillSort(C& collection){

}
