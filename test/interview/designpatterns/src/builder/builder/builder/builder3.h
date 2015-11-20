#ifndef _BUILDER3_H_
#define _BUILDER3_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
 *http://blog.csdn.net/zhengzhb/article/details/7375966
 ���壺��һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��

 ���ͣ�������ģʽ

 �ĸ�Ҫ��

 ��Ʒ�ࣺһ����һ����Ϊ���ӵĶ���Ҳ����˵��������Ĺ��̱Ƚϸ��ӣ�һ����бȽ϶�Ĵ��������ڱ���ͼ�У���Ʒ����һ��������࣬���ǳ����ࡣʵ�ʱ���У���Ʒ���������һ�������������Ĳ�ͬʵ����ɣ�Ҳ�������ɶ�������������ǵ�ʵ����ɡ�
 �������ߣ�����������ߵ�Ŀ�ģ���Ϊ�˽�����ľ�����̽�������������ʵ�֡�������������չ��һ�����ٻ����������󷽷���һ�����������Ʒ��һ�����������ز�Ʒ��
 �����ߣ�ʵ�ֳ����������δʵ�ֵķ�����������˵һ�������������齨��Ʒ�������齨�õĲ�Ʒ��
 �����ࣺ��������ʵ��Ľ��������齨��Ʒ��������һ�㲻���Ʒ�෢��������ϵ���뵼����ֱ�ӽ������ǽ������ࡣһ����˵�������౻������װ�������ױ�Ĳ��֡�

 ������ģʽ���ŵ�

 ���ȣ�������ģʽ�ķ�װ�Ժܺá�ʹ�ý�����ģʽ������Ч�ķ�װ�仯����ʹ�ý�����ģʽ�ĳ����У�һ���Ʒ��ͽ��������ǱȽ��ȶ��ģ�
    ��ˣ�����Ҫ��ҵ���߼���װ�ڵ������ж�������Կ���ȡ�ñȽϺõ��ȶ��ԡ�
 ��Σ�������ģʽ�����׽�����չ��������µ�����ͨ��ʵ��һ���µĽ�������Ϳ�����ɣ������ϲ����޸�֮ǰ�Ѿ�����ͨ���Ĵ��룬���Ҳ�Ͳ����ԭ�й���������ա�



 ������ģʽ�빤��ģʽ������
 ���ǿ��Կ�����������ģʽ�빤��ģʽ�Ǽ�Ϊ���Ƶģ������ϣ�������ģʽ����ֻ�ȹ���ģʽ����һ���������ࡱ�Ľ�ɫ��
    �ڽ�����ģʽ����ͼ�У��������������࿴�������յ��õĿͻ��ˣ���ôͼ��ʣ��Ĳ��־Ϳ��Կ�����һ���򵥵Ĺ���ģʽ�ˡ�
 �빤��ģʽ��ȣ�������ģʽһ������������Ϊ���ӵĶ�����Ϊ����Ĵ������̸�Ϊ���ӣ���˽�����Ĵ������̶����������һ���µ��ࡪ�������ࡣ
    Ҳ����˵������ģʽ�ǽ������ȫ���������̷�װ�ڹ������У��ɹ�������ͻ����ṩ���յĲ�Ʒ����������ģʽ�У���������һ��ֻ�ṩ��Ʒ���и�������Ľ��죬�������彨����̽����������ࡣ
    �ɵ����ฺ�𽫸�����������ض��Ĺ����齨Ϊ��Ʒ��Ȼ���齨�õĲ�Ʒ�������ͻ��ˡ�



 �ܽ�
 ������ģʽ�빤��ģʽ���ƣ����Ƕ��ǽ�����ģʽ�����õĳ���Ҳ�����ơ�һ����˵�������Ʒ�Ľ���ܸ��ӣ���ô���ù���ģʽ�������Ʒ�Ľ�������ӣ���ô���ý�����ģʽ��
 */

class Product3 
{
public:
    void showProduct()
    {
        cout<<"���ƣ�"<<name<<endl;
        cout<<"�ͺţ�"<<type<<endl;
    }
    void setName(string name) 
    {
        this->name = name;
    }
    void setType(string type)
    {
        this->type = type;
    }

private:
    string name;
    string type;
};


class Builder3 
{
public:
    virtual void setPart(string arg1, string arg2) = 0;
    virtual Product3* getProduct() = 0;
};

class ConcreteBuilder : public Builder3 
{
public:
    ConcreteBuilder()
    {
        m_product = new Product3();
    }

public:
    Product3* getProduct() 
    {
        return m_product;
    }

    void setPart(string arg1, string arg2) 
    {
        m_product->setName(arg1);
        m_product->setType(arg2);
    }

private:
    Product3*  m_product;
};

class Director3 
{
public:
    Director3()
    {
        m_pBuilder = new ConcreteBuilder();
    }

public:
    Product3* getAProduct()
    {
        m_pBuilder->setPart("��������","X7");
        return m_pBuilder->getProduct();
    }
    Product3* getBProduct()
    {
        m_pBuilder->setPart("�µ�����","Q5");
        return m_pBuilder->getProduct();
    }

private:
    Builder3* m_pBuilder;
};


#endif