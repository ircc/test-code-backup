// Builder_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Builder.h"
#include "Product.h"
#include "Director.h"

int main(int argc, char* argv[])
{
	Product* pro;//���ղ�Ʒ��ָ��
	//��һ������Ĺ����߸���ָ����
	Director* d = new Director(new ConcreteBuilder());
	pro=d->Construct();//���ò�����Ʒ
	pro->fun();
	printf("Hello World!\n");
	return 0;
}

