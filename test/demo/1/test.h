#ifndef TEST_H
#define TEST_H
#include <iostream>
using namespace std;
class testA
{
public:
    testA(){};
    virtual ~testA(){};

public:
    int Add(int a,int b);
    int Red(int a,int b);
    int Mul(int a,int b);
    int Dvi(int a,int b);

    virtual void Fun() ;
};

class testB : public testA
{
public:
    testB(){};
    ~testB(){};

public:
    virtual void Fun();
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

#define NUM 6

void *thread_function(void *arg);
int test_thread();

#endif // TEST_H
