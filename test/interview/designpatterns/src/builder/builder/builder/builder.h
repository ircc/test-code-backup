#ifndef _BUILDER_H_
#define _BUILDER_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;


/*
 *http://www.cnblogs.com/jiese/p/3161076.html
C++设计模式-Builder建造者模式

作用:
将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。
Builder模式和AbstractFactory模式在功能上很相似，因为都是用来创建大的复杂的对象，
它们的区别是：Builder模式强调的是一步步创建对象，并通过相同的创建过程可以获得不同的结果对象，一般来说Builder模式中对象不是直接返回的。
而在AbstractFactory模式中对象是直接返回的，AbstractFactory模式强调的是为创建多个相互依赖的对象提供一个同一的接口。

适用于以下情况:
1)当创建复杂对象的算法应该独立于该对象的组成部分以及它们的装配方式时。
2)当构造过程必须允许被构造的对象有不同的表示时。


Builder：定义创建对象过程的抽象，提供构建不同组成部分的接口

其中：BuildPartA,BuildPartB,BuildPartC是对一个对象不同部分的构建函数接口,由Builder的派生类ConcreteBuilder1、ConcreteBuilder2来具体实现.
另外还有一个需要注意的函数,就是Director::Construct函数,这个函数里面通过调用上面的接口函数完成对象的构建
    --也就是说各个不同部分装配的过程都是一致的(同样的调用的Construct函数),但是不同的构建方式会有不同的表示(根据Builder的实际类型来决定如何构建,也就是多态)

Builder模式是基于这样的一个情况:一个对象可能有不同的组成部分,这几个部分的不同的创建对象会有不同的表示,但是各个部分之间装配的方式是一致的.
比方说一辆单车,都是由车轮车座等等的构成的(一个对象不同的组成部分),不同的品牌生产出来的也不一样(不同的构建方式).虽然不同的品牌构建出来的单车不同,但是构建的过程还是一样的

也就是说,Director::Construct函数中固定了各个组成部分的装配方式,而具体是装配怎样的组成部分由Builder的派生类实现.

实现:
Builder模式的实现基于以下几个面向对象的设计原则:

1)把变化的部分提取出来形成一个基类和对应的接口函数,在这里不会变化的是都会创建PartA和PartB,变化的则是不同的创建方法,于是就抽取出这里的Builder基类和BuildPartA,BuildPartB接口函数
2)采用聚合的方式聚合了会发生变化的基类,就是这里Director聚合了Builder类的指针.

以上，通过两个派生类ConcreteBuilder1、ConcreteBuilder2定义了两种不同的建造细节（建造步骤是一样的，由Construct函数确定），
通过两个派生类所建造出来的对象，对外部所展现出来的属性或者功能是不一样的，由各自Builder派生类中的建造方法（BuildPartA、BuildPartB、BuildPartC）决定。


建造者模式和工厂模式非常相似呀，但是记住一点你就可以游刃有余的使用了：
建造者模式最主要功能是基本方法的调用顺序安排，也就是这些基本方法已经实现了；
而工厂方法则重点是创建，你要什么对象我创造一个对象出来，组装顺序则不是他关心的。
建造者模式使用的场景，一是产品类非常的复杂，或者产品类中的调用顺序不同产生了不同的效能，这个时候使用建造者模式是非常合适
*/


//产品类
class Product
{
public:
    Product(){};
    ~Product(){};

public:
    void setPartA(const string& s)
    {
        this->m_partA = s;
    }

    void setPartB(const string& s)
    {
        this->m_partB = s;
    }

    void setPartC(const string& s)
    {
        this->m_partC = s;
    }

private:
    string m_partA;
    string m_partB;
    string m_partC;
};

//抽象Builder基类，定义不同部分的创建接口
class Builder
{
public:
    Builder(){}
    virtual ~Builder(){}

public:
    virtual void BuildPartA()=0;
    virtual void BuildPartB()=0;
    virtual void BuildPartC()=0;
    virtual Product* GetProduct()=0;
};

//  Builder的派生类,实现BuilderPartA和BuilderPartB和BuildPartC接口函数 
class ConcreteBuilder1:public Builder
{
public:
    ConcreteBuilder1()
    {
        this->m_pProduct = new Product();
        cout<<"Create empty product!"<<endl;
    }

    ~ConcreteBuilder1()
    {
        delete this->m_pProduct;
        this->m_pProduct = NULL;
    }

public:
    virtual void BuildPartA()
    {
        this->m_pProduct->setPartA("A");
        cout<<"BuildPartA"<<endl;
    }

    virtual void BuildPartB()
    {
        this->m_pProduct->setPartB("B");
        cout<<"BuildPartB"<<endl;
    }

    virtual void BuildPartC()
    {
        this->m_pProduct->setPartC("C");
        cout<<"BuildPartC"<<endl;
    }

    virtual Product* GetProduct()
    {
        return this->m_pProduct;
    }

private:
    Product* m_pProduct;
};

//  Builder的派生类,实现BuilderPartA和BuilderPartB和BuildPartC接口函数 
class ConcreteBuilder2:public Builder
{
public:
    ConcreteBuilder2()
    {
        this->m_pProduct = new Product();
        cout<<"Create empty product!"<<endl;
    }

    ~ConcreteBuilder2()
    {
        delete this->m_pProduct;
        this->m_pProduct = NULL;
    }

public:
    virtual void BuildPartA()
    {
        this->m_pProduct->setPartA("A");
        cout<<"BuildPartA"<<endl;
    }

    virtual void BuildPartB()
    {
        this->m_pProduct->setPartB("B");
        cout<<"BuildPartB"<<endl;
    }

    virtual void BuildPartC()
    {
        this->m_pProduct->setPartC("C");
        cout<<"BuildPartC"<<endl;
    }

    virtual Product* GetProduct()
    {
        return this->m_pProduct;
    }

private:
    Product* m_pProduct;
};

//ConcreteBuilder1与ConcreteBuilder2是Builder的两个派生类，用于实现两种不同的建造细节

// 使用Builder构建产品,构建产品的过程都一致,但是不同的builder有不同的实现
// 这个不同的实现通过不同的Builder派生类来实现,存有一个Builder的指针,通过这个来实现多态调用 
class Director
{
public:
    Director(Builder* pBuilder)
    {
        this->m_pBuilder = pBuilder;
    }

    ~Director()
    {
        delete this->m_pBuilder;
        this->m_pBuilder = NULL;
    }

public:
    //Construct函数定义一个对象的整个构建过程,不同的部分之间的装配方式都是一致的,
    //首先构建PartA其次是PartB,只是根据不同的构建者会有不同的表示 
    void Construct()
    {
        this->m_pBuilder->BuildPartA();
        this->m_pBuilder->BuildPartB();
        this->m_pBuilder->BuildPartC();
    }
    //void Construct(const string& buildPara);
private:
    Builder* m_pBuilder;
};

#endif