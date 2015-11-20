// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

/*
 http://blog.csdn.net/chollima/article/details/3985570
һ.�򵥹���ģʽ�ֳƾ�̬��������ģʽ��Static Factory Method����������Gof ������23�����ģʽ֮һ��������ȴ�������ڱ�������о���ʹ�õķ���֮һ��

1.��̬��������ͳһ�������Ĵ�����
��̬��������ͨ������Ĳ����жϾ���������һ����Ʒ��ʵ������װ�˶���Ĵ������ͻ���ֻ�����ѣ�ʵ���˶����Σ�ģ�飩�ķָ

2.��̬���������Ƴ��˲�Ʒ��ʵ������
ͨ��XML�����ļ����ܸı����Ҫ�����Ĳ�Ʒʵ�����޸�Ϊ�����Ĳ�Ʒʵ�������벻�����±��롣


��.�򵥹���ģʽ������ȱ��ģ�����Ĺ�������ģʽ�ͳ��󹤳�ģʽ���Ƕ���Щȱ��ĸ��ơ�������������ģʽ������һ���Աȡ�������Nokia�ֻ�Ϊ�������ü򵥹���ģʽ��Ƶ�Դ������Ρ�
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


/* ������ */

#include <cassert>
class CNokiaSimpleFactory
{
public:
    CNokiaSimpleFactory(void){}
public:
    ~CNokiaSimpleFactory(void){}
public:
         /* ��̬�������� */
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


/* main���������Կ����ͻ��� */
int _tmain2(int argc, _TCHAR* argv[])
{
	CNokia * nokia = NULL;
        /* 
          modeName ���Դ��ⲿXML�ļ��ж�ȡ�����й����ж�̬��
            �����ô�����һ���ͺŵ��ֻ�
         */
	std::string modeName = "N96";
	nokia = CNokiaSimpleFactory::CreateNokia(modeName);
	nokia->MakeCall("123456789");
    
    delete nokia;
	nokia = NULL;
	return 0;
}


