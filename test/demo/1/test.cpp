#include "test.h"

int Test::Add(int a, int b)
{
    return a + b;
}

int Test::Red(int a,int b)
{
    return a - b;
}

int Test::Mul(int a,int b)
{
    return a * b;
}

int Test::Dvi(int a, int b)
{
    if(0 == b)
    {
        return -1;
    }
    return a / b;
}

void Test::Fun()
{
    std::cout<< "A Running" <<endl;
}

void B::Fun()
{
    std::cout << "B is Running"<<endl;
}
