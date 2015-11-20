// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}


/*
** FileName     : SingletonPatternDemo4
** Author       : Jelly Young
** Date         : 2013/11/20
** Description  : More information, please go to http://www.jellythink.com
*/

#include <iostream>
using namespace std;

//template<typename _Ty> 
//class Singleton
//{
//public:
//    //Singleton()
//    //{
//
//    //}
//
//    //~Singleton()
//    //{
//
//    //}
//
//public:
//    static _Ty *GetInstance()
//    {
//        static _Ty m_Instance;
//        return &m_Instance;
//    }
//
//public:
//    Singleton(){};
//    Singleton(Singleton const&);  
//    Singleton& operator = (Singleton const&);  
//};


template<typename _Ty> 
class Singleton
{
public:
    Singleton()
    {
        if (!MakeInstance())
        {
            //处理创建失败……………………未添加
        }
    }

    ~Singleton()
    {
        DestoryInstance();
    }

public:
    _Ty *GetInstance()
    {
        if (m_pInstance)
        {
            return m_pInstance;
        }

        return NULL;
    }

private:
    bool MakeInstance()
    {
        m_pInstance = NULL;
        m_pInstance = new _Ty;
        if (NULL == m_pInstance)
        {
            return false;
        }

        return true;
    }

    void DestoryInstance()
    {
        if (NULL != m_pInstance)
        {
            delete m_pInstance;
            m_pInstance = NULL ;
        }
    }
public:
    Singleton(Singleton const&);  
    Singleton& operator = (Singleton const&);

private:
    _Ty* m_pInstance;
};

class Example  
{   
public:
    Example(){};
    ~Example(){};

public:
    void Show()
    {
        printf("Templete Singleton Example\r\n");
        printf("test \r\n\a\tmmmmmm!");
    }

};  

int main1(int argc , char *argv [])
{
    //Singleton *singletonObj = Singleton ::GetInstance();
    //cout<<singletonObj->GetTest()<<endl;

    //singletonObj = Singleton ::GetInstance();
    //cout<<singletonObj->GetTest()<<endl;
    
    Singleton<Example> SglExample;  

    Example* pTemp = SglExample.GetInstance();

    pTemp->Show();

    return 0;
}