// FactoryPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Product.h"
#include "Factory.h"
/*
×× 工厂模式是应用非常广泛的模式，由于简单工厂、工厂、和抽象工厂模式它们的基本功能都是创建所需对象
×× 其中又关系密切，也容易使初学者困扰，这里我把他们放到一起来实现，希望能让大家看清他们的区别和联
×× 系，这里分为我暂时命名为工厂三步曲。下面也是结合我的学习理解总结的，希望对大家也有帮助。
×× 初级阶段：
×× 首先引入工厂的目的就是为了解决大量代码中大量New的问题，怎么办呢？把New封装，建成工厂，这样所有
×× 需要New 的地方都调用工厂的加工产品的方法来创建对象。好处：这样如果要New的Product发生变化只需要
×× 修改CreateProduct的实现一处即可以了。这种实现就是简单工厂模式
×× 进一步需求：
×× 有时为了适应变化，把工厂定义为抽象接口，具体加工对象的工作放到了工厂的子类中实现，这样就变成了
×× 工厂模式，它的一个特征就是所有的加工对象的方法都返回相同的对象类型（具体对象的抽象基类）。
×× 追踪需求：如果用户需求不同系列的一组组件如何创建。
×× 此时就需要抽象工厂模式了，其实工厂模式是抽象工厂模式的一个特例。
×× 补充说明：由于一般情况下，一个系统不需要多个相同工厂的实例，因此一般都把工厂设计成单件模式，这
×× 里为了使工厂模式的模型更清晰，就不把工厂实现成单件模式了

*/
int _tmain(int argc, _TCHAR* argv[])
{	
	cout<<"简单工厂模式实例"<<endl;
	cout<<"要点：把New封装到工厂中"<<endl;
	cout<<"方案：1)每需要新生成的类都对于一个加工产品的方法"<<endl;
	cout<<"      2)需要加工的类有参数模式传递给加工方法"<<endl;
	cout<<"运行"<<endl;
	
	SimpleFactory sf;
	Product *p = sf.CreateProductA();
	p->Function();
	delete p;
	p = sf.CreateProductB();
	p->Function();
	delete p;	
	cout<<"简单工厂运行完毕"<<endl<<endl;
	cout<<"按回车运行工厂模式"<<endl;
	getchar();
	
	
	cout<<"工厂模式实例"<<endl;
	cout<<"要点：把New对象的权限延迟到工厂子类进行"<<endl;
	cout<<"方案：1)实现雷同简单工厂"<<endl;
	cout<<"      2)利用多态，为每一个要创建的子类都创建一个对于工厂"<<endl;
	cout<<"和简单工厂的比较："<<endl;
	cout<<"  1)把工厂进行了抽象，具体加工产品，有子类实现"<<endl;
	cout<<"  2)对于基类不明确要创建的具体什么对象的适应性广"<<endl;
	cout<<"运行"<<endl;
	
	Factory*fct = new ConcreteFactory1();
	p = fct->CreateProduct(0);
	p->Function();
	delete p;
	p = fct->CreateProduct(1);
	p->Function();
	delete p;
	delete fct;

	fct = new ConcreteFactory2();
	p=fct->CreateProduct();
	delete p;
	delete fct;

	cout<<"工厂模式运行完毕"<<endl<<endl;
	cout<<"按回车运行抽象工厂模式"<<endl;
	getchar();


	cout<<"抽象工厂模式实例"<<endl;
	cout<<"问题引入：多套对象的创建。例如下列情况："<<endl;
	cout<<"1) 用户要求两套不同风格的控件"<<endl;
	cout<<"2) 游戏中不同难度的一系列关口"<<endl;
	cout<<"3) 小弟做个的一个系统，要对不同类型的文档（PROE、PDF、WORK、AutoCAD）的基本操作。"<<endl;
	cout<<" 类似上面的这种功能需求工厂模式就有点力不从心了，抽象工厂模式整好用来解决此类问题"<<endl;
	cout<<"特征：每一个工厂实例都产生一系列的产品。在一个工厂实例中加工产品方法的返回值不同"<<endl;
	cout<<"  当然，它们可以是共同基类继承而来，但在此模式中，关心和体现出来的是它们的不同点"<<endl;
	cout<<"  因此如果它们的返回值类型从共同基类继承，并返回此基类，就退化为工厂模式了，依照"<<endl;
	cout<<"  此特征因此工厂模式是抽象工厂模式的特例，可以近似认为抽象工厂是不同工厂聚合而成"<<endl;
	cout<<"  (这是个人见解，仅供参考)"<<endl;
	cout<<"运行"<<endl<<endl<<endl;
	

	AbstractFactory *absfct = new ConcreteAbsFactory1();
	ConcreteProductA *cpa = absfct->CreateA();
	cpa->Function();
	delete cpa;
	ConcreteProductB *cpb = absfct->CreateB();
	cpb->Function();
	delete cpb;
	delete absfct;
	absfct = new ConcreteAbsFactory2();
	cpa = absfct->CreateA();
	cpa->Function();
	delete cpa;
	cpb = absfct->CreateB();
	cpb->Function();
	delete cpb;

	std::cout<<endl<<"按任意键结束";
	getchar();
	return 0;
}

