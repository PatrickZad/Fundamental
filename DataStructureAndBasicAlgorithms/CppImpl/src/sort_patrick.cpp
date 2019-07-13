//
// Created by Dawne on 2019/7/10.
//
#include "include/sort_patrick.h"
#include <vector>
template <class T>
void patrick::insertionSort(std::vector<T>& sequence, int length, bool ascend){
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
inline void merge(std::vector<T>& sequence, int start, int end0, int end1, bool ascend){
    std::vector<T> result=new std::vector<T>(end1-start+1);
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
template <class T>
void patrick::mergeSort(std::vector<T>& sequence, int startIndex, int endIndex, bool ascend){
    if (endIndex==startIndex){
        return;
    }
    int medium=(startIndex+endIndex)/2;
    patrick::mergeSort(sequence,startIndex,medium,ascend);
    patrick::mergeSort(sequence,medium+1,endIndex,ascend);
    merge(sequence,startIndex,medium,endIndex,ascend);
}

