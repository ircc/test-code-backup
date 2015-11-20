// FactoryPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Product.h"
#include "Factory.h"
/*
���� ����ģʽ��Ӧ�÷ǳ��㷺��ģʽ�����ڼ򵥹������������ͳ��󹤳�ģʽ���ǵĻ������ܶ��Ǵ����������
���� �����ֹ�ϵ���У�Ҳ����ʹ��ѧ�����ţ������Ұ����Ƿŵ�һ����ʵ�֣�ϣ�����ô�ҿ������ǵ��������
���� ϵ�������Ϊ����ʱ����Ϊ����������������Ҳ�ǽ���ҵ�ѧϰ����ܽ�ģ�ϣ���Դ��Ҳ�а�����
���� �����׶Σ�
���� �������빤����Ŀ�ľ���Ϊ�˽�����������д���New�����⣬��ô���أ���New��װ�����ɹ�������������
���� ��ҪNew �ĵط������ù����ļӹ���Ʒ�ķ������������󡣺ô����������ҪNew��Product�����仯ֻ��Ҫ
���� �޸�CreateProduct��ʵ��һ���������ˡ�����ʵ�־��Ǽ򵥹���ģʽ
���� ��һ������
���� ��ʱΪ����Ӧ�仯���ѹ�������Ϊ����ӿڣ�����ӹ�����Ĺ����ŵ��˹�����������ʵ�֣������ͱ����
���� ����ģʽ������һ�������������еļӹ�����ķ�����������ͬ�Ķ������ͣ��������ĳ�����ࣩ��
���� ׷����������û�����ͬϵ�е�һ�������δ�����
���� ��ʱ����Ҫ���󹤳�ģʽ�ˣ���ʵ����ģʽ�ǳ��󹤳�ģʽ��һ��������
���� ����˵��������һ������£�һ��ϵͳ����Ҫ�����ͬ������ʵ�������һ�㶼�ѹ�����Ƴɵ���ģʽ����
���� ��Ϊ��ʹ����ģʽ��ģ�͸��������Ͳ��ѹ���ʵ�ֳɵ���ģʽ��

*/
int _tmain(int argc, _TCHAR* argv[])
{	
	cout<<"�򵥹���ģʽʵ��"<<endl;
	cout<<"Ҫ�㣺��New��װ��������"<<endl;
	cout<<"������1)ÿ��Ҫ�����ɵ��඼����һ���ӹ���Ʒ�ķ���"<<endl;
	cout<<"      2)��Ҫ�ӹ������в���ģʽ���ݸ��ӹ�����"<<endl;
	cout<<"����"<<endl;
	
	SimpleFactory sf;
	Product *p = sf.CreateProductA();
	p->Function();
	delete p;
	p = sf.CreateProductB();
	p->Function();
	delete p;	
	cout<<"�򵥹����������"<<endl<<endl;
	cout<<"���س����й���ģʽ"<<endl;
	getchar();
	
	
	cout<<"����ģʽʵ��"<<endl;
	cout<<"Ҫ�㣺��New�����Ȩ���ӳٵ������������"<<endl;
	cout<<"������1)ʵ����ͬ�򵥹���"<<endl;
	cout<<"      2)���ö�̬��Ϊÿһ��Ҫ���������඼����һ�����ڹ���"<<endl;
	cout<<"�ͼ򵥹����ıȽϣ�"<<endl;
	cout<<"  1)�ѹ��������˳��󣬾���ӹ���Ʒ��������ʵ��"<<endl;
	cout<<"  2)���ڻ��಻��ȷҪ�����ľ���ʲô�������Ӧ�Թ�"<<endl;
	cout<<"����"<<endl;
	
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

	cout<<"����ģʽ�������"<<endl<<endl;
	cout<<"���س����г��󹤳�ģʽ"<<endl;
	getchar();


	cout<<"���󹤳�ģʽʵ��"<<endl;
	cout<<"�������룺���׶���Ĵ������������������"<<endl;
	cout<<"1) �û�Ҫ�����ײ�ͬ���Ŀؼ�"<<endl;
	cout<<"2) ��Ϸ�в�ͬ�Ѷȵ�һϵ�йؿ�"<<endl;
	cout<<"3) С��������һ��ϵͳ��Ҫ�Բ�ͬ���͵��ĵ���PROE��PDF��WORK��AutoCAD���Ļ���������"<<endl;
	cout<<" ������������ֹ������󹤳�ģʽ���е����������ˣ����󹤳�ģʽ�������������������"<<endl;
	cout<<"������ÿһ������ʵ��������һϵ�еĲ�Ʒ����һ������ʵ���мӹ���Ʒ�����ķ���ֵ��ͬ"<<endl;
	cout<<"  ��Ȼ�����ǿ����ǹ�ͬ����̳ж��������ڴ�ģʽ�У����ĺ����ֳ����������ǵĲ�ͬ��"<<endl;
	cout<<"  ���������ǵķ���ֵ���ʹӹ�ͬ����̳У������ش˻��࣬���˻�Ϊ����ģʽ�ˣ�����"<<endl;
	cout<<"  ��������˹���ģʽ�ǳ��󹤳�ģʽ�����������Խ�����Ϊ���󹤳��ǲ�ͬ�����ۺ϶���"<<endl;
	cout<<"  (���Ǹ��˼��⣬�����ο�)"<<endl;
	cout<<"����"<<endl<<endl<<endl;
	

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

	std::cout<<endl<<"�����������";
	getchar();
	return 0;
}

