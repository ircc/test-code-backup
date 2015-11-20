// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

/*
http://blog.csdn.net/chollima/article/details/3989145
��������ģʽ�ǶԼ򵥹���ģʽ�ĸĽ������ȿ����򵥹���ģʽ��ȱ�㡣
�����֮���������ڳ�������Ϊ�����Ա�����ʹ�ã����ܼ�Ӵ���Ч�档��������������ĺ��ģ������û���������������û�д��ڵļ�ֵ��

����Nokia���¿�����һ�����ֻ�N99�����ڲ��ü򵥹���ģʽ��Ƶ�ϵͳ�����ǵ������ǣ�
1.����һ��CN99��̳���CNokia�����࣬������Ͽ���ԭ��(OCP)��
ע��OCP:Open-Closed Principle����ԭ��OCP��ע��������ԣ��Ķ���ͨ�����Ӵ�����еģ������ǸĶ����еĴ��롣
        ����չ���ţ����޸Ĺرա�

2.�޸ľ�̬���������е��ж��߼������Ӷ�N99�Ĵ������롣�������Υ��OCP��

�Ľ��򵥹���ģʽ������Ҫ���ľ��ǿ˷�2�е�ȱ�㡣


����Ĺ�������ģʽ������һ��N96�Ĺ����࣬�����޸����еĴ��룬��ȫ֧��OCPԭ�򣬶��ҹ�������ģʽҲ��ȫ���������滻ԭ��LSPԭ����OCP��Ϊ���ܵ���Ҫԭ��
ע��Liskov Substitution Principle�����ϴ���ԭ�򣩣�������(subtype)�����ܹ��滻���ǵĻ����͡�

��Ȼ��������ģʽ�ǶԼ򵥹���ģʽȱ��ĸý������ȱ�����Υ��������ԭ��OCP�����ǲ����ǹ�������ģʽ�����ڼ򵥹���ģʽ��ֻ�������߸����ϳ������������� 
 */


/* Nokia�����Ʒ */
class CNokia
{
public:
    CNokia(void){}
public:
    virtual ~CNokia(void){}
public:
    virtual bool MakeCall(const std::string & number) const = 0;
};

/* N96�ͺŵ�Nokia�ֻ���Ʒ�� */  
class CN96 : public CNokia
{
public:
    CN96(void)
    {
        std::cout << "����һ��N96" << std::endl;
    }

public:
    virtual ~CN96(void){}
public:
    virtual bool MakeCall(const std::string & number) const
    {
        std::cout << "������N96����������ǣ�" <<  number.c_str() << std::endl;
        return false;
    }
};

/* N95�ͺŵ�Nokia�ֻ���Ʒ�� */
class CN95 : public CNokia
{
public:
    CN95(void)
    {
        std::cout << "����һ��N95" << std::endl;
    }
public:
    virtual ~CN95(void){}
public:
    virtual bool MakeCall(const std::string & number) const
    {
        std::cout << "������N95����������ǣ�" <<  number.c_str() << std::endl;
        return false;
    }
};


/*N85, N81, ...*/
/* N85�ͺŵ�Nokia�ֻ���Ʒ�� */
class CN85 : public CNokia
{
public:
    CN85(void)
    {
        std::cout << "����һ��N85" << std::endl;
    }
public:
    virtual ~CN85(void){}
public:
    virtual bool MakeCall(const std::string & number) const
    {
        std::cout << "������N85����������ǣ�" <<  number.c_str() << std::endl;
        return false;
    }
};

/* N81�ͺŵ�Nokia�ֻ���Ʒ�� */
class CN81 : public CNokia
{
public:
    CN81(void)
    {
        std::cout << "����һ��N81" << std::endl;
    }
public:
    virtual ~CN81(void){}
public:
    virtual bool MakeCall(const std::string & number) const
    {
        std::cout << "������N81����������ǣ�" <<  number.c_str() << std::endl;
        return false;
    }
};




/* ���󹤳��� */
class CFactoryMethod
{
public:
    CFactoryMethod(void){}
public:
    virtual ~CFactoryMethod(void){}
public:
    virtual CNokia * CreateNokiaMobile(void) = 0;
};


/* ����N99�ľ��幤���� */
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

/* �ͻ���ͨ������N99��������Nokia�ֻ� */
int _tmain(int argc, _TCHAR* argv[])
{
    CFactoryMethod * factoryMethod = new CN96Factory();
    CNokia * nokia = factoryMethod->CreateNokiaMobile();
    nokia->MakeCall("1234567");
    return 0;
}