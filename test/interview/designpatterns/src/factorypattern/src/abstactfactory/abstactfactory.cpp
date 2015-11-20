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


//3.抽象工厂: 

// 抽象工厂是应对产品族概念的。比如说，每个汽车公司可能要同时生产轿车，货车，客车，那么每一个工厂都要有创建轿车，货车和客车的方法。
// 应对产品族概念而生，增加新的产品线很容易，但是无法增加新的产品。
// 
//心得:抽象方法似乎达到了完美境界.把开奔驰的司机和开宝马的类型（商务和运动）的公共方法抽象出来,并对不同的司机创建不同的类,到时候不管是开什么车的类型随你添加.它们唯一的共同点都是开车.

// 产品IBusinessCar
class IBusinessCar
{
public:
    virtual void run() = 0;

    //virtual void run()
    //{
    //    printf("ICar run!\r\n");
    //}
};

// 产品ISportCar
class ISportCar
{
public:
    virtual void run() = 0;
    //virtual void run()
    //{
    //    printf("ICar run!\r\n");
    //}
};

class BMWBusinessCar : public IBusinessCar
{
public:
    void run()
    {
        printf("BMWCar run!\r\n");
    }
};

class BenzBusinessCar : public IBusinessCar
{
public:
    void run()
    {
        printf("BenzBusinessCar run!\r\n");
    }
};

class BMWSportCar : public ISportCar
{
public:
    void run()
    {
        printf("BMWSportCar run!\r\n");
    }
};

class BenzSportCar : public ISportCar
{
public:
    void run()
    {
        printf("BenzSportCar run!\r\n");
    }
};

// 工厂实现
class IDriver
{
public:
    virtual IBusinessCar* BusinessCarDriver() = 0;
    virtual ISportCar* SportCarDriver() = 0;

    //virtual IBusinessCar* BusinessCarDriver(){return NULL;}
    //virtual ISportCar* SportCarDriver(){return NULL;}
};

class BMWDriver : public IDriver
{
public:
    IBusinessCar* BusinessCarDriver()
    {
        return new BMWBusinessCar();
    }

    ISportCar* SportCarDriver()
    {
        return new BMWSportCar();
    }
};

class BenzDriver : public IDriver
{
public:
    IBusinessCar* BusinessCarDriver()
    {
        return new BenzBusinessCar();
    }

    ISportCar* SportCarDriver()
    {
        return new BenzSportCar();
    }
};

int _tmain1(int argc, _TCHAR* argv[])
{
    //Client
    IDriver* pMyDriver = new BenzDriver();
    ISportCar* pMyCar = pMyDriver->SportCarDriver();
    pMyCar->run();

    getchar();
	return 0;
}

