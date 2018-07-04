#ifndef TEST_H
#define TEST_H
#include <iostream>
using namespace std;
class Test
{
public:
    Test(){};
    virtual ~Test(){};

public:
    int Add(int a,int b);
    int Red(int a,int b);
    int Mul(int a,int b);
    int Dvi(int a,int b);

    virtual void Fun() ;
};

class B : public Test
{
public:
    B(){};
    ~B(){};

public:
    virtual void Fun();
};

#endif // TEST_H
