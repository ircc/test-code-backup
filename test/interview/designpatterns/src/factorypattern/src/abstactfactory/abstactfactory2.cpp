// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//�򵥹���,���������ͳ��󹤳������� ���������Ϻܶ�������ģʽ�ķ���,�е�ģʽ����������,�����ʻ�������ܴ��.��򵥹���,���������ͳ��󹤳����к����Ե�����. 
//��һ���ȽϺ���������,�������ҽ�����: 
//1.���һ����԰ֻ���߲���,��ô���ü򵥹����Ϳ�����. 
//2.�����԰�߲�Ʒ�ַ���.���ù��������ſ���,�ѹ��еĶ����������. 
//3.���Ҫ�����԰�Ĺ�ģ,����һ���ڱ���,һ�����Ϸ�,���������������޷�ʵ����,��Ӧ���ó��󹤳�,�Ѹ��ָ�����ֲ��,�����һ����԰. 
//�����Ҹ�����Ϊ,�򵥹�����һ������ֻ����һ��Ĳ�Ʒ,��Ե��Ǿ������,���������ǿ���������ͬ�Ĳ�Ʒ,�ѹ����ķ����������,Ȼ����д������ָ����Ĳ�Ʒ.���󹤳��Ѽ��ֲ�Ʒ������ͬ�Ķ���,���໥�����Ķ���������,ֻҪʵ����Щ�ӿھͿ��Եõ���ͬ�Ĳ�Ʒ. 
//��������: 

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

/*
���󹤳�ģʽ�빤������ģʽ������

���󹤳�ģʽ�ǹ�������ģʽ�������汾������������һ����ػ����໥�����Ķ���
���빤������ģʽ����������ڣ���������ģʽ��Ե���һ����Ʒ�ȼ��ṹ�������󹤳�ģʽ������ԵĶ����Ʒ�ȼ��ṹ��
�ڱ���У�ͨ��һ����Ʒ�ṹ������Ϊһ���ӿڻ��߳����࣬Ҳ����˵����������ģʽ�ṩ�����в�Ʒ����������ͬһ���ӿڻ�����࣬�����󹤳�ģʽ���ṩ�Ĳ�Ʒ���������Բ�ͬ�Ľӿڻ�����ࡣ

�ڳ��󹤳�ģʽ�У���һ����Ʒ��ĸ����ν�Ĳ�Ʒ�壬��ָλ�ڲ�ͬ��Ʒ�ȼ��ṹ�й���������Ĳ�Ʒ��ɵļ��塣
���󹤳�ģʽ���ṩ��һϵ�в�Ʒ�����һ����Ʒ�壻�����������ṩ��һϵ�в�Ʒ��Ϊһ���ȼ��ṹ��

��֮ǰ�ļ򵥹����͹���ģʽ���ֻ���������˵������֮�������

����Nokia��N95�ֻ���ƻ����iphone5�ֻ���ͬһ����Ʒ��N96��iphone6Ҳ��ͬһ����Ʒ��ͬһʱ��ֻ��ͬһ����Ʒ��
��һ������ֻ����һ��Ʒ�Ƶ��ֻ���Ȼ�ǲ������ ����ͬһ����Ʒ������صĶ��������ͬһ����������
��һ����Ʒ������  ����Ҫ�����ϲ�Ʒ�ļ�������  ������һ�������������Ҫ���



���󹤳�ģʽ���ŵ�
���󹤳�ģʽ���˾��й�������ģʽ���ŵ��⣬����Ҫ���ŵ���ǿ���������ڲ��Բ�Ʒ�����Լ����
��ν�Ĳ�Ʒ�壬һ������ٵĶ�����һ���Ĺ��������󹤳�ģʽ�Ϳ��������ڲ��Բ�Ʒ��Ĺ�����ϵ���ж����������������ר������һ���µ��������й���

���󹤳�ģʽ��ȱ��
��Ʒ�����չ����һ��ʮ�ַ��������飬�����Ʒ������Ҫ����һ���µĲ�Ʒ���򼸺����еĹ����඼��Ҫ�����޸ġ�����ʹ�ó��󹤳�ģʽʱ���Բ�Ʒ�ȼ��ṹ�Ļ����Ƿǳ���Ҫ�ġ�

���ó���
����Ҫ�����Ķ�����һϵ���໥�������໥�����Ĳ�Ʒ��ʱ�������ʹ�ó��󹤳�ģʽ��
˵�ĸ�����һ�㣬����һ���̳���ϵ�У���������Ŷ���ȼ��ṹ���������Ŷ�������ࣩ�����ҷ��������ȼ��ṹ�е�ʵ����֮�������һ���Ĺ�������Լ�����Ϳ���ʹ�ó��󹤳�ģʽ��
��������ȼ��ṹ�е�ʵ����֮�䲻���ڹ�����Լ������ʹ�ö�������Ĺ������Բ�Ʒ���д������������һ�㡣

�ܽ�
�����Ǽ򵥹���ģʽ����������ģʽ�����ǳ��󹤳�ģʽ�����Ƕ����ڹ���ģʽ������ʽ���ص���Ҳ�Ǽ�Ϊ���Ƶģ����ǵ�����Ŀ�Ķ���Ϊ�˽��
��ʹ��ʱ�����ǲ���ȥ�������ģʽ���׹�������ģʽ���ǳ��󹤳�ģʽ����Ϊ����֮����ݱ䳣����������ĥ��͸�ġ�
������ᷢ�֣�����ʹ�õĹ�������ģʽ�������������٣��Լ��޸ģ�������һ���·������������еĲ�Ʒ�����˲�ͬ�ȼ��ṹ�еĲ�Ʒ�壬���ͱ�ɳ��󹤳�ģʽ�ˣ�
�����ڳ��󹤳�ģʽ��������һ������ʹ���ṩ�Ĳ�Ʒ���ٹ��ɲ�Ʒ��֮�������ݱ���˹�������ģʽ��

���ԣ���ʹ�ù���ģʽʱ��ֻ��Ҫ���Ľ�����϶ȵ�Ŀ���Ƿ�ﵽ�ˡ�
*/

//���󹤳�


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

/* Iphone�����Ʒ */
class CIphone
{
public:
    CIphone(void){}
public:
    virtual ~CIphone(void){}
public:
    virtual bool MakeCall(const std::string & number) const = 0;
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


/*Iphone5, Iphone6, ...*/
/* Iphone5�ͺŵ�Iphone�ֻ���Ʒ�� */
class CIphone5 : public CIphone
{
public:
    CIphone5(void)
    {
        std::cout << "����һ��Iphone5" << std::endl;
    }
public:
    virtual ~CIphone5(void){}
public:
    virtual bool MakeCall(const std::string & number) const
    {
        std::cout << "������Iphone5����������ǣ�" <<  number.c_str() << std::endl;
        return false;
    }
};

/* Iphone6�ͺŵ�Iphone�ֻ���Ʒ�� */
class CIphone6 : public CIphone
{
public:
    CIphone6(void)
    {
        std::cout << "����һ��Iphone6" << std::endl;
    }
public:
    virtual ~CIphone6(void){}
public:
    virtual bool MakeCall(const std::string & number) const
    {
        std::cout << "������Iphone6����������ǣ�" <<  number.c_str() << std::endl;
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
    virtual CNokia* CreateNokiaMobile(void) = 0;
    virtual CIphone* CreateIphoneMobile(void) = 0;
};


/* ����Nokia��iphone 5���ľ��幤���� */
class CIN5Factory : public CFactoryMethod
{
public:
    CIN5Factory(void){}
public:
    virtual ~CIN5Factory(void){}
public:
    virtual CNokia* CreateNokiaMobile(void)
    {
        return new CN95();
    }

    virtual CIphone* CreateIphoneMobile(void)
    {
        return new CIphone5();
    }
};

/* ����Nokia��iphone 6���ľ��幤���� */
class CIN6Factory : public CFactoryMethod
{
public:
    CIN6Factory(void){}
public:
    virtual ~CIN6Factory(void){}
public:
    virtual CNokia* CreateNokiaMobile(void)
    {
        return new CN96();
    }

    virtual CIphone* CreateIphoneMobile(void)
    {
        return new CIphone6();
    }
};

/* �ͻ���ͨ������N99��������Nokia�ֻ� */
int _tmain(int argc, _TCHAR* argv[])
{
    //5������ ����һ��n95��ŵ����
    CFactoryMethod* pclsFactoryMethod = new CIN5Factory();
    CNokia * pclsNokia = pclsFactoryMethod->CreateNokiaMobile();
    pclsNokia->MakeCall("1234567");

    delete pclsNokia;
    pclsNokia = NULL;
    delete pclsFactoryMethod;
    pclsFactoryMethod = NULL;

    //6������ ������һ��iphone6
    CFactoryMethod* pclsFactoryMethod2 = new CIN6Factory();
    CIphone * pclsIphone = pclsFactoryMethod2->CreateIphoneMobile();
    pclsIphone->MakeCall("7654321");

    delete pclsIphone;
    pclsIphone = NULL;
    delete pclsFactoryMethod2;
    pclsFactoryMethod2 = NULL;


    return 0;
}