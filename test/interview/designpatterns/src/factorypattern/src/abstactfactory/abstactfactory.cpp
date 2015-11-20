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


//3.���󹤳�: 

// ���󹤳���Ӧ�Բ�Ʒ�����ġ�����˵��ÿ��������˾����Ҫͬʱ�����γ����������ͳ�����ôÿһ��������Ҫ�д����γ��������Ϳͳ��ķ�����
// Ӧ�Բ�Ʒ���������������µĲ�Ʒ�ߺ����ף������޷������µĲ�Ʒ��
// 
//�ĵ�:���󷽷��ƺ��ﵽ����������.�ѿ����۵�˾���Ϳ���������ͣ�������˶����Ĺ��������������,���Բ�ͬ��˾��������ͬ����,��ʱ�򲻹��ǿ�ʲô���������������.����Ψһ�Ĺ�ͬ�㶼�ǿ���.

// ��ƷIBusinessCar
class IBusinessCar
{
public:
    virtual void run() = 0;

    //virtual void run()
    //{
    //    printf("ICar run!\r\n");
    //}
};

// ��ƷISportCar
class ISportCar
{
public:
    virtual void run() = 0;
    //virtual void run()
    //{
    //    printf("ICar run!\r\n");
    //}
};

class BMWBusinessCar : public IBusinessCar
{
public:
    void run()
    {
        printf("BMWCar run!\r\n");
    }
};

class BenzBusinessCar : public IBusinessCar
{
public:
    void run()
    {
        printf("BenzBusinessCar run!\r\n");
    }
};

class BMWSportCar : public ISportCar
{
public:
    void run()
    {
        printf("BMWSportCar run!\r\n");
    }
};

class BenzSportCar : public ISportCar
{
public:
    void run()
    {
        printf("BenzSportCar run!\r\n");
    }
};

// ����ʵ��
class IDriver
{
public:
    virtual IBusinessCar* BusinessCarDriver() = 0;
    virtual ISportCar* SportCarDriver() = 0;

    //virtual IBusinessCar* BusinessCarDriver(){return NULL;}
    //virtual ISportCar* SportCarDriver(){return NULL;}
};

class BMWDriver : public IDriver
{
public:
    IBusinessCar* BusinessCarDriver()
    {
        return new BMWBusinessCar();
    }

    ISportCar* SportCarDriver()
    {
        return new BMWSportCar();
    }
};

class BenzDriver : public IDriver
{
public:
    IBusinessCar* BusinessCarDriver()
    {
        return new BenzBusinessCar();
    }

    ISportCar* SportCarDriver()
    {
        return new BenzSportCar();
    }
};

int _tmain1(int argc, _TCHAR* argv[])
{
    //Client
    IDriver* pMyDriver = new BenzDriver();
    ISportCar* pMyCar = pMyDriver->SportCarDriver();
    pMyCar->run();

    getchar();
	return 0;
}

