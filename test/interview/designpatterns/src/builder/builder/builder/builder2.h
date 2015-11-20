#ifndef _BUILDER2_H_
#define _BUILDER2_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
 *http://blog.csdn.net/effective_coder/article/details/8917359#
 
刚开始我一直感觉建造者模式不太好懂，也许是我笨了点缘故，勤能补拙嘛，所以只能多看多想了
大话设计模式里面那个对于建造者模式我讲解，个人感觉不太好理解，我是看了很多遍也没体会到那样设计的精髓，后来在另一本设计模式上才稍微领悟到了点，


在这里我想到一个比较形象的例子：

比如我某天去吃兰州拉面，他们有不同的套餐，套餐里包含的种类是一样的，都有一
碗拉面，一份泡菜，一杯饮料。但是不同的套餐里这3样又都不是全部一样的，也许分量和品质有差别。此时我们就可以用建造者模式。

这里我没有合适的UML图，大致说一下模型：客户根据套餐不同，跟收银员点了一份A套餐的拉面，另一名客户同时又点了一份B套餐的拉面，
这时收银员把这两个单子转交给后台，其实也就是厨房，厨师看到这两个单子的不同而煮不同的拉面，然后返回给服务员，服务员分发拉面给客户！



1．建造者（Builder）角色：给出一个抽象接口，以规范产品对象的各个组成成分的建造。
2．具体建造者（Concrete Builder）角色：担任这个角色的是于应用程序紧密相关的类，它们在应用程序调用下创
建产品实例。


3．指导者（Director）角色：担任这个角色的类调用具体建造者角色以创建产品对象。是收银员，他知道我想要什么套餐，他会告诉里面的
店员工去准备什么套餐。

示例代码在下面

这个例子在FoodManager的时候还利用了简单工厂模式，其实更好的设计可以把FoodManager改写成单例模式，因为一般一个收银员在指示其他所有的工作者听从她的指挥，好了，总结一下建造模式：

1、建造者模式的使用使得产品的内部表象可以独立的变化。使用建造者模式可以使客户端不必知道产品内部组成的细节。
2、每一个Builder都相对独立，而与其它的Builder无关。
3、可使对构造过程更加精细控制。
4、将构建代码和实现代码分开。
5、建造者模式的缺点在于难于应付“分步骤构建算法”的需求变动


关于建造者模式的标准实例，相信学过C#的都知道有一个stringbuilder 他就是一个利用这种思想设计出来的，在我自己构思的C++库中我也会用string实作一个stringbuilder出来，到饭点了，闪！

 */

// 定义产品类，指示拉面的一些属性
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

// 定义抽象的制作类，含有三个制作的环节和一个返回制作出来的产品方法
class Builder2  
{
public:
    virtual void BuildCoolDish() = 0;
    virtual void BuildDrink() = 0;
    virtual void BuildRice() = 0;
    virtual Food* GetFood() = 0;
};


// 制作者A，我们假定他做出来的凉菜收20，饮料15，拉面25，总共60元，也就是说收银员接到60元的套餐就交给A来做
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
        cout<<"凉菜已经制作好，已加入制作工序容器（其实也就是做好了一样放在了盘子里）"<<endl;
        food->add("CoolDish",20);
    }

    virtual void BuildDrink()
    {
        cout<<"饮料制作好了，已加入制作工序容器(放在了杯子里)"<<endl;
        food->add("drink",15);
    }

    virtual void BuildRice()
    {
        cout<<"拉面做好了，放弃制作工序容器（放在了盘子里）"<<endl;
        food->add("Rice",25);
    }

    virtual Food* GetFood()
    {
        return food;
    }

private:
    Food *food;
};

// 制作者B，我们假定他做出来的凉菜收30，饮料20，拉面20，总共70元，也就是说收银员接到70元的套餐就交给B来做
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
        cout<<"凉菜已经制作好，已加入制作工序容器（其实也就是做好了一样放在了盘子里）"<<endl;
        food->add("CoolDish",30);
    }

    virtual void BuildDrink()
    {
        cout<<"饮料制作好了，已加入制作工序容器(放在了杯子里)"<<endl;
        food->add("drink",20);
    }

    virtual void BuildRice()
    {
        cout<<"拉面做好了，放弃制作工序容器（放在了盘子里）"<<endl;
        food->add("Rice",20);
    }

    virtual Food* GetFood()
    {
        return food;
    }

private:
    Food *food;
};

//定义收银员
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
            //你还可以加其他套餐;
            ;
        builder->BuildCoolDish();
        builder->BuildDrink();
        builder->BuildRice();

        return builder->GetFood();
    }

};
#endif