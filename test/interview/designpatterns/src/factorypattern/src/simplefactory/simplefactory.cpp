// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
using namespace std;


//�򵥹���,���������ͳ��󹤳������� ���������Ϻܶ�������ģʽ�ķ���,�е�ģʽ����������,�����ʻ�������ܴ��.��򵥹���,���������ͳ��󹤳����к����Ե�����. 
//��һ���ȽϺ����������,�������ҽ�����: 
//1.���һ����԰ֻ���߲���,��ô���ü򵥹����Ϳ�����. 
//2.�����԰�߲�Ʒ�ַ���.���ù��������ſ���,�ѹ��еĶ����������. 
//3.���Ҫ�����԰�Ĺ�ģ,����һ���ڱ���,һ�����Ϸ�,���������������޷�ʵ����,��Ӧ���ó��󹤳�,�Ѹ��ָ�����ֲ��,�����һ����԰. 
//�����Ҹ�����Ϊ,�򵥹�����һ������ֻ����һ��Ĳ�Ʒ,��Ե��Ǿ������,���������ǿ���������ͬ�Ĳ�Ʒ,�ѹ����ķ����������,Ȼ����д������ָ����Ĳ�Ʒ.���󹤳��Ѽ��ֲ�Ʒ������ͬ�Ķ���,���໥�����Ķ���������,ֻҪʵ����Щ�ӿھͿ��Եõ���ͬ�Ĳ�Ʒ. 
//��������: 


//1.�򵥹���: 
// �򵥹���ģʽ�Ĺ�����һ����ʹ�þ�̬������ͨ�����յĲ����Ĳ�ͬ�����ز�ͬ�Ķ���ʵ����
// ���޸Ĵ���Ļ������޷���չ�ġ�
// 
//�ĵ�:�ŵ���ֻҪʵ�ֹ��еĽӿھͿ���ʵ�ֲ�ͬ���ܵķ�ʽ.��ȱ�����Ҫ�ж���һ�ֳ�,���Ҫ�޸�Driver ��

class ICar
{
public:
    //virtual void run()=0;

    virtual void run()
    {
        printf("ICar run!\r\n");
    }
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


#define CAR_TYPE_BMW 1
#define CAR_TYPE_BENZ 2
class Driver
{
public:
    static ICar* DriverCar(int iInCarType)
    {
        switch(iInCarType)
        {
        case CAR_TYPE_BMW: return new BMWCar(); 
        case CAR_TYPE_BENZ: return new BenzCar(); 
        default:return NULL;
        }
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    ICar* pMyCar = Driver::DriverCar(CAR_TYPE_BENZ); 
    pMyCar->run();

    delete pMyCar;
    pMyCar = NULL;

    /*************************************************
     ���run������ʹ��virtual�ؼ��� ��myCar���õ�ʼ���Ǹ����run������
     ʹ���˵Ļ������run���������ǣ����õ��������run����

     C++�е��麯����������Ҫ��ʵ���˶�̬�Ļ��ơ����ڶ�̬�������֮�����ø����ͱ��ָ��ָ���������ʵ����Ȼ��ͨ�������ָ�����ʵ������ĳ�Ա������
     ���ּ��������ø����ָ���С�������̬��������һ�ַ��ͼ�������ν���ͼ�����˵���˾�����ͼʹ�ò���Ĵ�����ʵ�ֿɱ���㷨��
     ���磺ģ�弼����RTTI�������麯��������Ҫô����ͼ�����ڱ���ʱ���飬Ҫô��ͼ��������ʱ���顣

     C++֧�ֱ���ʱ��̬������ʱ��̬����������غͺ������ؾ��Ǳ���ʱ��̬������������麯��ʵ������ʱ��̬
     ����ʱ��̬�Ļ����ǻ���ָ�룬����ָ�����ָ���κ����������
     *************************************************/
    getchar();
	return 0;
}
