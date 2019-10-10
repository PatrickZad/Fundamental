//
// Created by Patrick on 2019/6/25.
//

#ifndef PRACTICE_TESTFUNCS_H
#define PRACTICE_TESTFUNCS_H
namespace test{
    void lambdaExpr();
    void referenceParam(int , int& );
    void namedTypeTrans();
    class MyClass{
    public:
        int* ptr;
    public:
        //MyClass();

    private:
        //int& num;
    };
    void refAndptr();
    void deletearray();
    class BasicC{
    public:
        int atrr0;
    };
    class DerivedC : public BasicC{
    public:
        int attr1;
    };
    void dynamicCastTest();
    class BaseClass{
    public:
        virtual void func();
    };
    class DerivedClass: public BaseClass{
    public:
        void func();
    };
    void testVirtual(BaseClass* obj);
}
#endif //PRACTICE_TESTFUNCS_H
