//
// Created by patrick on 9/14/19.
//

#include "include/linear_structure_test.h"
#include "linear_structure.h"
using namespace patrick;

TestElement::TestElement(int val) {
    this->var=val;
}

void testExtendableArray(){
    //ExtendableArray
    patrick::ExtendableArray<TestElement> array0=patrick::ExtendableArray<TestElement>{};
    for (int i=0;i<192;i++){
        TestElement obj=TestElement{i};
        array0.append(obj);
    }
    TestElement obj=TestElement{200};
    array0.insert(64,obj);
    obj=array0.remove(66);
    patrick::ExtendableArray<TestElement> array1=array0;
    patrick::ExtendableArray<TestElement> array2=std::move(array1);
    array0.clear();
}