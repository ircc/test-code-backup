// Strategy_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Strategy.h"
#include "Application.h"

int main(int argc, char* argv[])
{
	//����һ��Ӧ�������
	Application *app = new ApplicationOne();
	//������Ϊ
	app->disply();
	app->CommonMethod();
	app->perForm();
    //��������Ϊ
	app->setBehaviorOne(new BehaviorOneB());
	app->setBehaviorTwo(new BehaviorTwoB());
    app->perForm();
	//printf("Hello World!\n");
	return 0;
}

