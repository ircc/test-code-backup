// AdapterClass_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Adapter.h"

int main(int argc, char* argv[])
{
	//Ŀ����ָ�����ָ�������ࣨ������������
	Target* adt = new Adapter();
	//ͨ�����������õ�����������
	adt->Request();
	//Ŀ����ָ�뵱Ȼ����ָ�������
	adt=new Target();
	//ֱ�ӵ��ñ��෽��
	adt->Request();
	printf("Hello World!\n");
	return 0;
}

