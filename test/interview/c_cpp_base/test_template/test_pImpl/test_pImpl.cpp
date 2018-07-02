// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//
//class MyType{ // �Զ�������
//public:
//    char ch;
//    MyType(char _ch):ch(_ch){}
//};
//
//template<class T1, class T2>
//class A{
//public:
//    void function(T1 value1, T2 value2){
//        cout<<"value1 = "<<value1<<endl;
//        cout<<"value2 = "<<value2<<endl;
//    }
//};
//
//template<>
//class A<int, MyType>{ //���������ػ�������ģ�����ͱ��ػ�Ϊһ����ͨ���ͺ�һ���Զ������������
//public:
//    void function(int value1, MyType value2){
//        cout<<"int value1 = "<<value1<<endl;
//        cout<<"double value2 = "<<value2.ch<<endl;
//    }
//};
//
//int _tmain(int argc, _TCHAR* argv[])
//{     
//    MyType mytype(65);
//    A<int, MyType> mychild1;
//    mychild1.function(1, mytype);
//    return 0;
//}


// ǰ�˵İ�ͷ,����cid
typedef struct BIN_HDR
{
    uint32_t len;
    uint32_t cmd;
    uint32_t seq;
    uint64_t cid;
    uint64_t uid;
}BHDR;


// ͨ�õİ�ͷ
typedef struct CO_BIN_HDR
{
    uint32_t len;          // �������ĳ���
    uint32_t cmd;          // Э���
    uint32_t seq;          // ��������к�
    uint32_t head_len;     // ��ͷ����=sizeof(head_len)+sizeof(sender_coid)sizeof(receiver_coid)sizeof(server_id)
    uint32_t sender_coid;  // ���ͷ���coid
    uint32_t receiver_coid;// ���շ���coid
    uint32_t server_id;    // ǰ�˵ķ���id
}COBHDR;

template <typename _Ty>
class MyType
{ // �Զ�������

public:
    void show()
    {
        printf("Hello MyType:%d!!!", head.len);
    }
    _Ty head;
};

template <typename _Ty>
class MyChild : public MyType<BHDR>
{

public:
    void show()
    {
        printf("Hello MyChild!!!");
    }

    void showChild()
    {
        printf("Hello child MyChild!!!");
    }
};

template<class T1>
class A
{
public:
    void function()
    {
    }

};

template<>
class A<MyType>
{ //���������ػ�������ģ�����ͱ��ػ�Ϊһ����ͨ���ͺ�һ���Զ������������
public:
    void function()
    {
        //cout<<"double value2 = "<<value2.ch<<endl;
        T_.show();
    }

private:
   MyType T_;
};

int _tmain(int argc, _TCHAR* argv[])
{     
    A<MyChild> mychild1;
    mychild1.function();
	return 0;
}