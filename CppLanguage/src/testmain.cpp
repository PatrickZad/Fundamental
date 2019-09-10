//
// Created by Patrick on 2019/6/25.
//
#include "testFuncs.h"
#include <vector>
#include <iostream>
#include <utility>
#include "testFuncs.h"
class TestRref{
public:
    std::vector<int> v=std::vector<int>{};
};
void testrr(std::vector<int>&& v){
    std::cout<<"done";
}
int main(){
    int k=6;
    int& rk=k;
    //test::referenceParam(rk,k);
    //test::lambdaExpr();
    //test::namedTypeTrans();
    //test::refAndptr();
    //test::deletearray();
    //TestRref obj=TestRref{};
    //testrr(std::move(obj).v);
    test::DerivedClass* ptr = new test::DerivedClass{};
    test::testVirtual(ptr);
    return 0;
}
