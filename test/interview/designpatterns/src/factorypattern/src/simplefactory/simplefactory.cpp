// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
using namespace std;


//简单工厂,工厂方法和抽象工厂的区别 看了网络上很多关于设计模式的方法,有的模式看起来相似,但本质还是区别很大的.像简单工厂,工厂方法和抽象工厂就有很明显的区别. 
//有一个比较好理解的例子,在这跟大家介绍下: 
//1.如果一个后花园只种蔬菜类,那么就用简单工厂就可以了. 
//2.如果后花园蔬菜品种繁多.得用工厂方法才可以,把共有的东西抽象出来. 
//3.如果要扩大后花园的规模,比如一个在北方,一个在南方,这样工厂方法就无法实现了,就应当用抽象工厂,把各种各样的植物,又组成一个后花园. 
//所以我个人认为,简单工厂是一个工厂只生产一类的产品,面对的是具体的类,工厂方法是可以生产不同的产品,把公共的方法抽象出来,然后进行创建各种各样的产品.抽象工厂把几种产品划出共同的东西,把相互依赖的对象抽象出来,只要实现这些接口就可以得到不同的产品. 
//具体例子: 


//1.简单工厂: 
// 简单工厂模式的工厂类一般是使用静态方法，通过接收的参数的不同来返回不同的对象实例。
// 不修改代码的话，是无法扩展的。
// 
//心得:优点是只要实现共有的接口就可以实现不同车跑的方式.但缺点就是要判断哪一种车,造成要修改Driver 类

// 产品类
class ICar
{
public:
    //virtual void run()=0;

    virtual void run()
    {
        printf("ICar run!\r\n");
    }
};

class BMWCar : public ICar
{
public:
    void run()
    {
        printf("BMWCar run!\r\n");
    }
};

class BenzCar : public ICar
{
public:
    void run()
    {
        printf("BenzCar run!\r\n");
    }
};


#define CAR_TYPE_BMW 1
#define CAR_TYPE_BENZ 2
// 工厂类
class Driver
{
public:
    static ICar* DriverCar(int iInCarType)
    {
        switch(iInCarType)
        {
        case CAR_TYPE_BMW: return new BMWCar(); 
        case CAR_TYPE_BENZ: return new BenzCar(); 
        default:return NULL;
        }
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    ICar* pMyCar = Driver::DriverCar(CAR_TYPE_BENZ); 
    pMyCar->run();

    delete pMyCar;
    pMyCar = NULL;

    /*************************************************
     如果run函数不使用virtual关键字 则myCar调用的始终是父类的run函数，
     使用了的话父类的run函数被覆盖，调用的是子类的run函数

     C++中的虚函数的作用主要是实现了多态的机制。关于多态，简而言之就是用父类型别的指针指向其子类的实例，然后通过父类的指针调用实际子类的成员函数。
     这种技术可以让父类的指针有“多种形态”，这是一种泛型技术。所谓泛型技术，说白了就是试图使用不变的代码来实现可变的算法。
     比如：模板技术，RTTI技术，虚函数技术，要么是试图做到在编译时决议，要么试图做到运行时决议。

     C++支持编译时多态和运行时多态，运算符重载和函数重载就是编译时多态，而派生类和虚函数实现运行时多态
     运行时多态的基础是基类指针，基类指针可以指向任何派生类对象
     *************************************************/
    getchar();
	return 0;
}

