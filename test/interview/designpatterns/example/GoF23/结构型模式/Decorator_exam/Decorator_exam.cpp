// Decorator_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Decorator.h"
int main(int argc, char* argv[])
{
	//һ�������ӿ�
	Component* com;
	//ָ��ԭʼ����
	com= new ConcreteComponent();
	com->Operation();
	//ָ��Aװ�λ������´�ӡ
	cout<<"--------------------------------------"<<endl;
	com = new DecoratorA(com);
	com->Operation();
	//ָ��Bװ�λ������´�ӡ
	cout<<"--------------------------------------"<<endl;
	com = new DecoratorB(com);
	com->Operation();
	return 0;
}

