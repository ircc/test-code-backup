// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//
//class MyType{ // 自定义类型
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
//class A<int, MyType>{ //绝对类型特化，两个模板类型被特化为一个普通类型和一个自定义的数据类型
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


// 前端的包头,包含cid
typedef struct BIN_HDR
{
    uint32_t len;
    uint32_t cmd;
    uint32_t seq;
    uint64_t cid;
    uint64_t uid;
}BHDR;


// 通用的包头
typedef struct CO_BIN_HDR
{
    uint32_t len;          // 整个包的长度
    uint32_t cmd;          // 协议号
    uint32_t seq;          // 请求的序列号
    uint32_t head_len;     // 包头长度=sizeof(head_len)+sizeof(sender_coid)sizeof(receiver_coid)sizeof(server_id)
    uint32_t sender_coid;  // 发送方的coid
    uint32_t receiver_coid;// 接收方的coid
    uint32_t server_id;    // 前端的服务id
}COBHDR;

template <typename _Ty>
class MyType
{ // 自定义类型

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
{ //绝对类型特化，两个模板类型被特化为一个普通类型和一个自定义的数据类型
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