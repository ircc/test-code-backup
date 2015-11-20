// Observer_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Subject.h"
#include "Observer.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	ConcreteSubject* sub = new ConcreteSubject();
    Observer* o1 = new ConcreteObserverA(sub);
	Observer* o2 = new ConcreteObserverB(sub);
	cout<<endl<<endl;

	sub->SetState("old");
	sub->Notify();
	cout<<endl<<endl;

	sub->SetState("new"); //Ҳ������Observer����
	sub->Notify();
    cout<<endl<<endl;

	sub->Detach(o1);/*�ӿ�Ŀ����Ĺ۲����б���ɾ��һ���۲���o1->~Observer();//�۲��߶����Լ��ӿ�Ŀ�б���ɾ��*/
	sub->Notify();
	//printf("Hello World!\n");
	return 0;
}

