// Singleton_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Singleton.h"

int main(int argc, char* argv[])
{
	//Singleton sgn1;//ʵ��������
	Singleton* sgn = Singleton::Instance();//ͨ���������ú����õ�һ������
	printf("Hello World!\n");
	return 0;
}

