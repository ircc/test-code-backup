// ChainOfResponsibility_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Request.h"
#include "Handle.h"

int main(int argc, char* argv[])
{
	HandleChain hc;//����һ����������Ӧ��ʱ���Ը�����Ҫ��������
	
	Request* que= new Request();//����һ������
	que->setRequestName("�򶹶�");//��Ȼ�����ڹ�������ʱ�ṩ������û��������
	que->setRequestLeverl(2);//��Ȼ�����ڹ�������ʱ�ṩ������û��������*/
	hc.setRequest(que);//������������

	que->setRequestLeverl(15);//�������⼶��
	hc.setRequest(que);

	//printf("Hello World!\n");
	return 0;
}

