// Builder.cpp: implementation of the Builder class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Builder.h"
#include "iostream"
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


HumanBuilder::HumanBuilder()
{
	//person=new Person();
}

HumanBuilder::~HumanBuilder()
{

}

void HumanBuilder::buildBody()
{
	cout<<"���� ���� ���壡"<<endl;
	person.setBody("����");
}
void HumanBuilder::buildFoot()
{
	cout<<"���� ���� �ţ�"<<endl;
	person.setFoot("����");
}
void HumanBuilder::buildHead()
{
	cout<<"�������� ͷ��"<<endl;
	person.setHead("����");
}
Person HumanBuilder::buildPerson()
{
	return person;
} 


TransformerBuilder::TransformerBuilder()
{
	//person=newPerson();
}

void TransformerBuilder::buildBody()
{
	cout<<"���� ���ν�� ���壡"<<endl;
	person.setBody("���ν��");
}
void TransformerBuilder::buildFoot()
{
	cout<<"���� ���ν�� �ţ�"<<endl;
	person.setFoot("���ν��");
}
void TransformerBuilder::buildHead()
{
	cout<<"���� ���ν�� ͷ��"<<endl;
	person.setHead("���ν��");
}
Person TransformerBuilder::buildPerson()
{
	return person;
}
TransformerBuilder::~TransformerBuilder()
{

}