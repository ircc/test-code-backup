// test.cpp : �������̨Ӧ�ó������ڵ㡣
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
//class Point                                       //���������࣬Ҫ��һ����Point�������ָ��
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
//class RefPtr                                  //������
//{//�����Ա����Ȩ��ȫ��Ϊprivate����Ϊ�������û�ֱ��ʹ�ø���
//    friend class SmartPtr;      //��������ָ����Ϊ��Ԫ����Ϊ����ָ������Ҫֱ�Ӳ��ݸ�����
//    RefPtr(Point *ptr):p(ptr), count(1) { }
//    ~RefPtr() { delete p; }
//
//    int count;                                                     //���ü���
//    Point *p;                                                      //��������ָ��
//};
//
//class SmartPtr                                             //����ָ����
//{
//public:
//    SmartPtr(Point *ptr):rp(new RefPtr(ptr)) { }                                 //���캯��
//    SmartPtr(const SmartPtr &sp):rp(sp.rp) { ++rp->count; }            //���ƹ��캯��
//    SmartPtr& operator=(const SmartPtr& rhs) {                              //���ظ�ֵ������
//        ++rhs.rp->count;                                                         //���Ƚ��Ҳ��������ü�����1��
//        if(--rp->count == 0)                                                                     //Ȼ�����ü�����1������Ӧ���Ը�ֵ
//            delete rp;
//        rp = rhs.rp;
//        return *this;
//    }
//    ~SmartPtr() {                                            //��������
//        if(--rp->count == 0)                                  //�����ü�����Ϊ0ʱ��ɾ�����������ָ�룬�Ӷ�ɾ����������
//            delete rp;
//    }
//
//private:
//    RefPtr *rp;                                                //���������ָ��
//};
//
//int main()
//{
//    Point *p1 = new Point(10, 8);
//    SmartPtr sp1(p1);    //��ʱsp1.rp->count = 1
//    SmartPtr sp2(sp1);    //���Ƚ�sp1.rp->count����sp2.rp->count,֮��sp2.rp->count++,��ʱsp1,sp2��rp��ͬһ������
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
    common::smart_ptr<Int>    spInt(new Int(10));   // ��������

    //spInt.element_type;
    if (spInt.get())                     // �ж�����ָ���Ƿ�Ϊ��
    { 
        spInt->PrintValue();        // ʹ��operator->��������ָ�����ĺ���
        spInt.get()->SetValue(20);    // ʹ��get()������ָ�룬Ȼ��ͨ����ָ����õĳ�Ա����
        spInt->PrintValue();        // �ٴδ�ӡ�������ϲ���ֵ�ɹ�
        (*spInt).SetValue(30);        // ʹ��operator*��������ָ���ڲ�����Ȼ���á�.����������ָ������еĺ���
        spInt->PrintValue();        // �ٴδ�ӡ�������ϲ���ֵ�ɹ�            
    }
    //spIntջ������������ڣ���֮�����Ѷ���Int(10)��ͬʱ�ͷ��ڴ���Դ
}

void main1()
{
    TestAuto_Ptr1();
}

