//
// Created by Patrick on 2019/6/25.
//

#ifndef PRACTICE_TESTFUNCS_H
#define PRACTICE_TESTFUNCS_H
namespace test{
    void lambdaExpr();
    void referenceParam(int , int& );
    void namedTypeTrans();
    void nullReference();
    class MyClass{
    public:
        MyClass();

    private:
        int& num;
    };
}
#endif //PRACTICE_TESTFUNCS_H
