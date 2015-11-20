// Factory_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Factory.h"
#include "Product.h"
#include <iostream>
using namespace std;


//以上两个问题也就引出了 Factory模式的两个最重要的功能： 
// 1）定义创建对象的接口，封装了对象的创建； 
// 2）使得具体化类的工作延迟到了子类中。
// 


// 1）为了提高内聚（Cohesion）和松耦合（Coupling） ，我们经常会抽象出一些类的公共接口以形成抽象基类或者接口。
//    这样我们可以通过声明一个指向基类的指针来指向实际的子类实现，达到了多态的目的。
//    这里很容易出现的一个问题 n 多的子类继承自抽象基类，我们不得不在每次要用到子类的地方就编写诸如 new  ×××;的代码。
//    这里带来两个问题 
//		1）客户程序员必须知道实际子类的名称（当系统复杂后，命名将是一个很不好处理的问题，为了处理可能的名字冲突，
//		   有的命名可能并不是具有很好的可读性和可记忆性，就姑且不论不同程序员千奇百怪的个人偏好了。 ） ，
//		2）程序的扩展性和维护变得越来越困难。 
// 2）还有一种情况就是在父类中并不知道具体要实例化哪一个具体的子类。
//	  这里的意思为：假设我们在类 A 中要使用到类 B，B 是一个抽象父类，在 A 中并不知道具体要实例化那一个 B 的子类，但是在类 A的子类 D中是可以知道的。
//	  在 A中我们没有办法直接使用类似于 new  ×××的语句，因为根本就不知道×××是什么。 
//	  
int main(int argc, char* argv[])
{
	Factory* fac = new ConcreteFactory1();  //这不是new了子类吗？ 工厂
 
	Product* p = fac->CreateProduct(); //创建产品  不需要指明具体产品了

	Factory* fac2 = new ConcreteFactory2();  //这不是new了子类吗？ 工厂

	Product* p2 = fac2->CreateProduct(); //创建产品  不需要指明具体产品了

	printf("Hello World!\n");
	return 0;
}

