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
    const int* ip=&i;
    int& rp=i;
    i++;
    auto ncip= const_cast<int*>(ip);
    (*ncip)++;
    auto crp= const_cast<const int&>(rp);
    crp++;
}
