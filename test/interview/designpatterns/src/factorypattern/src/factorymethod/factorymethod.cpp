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


//2.��������: 
// �������������ÿһ�ֲ�Ʒ�ṩһ�������ࡣͨ����ͬ�Ĺ���ʵ����������ͬ�Ĳ�Ʒʵ����
// ��ͬһ�ȼ��ṹ�У�֧�����������Ʒ��

//�ĵ�:�ŵ��Ƿ����˿���-���ԭ��(OCP),�������ϻ�������ʲôȱ��.
//��Ʒ��
class ICar
{
public:
    virtual void run() = 0;

    //virtual void run()
    //{
    //    printf("ICar run!\r\n");
    //}
};


class BMWCar : public ICar
{
public:
    void run()
    {
        printf("BMWCar run!\r\n");
    }
};

class BenzCar : public ICar
{
public:
    void run()
    {
        printf("BenzCar run!\r\n");
    }
};

//������
class Driver 
{ 
public:
    virtual ICar* DriverCar() = 0; 
    //virtual ICar* DriverCar()
    //{
    //    printf("DriverCar\r\n");   
    //    return NULL;
    //}; 
};

class BMWDriver : public Driver 
{ 
public:
    ICar* DriverCar() 
    { 
        return new BMWCar(); 
    } 

};

class BenzDriver : public Driver  
{ 
public:
    ICar* DriverCar() 
    { 
        return new BenzCar(); 
    } 
};

int _tmain1(int argc, _TCHAR* argv[])
{
    Driver* pMyDriver = new BenzDriver(); 
    ICar* pMyCar = pMyDriver->DriverCar(); 
    pMyCar->run(); 

    delete pMyCar;
    pMyCar = NULL;

    getchar();
	return 0;
}

