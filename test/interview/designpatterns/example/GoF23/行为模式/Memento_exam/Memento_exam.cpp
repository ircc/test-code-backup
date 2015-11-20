// Memento_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Memento.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	Originator* o = new Originator();
	o->SetState("old"); //����ǰ״̬
	o->PrintState();//��ʾ��ǰֵ	
	Memento* m1 = o->CreateMemento(); //����ǰ״̬����
	cout<<endl;

	o->SetState("newA"); //�޸�״̬
	o->PrintState();
	cout<<endl;

	o->SetState("newB"); //�޸�״̬
	o->PrintState();
	cout<<endl;

	o->SetState("newC"); //�޸�״̬
	o->PrintState();
    Memento* m2 = o->CreateMemento(); //����ǰ״̬����
	cout<<endl;

	o->RestoreToMemento(m1); //�ָ��޸�ǰ״̬
	o->PrintState();
	cout<<endl;

	o->RestoreToMemento(m2); //�ָ��޸�ǰ״̬
	o->PrintState();
//	printf("Hello World!\n");
	return 0;
}

