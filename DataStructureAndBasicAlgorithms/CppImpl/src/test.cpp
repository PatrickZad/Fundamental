//
// Created by pengcheng.zhang on 2019/8/26.
//
#include <iostream>
#include "linear_structure.h"
#include "others_patrick.h"
void testlinear();
void testothers();
class TestObject{
public:
    TestObject(int val);

private:
    int var=0;
};

int main(){
    testlinear();
    return 0;
}

TestObject::TestObject(int val) {
    this->var=val;
}
void testlinear(){
    //ExtendableArray
    patrick::ExtendableArray<TestObject> array0=patrick::ExtendableArray<TestObject>{};
    for (int i=0;i<192;i++){
        TestObject obj=TestObject{i};
        array0.append(obj);
    }
    TestObject obj=TestObject{200};
    array0.insert(64,obj);
    obj=array0.remove(66);
    patrick::ExtendableArray<TestObject> array1=array0;
    patrick::ExtendableArray<TestObject> array2=std::move(array1);
    array0.clear();
}
