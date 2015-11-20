// Mediator_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Mediator.h"
#include "Colleage.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	ConcreteMediator* m = new ConcreteMediator();//�н����
	ConcreteColleageA* c1 = new ConcreteColleageA(m);//����ͬ��һ
	ConcreteColleageB* c2 = new ConcreteColleageB(m);//����ͬ�¶�
	m->IntroColleage(c1,c2);//��Ҫͨ�ŵ�ͬ���������н飬��������ܶ�������б��

	c1->SetState("111111111111"); //ͬ��һ������Ϣ
    //cout<<"ͬ��һ��ǰֵ��"<<c1->GetState()<<endl;//����ͬ��һ����Ϣ
    c1->Aciton();/*ͬ��һ�Ļ,���н���Ϊÿ��ͬ�¶�дһ��ר�ŵĻ��
	                 ��Ȼ���ĳͬ�»����ܶ࣬����Ϊ��д�ܶ�������俪�ص���*/
	cout<<"ͬ�¶���ǰֵ:"<<c2->GetState()<<endl;/*�һ�Ѿ�ͨ���н齫��Ϣ���ݸ�ͬ�¶�,����ͬ�¶���ֵ*/


	c2->SetState("22222222");/*/ͬ�¶��յ���Ϣ��������Ӧ�����Լ�����Ϣ*/
	//cout<<"ͬ�¶���ǰֵ��"<<c2->GetState();//����ͬ�¶�����Ϣ
    c2->Aciton();

	//printf("Hello World!\n");*/
	return 0;
}

