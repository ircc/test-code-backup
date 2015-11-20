// Bridge_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Abstraction.h"
#include "AbstractionImp.h"
#include "Bridge.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	/*Bridge ���õ�̬ģʽ���������Է�����Ϊ��̬���������������Ƿ�����Bridge �����ָ�롣������ʹ��
    Bridge* bridge  = Bridge::getBridge();
    bridge->setActionImp(new ConcreteAbstractionImpA());
     Abstraction* action = new RefinedAbstraction();
	action->Operation();*/
	//����һ���µĻ
    Abstraction* action = new RefinedAbstraction();
	//�����÷��������Ĭ�Ϸ���
	action->Operation();
	//ͨ�������÷���
	Bridge::setActionImp(new ConcreteAbstractionImpA());
    action->Operation();
	printf("Hello World!\n");
	return 0;
}

