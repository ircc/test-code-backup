// AdapterObj_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Adapter.h"

int main(int argc, char* argv[])
{
	//������������һ���ӿ�
	ThirdPartyInterface* thirdPartyInterface;
	//��������ӿ�ָ����������һ��ʵ������ʵ���ɻ�
	thirdPartyInterface = new ThirdPartyOne;
    //Ŀ����ָ��ָ������������õ������෽��
	Target* tgt= new Adapter(thirdPartyInterface);
	//�������෽����ע�����ǵ���ʱ�õ���������Ϥ��Ŀ���෽��Request
	tgt->Request();
	//Ŀ����ָ��ָ�����������ñ��෽��
	tgt = new Target();
	//���ñ��෽��
	tgt->Request();
	printf("Hello World!\n");
	return 0;
}

