#ifndef _BUILDER_H_
#define _BUILDER_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;


/*
 *http://www.cnblogs.com/jiese/p/3161076.html
C++���ģʽ-Builder������ģʽ

����:
��һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��
Builderģʽ��AbstractFactoryģʽ�ڹ����Ϻ����ƣ���Ϊ��������������ĸ��ӵĶ���
���ǵ������ǣ�Builderģʽǿ������һ�����������󣬲�ͨ����ͬ�Ĵ������̿��Ի�ò�ͬ�Ľ������һ����˵Builderģʽ�ж�����ֱ�ӷ��صġ�
����AbstractFactoryģʽ�ж�����ֱ�ӷ��صģ�AbstractFactoryģʽǿ������Ϊ��������໥�����Ķ����ṩһ��ͬһ�Ľӿڡ�

�������������:
1)���������Ӷ�����㷨Ӧ�ö����ڸö������ɲ����Լ����ǵ�װ�䷽ʽʱ��
2)��������̱�����������Ķ����в�ͬ�ı�ʾʱ��


Builder�����崴��������̵ĳ����ṩ������ͬ��ɲ��ֵĽӿ�

���У�BuildPartA,BuildPartB,BuildPartC�Ƕ�һ������ͬ���ֵĹ��������ӿ�,��Builder��������ConcreteBuilder1��ConcreteBuilder2������ʵ��.
���⻹��һ����Ҫע��ĺ���,����Director::Construct����,�����������ͨ����������Ľӿں�����ɶ���Ĺ���
    --Ҳ����˵������ͬ����װ��Ĺ��̶���һ�µ�(ͬ���ĵ��õ�Construct����),���ǲ�ͬ�Ĺ�����ʽ���в�ͬ�ı�ʾ(����Builder��ʵ��������������ι���,Ҳ���Ƕ�̬)

Builderģʽ�ǻ���������һ�����:һ����������в�ͬ����ɲ���,�⼸�����ֵĲ�ͬ�Ĵ���������в�ͬ�ı�ʾ,���Ǹ�������֮��װ��ķ�ʽ��һ�µ�.
�ȷ�˵һ������,�����ɳ��ֳ����ȵȵĹ��ɵ�(һ������ͬ����ɲ���),��ͬ��Ʒ������������Ҳ��һ��(��ͬ�Ĺ�����ʽ).��Ȼ��ͬ��Ʒ�ƹ��������ĵ�����ͬ,���ǹ����Ĺ��̻���һ����

Ҳ����˵,Director::Construct�����й̶��˸�����ɲ��ֵ�װ�䷽ʽ,��������װ����������ɲ�����Builder��������ʵ��.

ʵ��:
Builderģʽ��ʵ�ֻ������¼��������������ԭ��:

1)�ѱ仯�Ĳ�����ȡ�����γ�һ������Ͷ�Ӧ�Ľӿں���,�����ﲻ��仯���Ƕ��ᴴ��PartA��PartB,�仯�����ǲ�ͬ�Ĵ�������,���Ǿͳ�ȡ�������Builder�����BuildPartA,BuildPartB�ӿں���
2)���þۺϵķ�ʽ�ۺ��˻ᷢ���仯�Ļ���,��������Director�ۺ���Builder���ָ��.

���ϣ�ͨ������������ConcreteBuilder1��ConcreteBuilder2���������ֲ�ͬ�Ľ���ϸ�ڣ����첽����һ���ģ���Construct����ȷ������
ͨ����������������������Ķ��󣬶��ⲿ��չ�ֳ��������Ի��߹����ǲ�һ���ģ��ɸ���Builder�������еĽ��췽����BuildPartA��BuildPartB��BuildPartC��������


������ģʽ�͹���ģʽ�ǳ�����ѽ�����Ǽ�סһ����Ϳ������������ʹ���ˣ�
������ģʽ����Ҫ�����ǻ��������ĵ���˳���ţ�Ҳ������Щ���������Ѿ�ʵ���ˣ�
�������������ص��Ǵ�������Ҫʲô�����Ҵ���һ�������������װ˳�����������ĵġ�
������ģʽʹ�õĳ�����һ�ǲ�Ʒ��ǳ��ĸ��ӣ����߲�Ʒ���еĵ���˳��ͬ�����˲�ͬ��Ч�ܣ����ʱ��ʹ�ý�����ģʽ�Ƿǳ�����
*/


//��Ʒ��
class Product
{
public:
    Product(){};
    ~Product(){};

public:
    void setPartA(const string& s)
    {
        this->m_partA = s;
    }

    void setPartB(const string& s)
    {
        this->m_partB = s;
    }

    void setPartC(const string& s)
    {
        this->m_partC = s;
    }

private:
    string m_partA;
    string m_partB;
    string m_partC;
};

//����Builder���࣬���岻ͬ���ֵĴ����ӿ�
class Builder
{
public:
    Builder(){}
    virtual ~Builder(){}

public:
    virtual void BuildPartA()=0;
    virtual void BuildPartB()=0;
    virtual void BuildPartC()=0;
    virtual Product* GetProduct()=0;
};

//  Builder��������,ʵ��BuilderPartA��BuilderPartB��BuildPartC�ӿں��� 
class ConcreteBuilder1:public Builder
{
public:
    ConcreteBuilder1()
    {
        this->m_pProduct = new Product();
        cout<<"Create empty product!"<<endl;
    }

    ~ConcreteBuilder1()
    {
        delete this->m_pProduct;
        this->m_pProduct = NULL;
    }

public:
    virtual void BuildPartA()
    {
        this->m_pProduct->setPartA("A");
        cout<<"BuildPartA"<<endl;
    }

    virtual void BuildPartB()
    {
        this->m_pProduct->setPartB("B");
        cout<<"BuildPartB"<<endl;
    }

    virtual void BuildPartC()
    {
        this->m_pProduct->setPartC("C");
        cout<<"BuildPartC"<<endl;
    }

    virtual Product* GetProduct()
    {
        return this->m_pProduct;
    }

private:
    Product* m_pProduct;
};

//  Builder��������,ʵ��BuilderPartA��BuilderPartB��BuildPartC�ӿں��� 
class ConcreteBuilder2:public Builder
{
public:
    ConcreteBuilder2()
    {
        this->m_pProduct = new Product();
        cout<<"Create empty product!"<<endl;
    }

    ~ConcreteBuilder2()
    {
        delete this->m_pProduct;
        this->m_pProduct = NULL;
    }

public:
    virtual void BuildPartA()
    {
        this->m_pProduct->setPartA("A");
        cout<<"BuildPartA"<<endl;
    }

    virtual void BuildPartB()
    {
        this->m_pProduct->setPartB("B");
        cout<<"BuildPartB"<<endl;
    }

    virtual void BuildPartC()
    {
        this->m_pProduct->setPartC("C");
        cout<<"BuildPartC"<<endl;
    }

    virtual Product* GetProduct()
    {
        return this->m_pProduct;
    }

private:
    Product* m_pProduct;
};

//ConcreteBuilder1��ConcreteBuilder2��Builder�����������࣬����ʵ�����ֲ�ͬ�Ľ���ϸ��

// ʹ��Builder������Ʒ,������Ʒ�Ĺ��̶�һ��,���ǲ�ͬ��builder�в�ͬ��ʵ��
// �����ͬ��ʵ��ͨ����ͬ��Builder��������ʵ��,����һ��Builder��ָ��,ͨ�������ʵ�ֶ�̬���� 
class Director
{
public:
    Director(Builder* pBuilder)
    {
        this->m_pBuilder = pBuilder;
    }

    ~Director()
    {
        delete this->m_pBuilder;
        this->m_pBuilder = NULL;
    }

public:
    //Construct��������һ�������������������,��ͬ�Ĳ���֮���װ�䷽ʽ����һ�µ�,
    //���ȹ���PartA�����PartB,ֻ�Ǹ��ݲ�ͬ�Ĺ����߻��в�ͬ�ı�ʾ 
    void Construct()
    {
        this->m_pBuilder->BuildPartA();
        this->m_pBuilder->BuildPartB();
        this->m_pBuilder->BuildPartC();
    }
    //void Construct(const string& buildPara);
private:
    Builder* m_pBuilder;
};

#endif