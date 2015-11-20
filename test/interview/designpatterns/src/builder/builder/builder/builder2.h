#ifndef _BUILDER2_H_
#define _BUILDER2_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
 *http://blog.csdn.net/effective_coder/article/details/8917359#
 
�տ�ʼ��һֱ�о�������ģʽ��̫�ö���Ҳ�����ұ��˵�Ե�ʣ����ܲ�׾�����ֻ�ܶ࿴������
�����ģʽ�����Ǹ����ڽ�����ģʽ�ҽ��⣬���˸о���̫����⣬���ǿ��˺ܶ��Ҳû��ᵽ������Ƶľ��裬��������һ�����ģʽ�ϲ���΢�����˵㣬


���������뵽һ���Ƚ���������ӣ�

������ĳ��ȥ���������棬�����в�ͬ���ײͣ��ײ��������������һ���ģ�����һ
�����棬һ���ݲˣ�һ�����ϡ����ǲ�ͬ���ײ�����3���ֶ�����ȫ��һ���ģ�Ҳ�������Ʒ���в�𡣴�ʱ���ǾͿ����ý�����ģʽ��

������û�к��ʵ�UMLͼ������˵һ��ģ�ͣ��ͻ������ײͲ�ͬ��������Ա����һ��A�ײ͵����棬��һ���ͻ�ͬʱ�ֵ���һ��B�ײ͵����棬
��ʱ����Ա������������ת������̨����ʵҲ���ǳ�������ʦ�������������ӵĲ�ͬ����ͬ�����棬Ȼ�󷵻ظ�����Ա������Ա�ַ�������ͻ���



1�������ߣ�Builder����ɫ������һ������ӿڣ��Թ淶��Ʒ����ĸ�����ɳɷֵĽ��졣
2�����彨���ߣ�Concrete Builder����ɫ�����������ɫ������Ӧ�ó��������ص��࣬������Ӧ�ó�������´�
����Ʒʵ����


3��ָ���ߣ�Director����ɫ�����������ɫ������þ��彨���߽�ɫ�Դ�����Ʒ����������Ա����֪������Ҫʲô�ײͣ�������������
��Ա��ȥ׼��ʲô�ײ͡�

ʾ������������

���������FoodManager��ʱ�������˼򵥹���ģʽ����ʵ���õ���ƿ��԰�FoodManager��д�ɵ���ģʽ����Ϊһ��һ������Ա��ָʾ�������еĹ�������������ָ�ӣ����ˣ��ܽ�һ�½���ģʽ��

1��������ģʽ��ʹ��ʹ�ò�Ʒ���ڲ�������Զ����ı仯��ʹ�ý�����ģʽ����ʹ�ͻ��˲���֪����Ʒ�ڲ���ɵ�ϸ�ڡ�
2��ÿһ��Builder����Զ���������������Builder�޹ء�
3����ʹ�Թ�����̸��Ӿ�ϸ���ơ�
4�������������ʵ�ִ���ֿ���
5��������ģʽ��ȱ����������Ӧ�����ֲ��蹹���㷨��������䶯


���ڽ�����ģʽ�ı�׼ʵ��������ѧ��C#�Ķ�֪����һ��stringbuilder ������һ����������˼����Ƴ����ģ������Լ���˼��C++������Ҳ����stringʵ��һ��stringbuilder�������������ˣ�����

 */

// �����Ʒ�ָ࣬ʾ�����һЩ����
class Food     
{
public:
    void add(string foodName,int price)
    {
        mFoodName.push_back(foodName);
        mPrice.push_back(price);
    }

    void show()
    {
        cout<<"food list:"<<endl;
        cout<<"_______________________"<<endl;
        for(int i=0;i<mFoodName.size();++i)
        {
            cout<<mFoodName[i]<<"  "<<mPrice[i]<<endl;
        }
    }

private:
    vector<string> mFoodName;
    vector<int> mPrice;
};

// �������������࣬�������������Ļ��ں�һ���������������Ĳ�Ʒ����
class Builder2  
{
public:
    virtual void BuildCoolDish() = 0;
    virtual void BuildDrink() = 0;
    virtual void BuildRice() = 0;
    virtual Food* GetFood() = 0;
};


// ������A�����Ǽٶ�����������������20������15������25���ܹ�60Ԫ��Ҳ����˵����Ա�ӵ�60Ԫ���ײ;ͽ���A����
class BuilderA : public Builder2 
{
public:
    BuilderA()
    {
        food = new Food();
    }

public:
    virtual void BuildCoolDish()
    {
        cout<<"�����Ѿ������ã��Ѽ�������������������ʵҲ����������һ�������������"<<endl;
        food->add("CoolDish",20);
    }

    virtual void BuildDrink()
    {
        cout<<"�����������ˣ��Ѽ���������������(�����˱�����)"<<endl;
        food->add("drink",15);
    }

    virtual void BuildRice()
    {
        cout<<"���������ˣ������������������������������"<<endl;
        food->add("Rice",25);
    }

    virtual Food* GetFood()
    {
        return food;
    }

private:
    Food *food;
};

// ������B�����Ǽٶ�����������������30������20������20���ܹ�70Ԫ��Ҳ����˵����Ա�ӵ�70Ԫ���ײ;ͽ���B����
class BuilderB : public Builder2  
{
public:
    BuilderB()
    {
        food = new Food();
    }

public:
    virtual void BuildCoolDish()
    {
        cout<<"�����Ѿ������ã��Ѽ�������������������ʵҲ����������һ�������������"<<endl;
        food->add("CoolDish",30);
    }

    virtual void BuildDrink()
    {
        cout<<"�����������ˣ��Ѽ���������������(�����˱�����)"<<endl;
        food->add("drink",20);
    }

    virtual void BuildRice()
    {
        cout<<"���������ˣ������������������������������"<<endl;
        food->add("Rice",20);
    }

    virtual Food* GetFood()
    {
        return food;
    }

private:
    Food *food;
};

//��������Ա
class FoodManager
{
private:
    Builder2 *builder;

public:
    FoodManager(){builder = NULL;};

    Food* FoodInfo(char ch)
    {
        if(ch == 'A')
            builder = new BuilderA();
        else if(ch == 'B')
            builder = new BuilderB();
        else
            //�㻹���Լ������ײ�;
            ;
        builder->BuildCoolDish();
        builder->BuildDrink();
        builder->BuildRice();

        return builder->GetFood();
    }

};
#endif