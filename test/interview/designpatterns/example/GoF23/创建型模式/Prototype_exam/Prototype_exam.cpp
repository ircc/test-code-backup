// Prototype_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"

int main(int argc, char* argv[])
{
	/*��������Ϊһ�����ԣ����Բ���ԭ��ģʽ��¡����ֱ�����ɶ���ֵ��
	���˸о���ԭ�ͷ��������Ǻܴ�Ψһ��������Ҫ֪�������ࡣ������಻��ʵ������������಻�ǳ���ģ�
	��ƾ�����Լ������һ��ʵ������֪����������������õ�һ�����������һ����ʵ���Ǻ����ѵ�*/
	/*
	ConcretePrototype cp1(101,"wang",23);
    //ConcretePrototype cp2;
	//cp2=cp1;
    //�������Ч��
  	ConcretePrototype cp2(cp1);
	cp1.setName("zhang");
	cp1.show();	cp2.show();
	//*/
	Prototype* p = new ConcretePrototype(101,"wang",23);
	/*new ConcretePrototype(101,"wang",23); �����Ǵ������������ݹ�����
	Ҳ����˵����������֪��������ֻ࣬��ӵ�����ĳ���ӿڣ���һ�������ʵ������
	���ǾͿ��Եõ�һ������ͬ���Ķ��󣬼���Ӧ�á�������������ϵͳ����ʱ��Ҫ�����Ǹ������࣬
	�����Զ�̬�ƶ�
	*/
	Prototype* p1 = p->Clone();
	p->show(); p1->show();
	p->setName("li");
    p->show(); p1->show();
	printf("Hello World!\n");
	return 0;
}

