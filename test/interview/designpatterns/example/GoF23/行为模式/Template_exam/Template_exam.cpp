// Template_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Template.h"

int main(int argc, char* argv[])
{
	//ģ��ģʽ�������幫�������ڳ�����
	//�ֱ����ɲ�ͬ��������һ��
	AbstractClass* p1 = new ConcreteClass1();
	AbstractClass* p2 = new ConcreteClass2(); 
	//���ù�����������
	cout<<"���ù�����������:....."<<endl;
	p1->CommonMethod();p2->CommonMethod();
	cout<<"�������෽������:....."<<endl;
	//p1->PrimitiveOperation1();p2->PrimitiveOperation2();
	p1->TemplateMethod();
	p2->TemplateMethod();
	//printf("Hello World!\n");
	return 0;
}

