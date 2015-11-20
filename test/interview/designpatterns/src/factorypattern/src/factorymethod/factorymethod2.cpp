// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

/*
http://blog.csdn.net/chollima/article/details/3989145
工厂方法模式是对简单工厂模式的改进。首先看看简单工厂模式的缺点。
软件是之所以区别于程序，是因为它可以被人们使用，并能间接创造效益。需求是软件开发的核心，忽视用户的需求，软件本身就没有存在的价值。

假如Nokia又新开发了一款新手机N99，对于采用简单工厂模式设计的系统，我们的做法是：
1.新增一个CN99类继承自CNokia抽象类，这个符合开闭原则(OCP)。
注：OCP:Open-Closed Principle开闭原则。OCP关注的是灵活性，改动是通过增加代码进行的，而不是改动现有的代码。
        对扩展开放，对修改关闭。

2.修改静态工厂方法中的判断逻辑，增加对N99的创建代码。这个明显违背OCP。

改进简单工厂模式，我们要做的就是克服2中的缺点。


下面的工厂方法模式，新增一个N96的工厂类，不用修改已有的代码，完全支持OCP原则，而且工厂方法模式也完全遵守里氏替换原则，LSP原则是OCP成为可能的重要原则。
注：Liskov Substitution Principle（里氏代换原则）：子类型(subtype)必须能够替换它们的基类型。

虽然工厂方法模式是对简单工厂模式缺点的该进，这个缺点就是违背软件设计原则OCP。但是并不是工厂方法模式就优于简单工厂模式，只不过后者更符合常规的软件设计理念。 
 */


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


/*N85, N81, ...*/
/* N85型号的Nokia手机产品类 */
class CN85 : public CNokia
{
public:
    CN85(void)
    {
        std::cout << "生产一部N85" << std::endl;
    }
public:
    virtual ~CN85(void){}
public:
    virtual bool MakeCall(const std::string & number) const
    {
        std::cout << "我在用N85，拨打号码是：" <<  number.c_str() << std::endl;
        return false;
    }
};

/* N81型号的Nokia手机产品类 */
class CN81 : public CNokia
{
public:
    CN81(void)
    {
        std::cout << "生产一部N81" << std::endl;
    }
public:
    virtual ~CN81(void){}
public:
    virtual bool MakeCall(const std::string & number) const
    {
        std::cout << "我在用N81，拨打号码是：" <<  number.c_str() << std::endl;
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
    virtual CNokia * CreateNokiaMobile(void) = 0;
};


/* 生产N99的具体工厂类 */
class CN96Factory : public CFactoryMethod
{
public:
    CN96Factory(void){}
public:
    virtual ~CN96Factory(void){}
public:
    virtual CNokia * CreateNokiaMobile(void)
    {
        return new CN96();
    }
};

/* 客户端通过建立N99工厂生产Nokia手机 */
int _tmain(int argc, _TCHAR* argv[])
{
    CFactoryMethod * factoryMethod = new CN96Factory();
    CNokia * nokia = factoryMethod->CreateNokiaMobile();
    nokia->MakeCall("1234567");
    return 0;
}