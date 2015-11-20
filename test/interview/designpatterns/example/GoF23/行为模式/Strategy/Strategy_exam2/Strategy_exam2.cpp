// Strategy_exam2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Duck.h"
#include "Fly.h"
#include "Quack.h"

int main(int argc, char* argv[])
{
	//����һ����ģ��Ѽ��
    Duck* duck= new ModelDuck();
    duck->display();duck->performQuack();duck->performFly();
	//ģ��Ѽ�ӻ�������ֻ������һ�����ж����ࣨ���û�У�����������Ѽ�������ʹ��
	duck->setFlyBehavior(new FlyRocketPowered());
	duck->display();duck->performQuack();duck->performFly();
	//printf("Hello World!\n");
	return 0;
}

