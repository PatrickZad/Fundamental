//
// Created by Dawne on 2019/6/25.
//
#include "testFuncs.h"
#include <iostream>
void test::lambdaExpr(){
    int i=1;
    int j=2;
    auto result=[=]()->int { int k =i+j;return k;};
    std::cout<< sizeof(result);
}
void test::referenceParam(int i, int& j){
    i++;
    j++;
}
void test::namedTypeTrans(){
    int i=2;
    const int k=6;
    const int* ip=&i;
    const int& rp=i;
    i++;
    auto ncip= const_cast<int*>(ip);
    (*ncip)++;
    auto crp= const_cast<int&>(rp);
    //crp++;
    //auto ck= const_cast<int>(k);
    //ck++;
    //rp++;
}

void test::refAndptr() {
    int num=6;
    int& rnum=num;
    int* pnum=&num;
    int* prnum=&rnum;
    //int&* pr=&num;
    if (pnum==prnum){
        std::cout<<"done";
    }
}
void test::deletearray() {
    int** array0=new int*[8];
    int** array1=array0;
    delete [] array1;
    int num=6;
    array0[0]=&num;
    array1[0]=&num;
}

