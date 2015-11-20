// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "singleton.h"
#include "ref_counted.h"
using namespace COMMON;
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

Singleton<ref_counted> g_clsRCSingleton;

int _tmain(int argc, _TCHAR* argv[])
{
    Singleton<Example> clsSingletonExample;

    Example* pclsExample = clsSingletonExample.getInstance();

    ref_counted* pclsCounted = g_clsRCSingleton.getInstance();
    pclsCounted->addref();
    pclsExample->Show();
    pclsCounted->release();

    //Ҳ��������ʹ��
    g_clsRCSingleton.getInstance()->addref();
    g_clsRCSingleton.getInstance()->release();

	return 0;
}

