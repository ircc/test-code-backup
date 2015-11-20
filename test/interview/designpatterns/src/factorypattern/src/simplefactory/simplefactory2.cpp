// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

/*
 http://blog.csdn.net/chollima/article/details/3985570
一.简单工厂模式又称静态工厂方法模式（Static Factory Method），它不是Gof 所讲的23种设计模式之一，但是它却是我们在编码过程中经常使用的方法之一。

1.静态工厂方法统一管理对象的创建。
静态工厂方法通过传入的参数判断决定创建哪一个产品的实例，封装了对象的创建，客户端只管消费，实现了对责任（模块）的分割。

2.静态工厂方法推迟了产品的实例化。
通过XML配置文件就能改变具体要创建的产品实例，修改为其它的产品实例，代码不须重新编译。


二.简单工厂模式还是有缺点的，后面的工厂方法模式和抽象工厂模式就是对这些缺点的改善。讲完了这三种模式将会有一个对比。以下以Nokia手机为例，采用简单工厂模式设计的源代码雏形。
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


/* 工厂类 */

#include <cassert>
class CNokiaSimpleFactory
{
public:
    CNokiaSimpleFactory(void){}
public:
    ~CNokiaSimpleFactory(void){}
public:
         /* 静态工厂方法 */
	static CNokia * CreateNokia(const std::string & model)
    {
        if (model == "N96")
        {
            return new CN96();
        }
        else if (model == "N95")
        {
            return new CN95();
        }
        else if (model == "N85")
        {
            return new CN85();
        }
        else if (model == "N81")
        {
            return new CN81();
        }
        else
        {
            assert(false);
        }
        return NULL;
    }
};


/* main方法，可以看做客户端 */
int _tmain2(int argc, _TCHAR* argv[])
{
	CNokia * nokia = NULL;
        /* 
          modeName 可以从外部XML文件中读取，运行过程中动态的
            决定该创建哪一种型号的手机
         */
	std::string modeName = "N96";
	nokia = CNokiaSimpleFactory::CreateNokia(modeName);
	nokia->MakeCall("123456789");
    
    delete nokia;
	nokia = NULL;
	return 0;
}


