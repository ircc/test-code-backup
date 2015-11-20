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

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

/*
抽象工厂模式与工厂方法模式的区别

抽象工厂模式是工厂方法模式的升级版本，他用来创建一组相关或者相互依赖的对象。
他与工厂方法模式的区别就在于，工厂方法模式针对的是一个产品等级结构；而抽象工厂模式则是针对的多个产品等级结构。
在编程中，通常一个产品结构，表现为一个接口或者抽象类，也就是说，工厂方法模式提供的所有产品都是衍生自同一个接口或抽象类，而抽象工厂模式所提供的产品则是衍生自不同的接口或抽象类。

在抽象工厂模式中，有一个产品族的概念：所谓的产品族，是指位于不同产品等级结构中功能相关联的产品组成的家族。
抽象工厂模式所提供的一系列产品就组成一个产品族；而工厂方法提供的一系列产品称为一个等级结构。

继之前的简单工厂和工厂模式拿手机的例子来说明他们之间的区别。

假如Nokia的N95手机和苹果的iphone5手机是同一代产品，N96和iphone6也是同一代产品，同一时间只出同一代产品，
用一个工厂只生产一个品牌的手机显然是不合算的 所以同一代产品就是相关的对象可以在同一个工厂生产
新一代产品出来了  还需要保持老产品的继续生产  所以另建一个工厂是最符合要求的



抽象工厂模式的优点
抽象工厂模式除了具有工厂方法模式的优点外，最主要的优点就是可以在类的内部对产品族进行约束。
所谓的产品族，一般或多或少的都存在一定的关联，抽象工厂模式就可以在类内部对产品族的关联关系进行定义和描述，而不必专门引入一个新的类来进行管理。

抽象工厂模式的缺点
产品族的扩展将是一件十分费力的事情，假如产品族中需要增加一个新的产品，则几乎所有的工厂类都需要进行修改。所以使用抽象工厂模式时，对产品等级结构的划分是非常重要的。

适用场景
当需要创建的对象是一系列相互关联或相互依赖的产品族时，便可以使用抽象工厂模式。
说的更明白一点，就是一个继承体系中，如果存在着多个等级结构（即存在着多个抽象类），并且分属各个等级结构中的实现类之间存在着一定的关联或者约束，就可以使用抽象工厂模式。
假如各个等级结构中的实现类之间不存在关联或约束，则使用多个独立的工厂来对产品进行创建，则更合适一点。

总结
无论是简单工厂模式，工厂方法模式，还是抽象工厂模式，他们都属于工厂模式，在形式和特点上也是极为相似的，他们的最终目的都是为了解耦。
在使用时，我们不必去在意这个模式到底工厂方法模式还是抽象工厂模式，因为他们之间的演变常常是令人琢磨不透的。
经常你会发现，明明使用的工厂方法模式，当新需求来临，稍加修改，加入了一个新方法后，由于类中的产品构成了不同等级结构中的产品族，它就变成抽象工厂模式了；
而对于抽象工厂模式，当减少一个方法使的提供的产品不再构成产品族之后，它就演变成了工厂方法模式。

所以，在使用工厂模式时，只需要关心降低耦合度的目的是否达到了。
*/

//抽象工厂


/* Nokia抽象产品 */
class CNokia
{
public:
    CNokia(void){}
public:
    virtual ~CNokia(void){}
public:
    virtual bool MakeCall(const std::string & number) const = 0;
};

/* Iphone抽象产品 */
class CIphone
{
public:
    CIphone(void){}
public:
    virtual ~CIphone(void){}
public:
    virtual bool MakeCall(const std::string & number) const = 0;
};


/* N95型号的Nokia手机产品类 */
class CN95 : public CNokia
{
public:
    CN95(void)
    {
        std::cout << "生产一部N95" << std::endl;
    }
public:
    virtual ~CN95(void){}
public:
    virtual bool MakeCall(const std::string & number) const
    {
        std::cout << "我在用N95，拨打号码是：" <<  number.c_str() << std::endl;
        return false;
    }
};


/* N96型号的Nokia手机产品类 */  
class CN96 : public CNokia
{
public:
    CN96(void)
    {
        std::cout << "生产一部N96" << std::endl;
    }

public:
    virtual ~CN96(void){}
public:
    virtual bool MakeCall(const std::string & number) const
    {
        std::cout << "我在用N96，拨打号码是：" <<  number.c_str() << std::endl;
        return false;
    }
};


/*Iphone5, Iphone6, ...*/
/* Iphone5型号的Iphone手机产品类 */
class CIphone5 : public CIphone
{
public:
    CIphone5(void)
    {
        std::cout << "生产一部Iphone5" << std::endl;
    }
public:
    virtual ~CIphone5(void){}
public:
    virtual bool MakeCall(const std::string & number) const
    {
        std::cout << "我在用Iphone5，拨打号码是：" <<  number.c_str() << std::endl;
        return false;
    }
};

/* Iphone6型号的Iphone手机产品类 */
class CIphone6 : public CIphone
{
public:
    CIphone6(void)
    {
        std::cout << "生产一部Iphone6" << std::endl;
    }
public:
    virtual ~CIphone6(void){}
public:
    virtual bool MakeCall(const std::string & number) const
    {
        std::cout << "我在用Iphone6，拨打号码是：" <<  number.c_str() << std::endl;
        return false;
    }
};




/* 抽象工厂类 */
class CFactoryMethod
{
public:
    CFactoryMethod(void){}
public:
    virtual ~CFactoryMethod(void){}
public:
    virtual CNokia* CreateNokiaMobile(void) = 0;
    virtual CIphone* CreateIphoneMobile(void) = 0;
};


/* 生产Nokia和iphone 5代的具体工厂类 */
class CIN5Factory : public CFactoryMethod
{
public:
    CIN5Factory(void){}
public:
    virtual ~CIN5Factory(void){}
public:
    virtual CNokia* CreateNokiaMobile(void)
    {
        return new CN95();
    }

    virtual CIphone* CreateIphoneMobile(void)
    {
        return new CIphone5();
    }
};

/* 生产Nokia和iphone 6代的具体工厂类 */
class CIN6Factory : public CFactoryMethod
{
public:
    CIN6Factory(void){}
public:
    virtual ~CIN6Factory(void){}
public:
    virtual CNokia* CreateNokiaMobile(void)
    {
        return new CN96();
    }

    virtual CIphone* CreateIphoneMobile(void)
    {
        return new CIphone6();
    }
};

/* 客户端通过建立N99工厂生产Nokia手机 */
int _tmain(int argc, _TCHAR* argv[])
{
    //5代工厂 生产一个n95的诺基亚
    CFactoryMethod* pclsFactoryMethod = new CIN5Factory();
    CNokia * pclsNokia = pclsFactoryMethod->CreateNokiaMobile();
    pclsNokia->MakeCall("1234567");

    delete pclsNokia;
    pclsNokia = NULL;
    delete pclsFactoryMethod;
    pclsFactoryMethod = NULL;

    //6代工厂 生产了一个iphone6
    CFactoryMethod* pclsFactoryMethod2 = new CIN6Factory();
    CIphone * pclsIphone = pclsFactoryMethod2->CreateIphoneMobile();
    pclsIphone->MakeCall("7654321");

    delete pclsIphone;
    pclsIphone = NULL;
    delete pclsFactoryMethod2;
    pclsFactoryMethod2 = NULL;


    return 0;
}