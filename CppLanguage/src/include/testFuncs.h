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
        MyClass();

    private:
        int& num;
    };
    void refAndptr();
    void deletearray();
}
#endif //PRACTICE_TESTFUNCS_H
