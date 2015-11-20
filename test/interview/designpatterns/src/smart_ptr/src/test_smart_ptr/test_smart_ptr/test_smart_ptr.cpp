// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//
//
////int _tmain(int argc, _TCHAR* argv[])
////{
////	return 0;
////}
//
//
//class Point                                       //基础对象类，要做一个对Point类的智能指针
//{
//public:
//    Point(int xVal = 0, int yVal = 0):x(xVal),y(yVal) { }
//    int getX() const { return x; }
//    int getY() const { return y; }
//    void setX(int xVal) { x = xVal; }
//    void setY(int yVal) { y = yVal; }
//private:
//    int x,y;
//};
//class RefPtr                                  //辅助类
//{//该类成员访问权限全部为private，因为不想让用户直接使用该类
//    friend class SmartPtr;      //定义智能指针类为友元，因为智能指针类需要直接操纵辅助类
//    RefPtr(Point *ptr):p(ptr), count(1) { }
//    ~RefPtr() { delete p; }
//
//    int count;                                                     //引用计数
//    Point *p;                                                      //基础对象指针
//};
//
//class SmartPtr                                             //智能指针类
//{
//public:
//    SmartPtr(Point *ptr):rp(new RefPtr(ptr)) { }                                 //构造函数
//    SmartPtr(const SmartPtr &sp):rp(sp.rp) { ++rp->count; }            //复制构造函数
//    SmartPtr& operator=(const SmartPtr& rhs) {                              //重载赋值操作符
//        ++rhs.rp->count;                                                         //首先将右操作数引用计数加1，
//        if(--rp->count == 0)                                                                     //然后将引用计数减1，可以应对自赋值
//            delete rp;
//        rp = rhs.rp;
//        return *this;
//    }
//    ~SmartPtr() {                                            //析构函数
//        if(--rp->count == 0)                                  //当引用计数减为0时，删除辅助类对象指针，从而删除基础对象
//            delete rp;
//    }
//
//private:
//    RefPtr *rp;                                                //辅助类对象指针
//};
//
//int main()
//{
//    Point *p1 = new Point(10, 8);
//    SmartPtr sp1(p1);    //此时sp1.rp->count = 1
//    SmartPtr sp2(sp1);    //首先将sp1.rp->count赋给sp2.rp->count,之后sp2.rp->count++,这时sp1,sp2的rp是同一个对象
//    Point *p2 = new Point(5, 5);
//    SmartPtr sp3(p2);
//    sp3 = sp1;
//
//    return 0;
//}


#include<iostream>
//#include<memory>
#include "smart_ptr.h"
using namespace std;

class Int
{
public:
    Int(int nValue = 0) 
    {
        m_nValue = nValue;
        std::cout << "Constructor: " << m_nValue << std::endl; 
    }
    ~Int() 
    {
        std::cout << "Destructor: " << m_nValue << std::endl;
    }
    void PrintValue()
    {
        std::cout << "PrintValue: " <<m_nValue<< std::endl;
    }
    void SetValue(int nSetValue)
    {
        m_nValue = nSetValue;
    }

private:
    int m_nValue;
};

void TestAuto_Ptr1() 
{
    common::smart_ptr<Int>    spInt(new Int(10));   // 创建对象

    //spInt.element_type;
    if (spInt.get())                     // 判断智能指针是否为空
    { 
        spInt->PrintValue();        // 使用operator->调用智能指针对象的函数
        spInt.get()->SetValue(20);    // 使用get()返回裸指针，然后通过裸指针调用的成员函数
        spInt->PrintValue();        // 再次打印，检验上步赋值成功
        (*spInt).SetValue(30);        // 使用operator*返回智能指针内部对象，然后用“.”调用智能指针对象中的函数
        spInt->PrintValue();        // 再次打印，表明上步赋值成功            
    }
    //spInt栈对象结束生命期，随之析构堆对象Int(10)，同时释放内存资源
}

void main1()
{
    TestAuto_Ptr1();
}

