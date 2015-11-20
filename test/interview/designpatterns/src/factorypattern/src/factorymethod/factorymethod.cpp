// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//简单工厂,工厂方法和抽象工厂的区别 看了网络上很多关于设计模式的方法,有的模式看起来相似,但本质还是区别很大的.像简单工厂,工厂方法和抽象工厂就有很明显的区别. 
//有一个比较好理解的例子,在这跟大家介绍下: 
//1.如果一个后花园只种蔬菜类,那么就用简单工厂就可以了. 
//2.如果后花园蔬菜品种繁多.得用工厂方法才可以,把共有的东西抽象出来. 
//3.如果要扩大后花园的规模,比如一个在北方,一个在南方,这样工厂方法就无法实现了,就应当用抽象工厂,把各种各样的植物,又组成一个后花园. 
//所以我个人认为,简单工厂是一个工厂只生产一类的产品,面对的是具体的类,工厂方法是可以生产不同的产品,把公共的方法抽象出来,然后进行创建各种各样的产品.抽象工厂把几种产品划出共同的东西,把相互依赖的对象抽象出来,只要实现这些接口就可以得到不同的产品. 
//具体例子: 


//2.工厂方法: 
// 工厂方法是针对每一种产品提供一个工厂类。通过不同的工厂实例来创建不同的产品实例。
// 在同一等级结构中，支持增加任意产品。

//心得:优点是符合了开放-封闭原则(OCP),从整体上还看不出什么缺点.
//产品类
class ICar
{
public:
    virtual void run() = 0;

    //virtual void run()
    //{
    //    printf("ICar run!\r\n");
    //}
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

//工厂类
class Driver 
{ 
public:
    virtual ICar* DriverCar() = 0; 
    //virtual ICar* DriverCar()
    //{
    //    printf("DriverCar\r\n");   
    //    return NULL;
    //}; 
};

class BMWDriver : public Driver 
{ 
public:
    ICar* DriverCar() 
    { 
        return new BMWCar(); 
    } 

};

class BenzDriver : public Driver  
{ 
public:
    ICar* DriverCar() 
    { 
        return new BenzCar(); 
    } 
};

int _tmain1(int argc, _TCHAR* argv[])
{
    Driver* pMyDriver = new BenzDriver(); 
    ICar* pMyCar = pMyDriver->DriverCar(); 
    pMyCar->run(); 

    delete pMyCar;
    pMyCar = NULL;

    getchar();
	return 0;
}

