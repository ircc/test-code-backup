// Interpreter_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Context.h"
#include "Expression.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	//���ɱ��ʽ
	AbstractExpression* expression;
	//����������
	Context context;
	//��������
	VariableExp* varX = new VariableExp("keyX");
	VariableExp* varY = new VariableExp("keyY");
	/*һ�����ӱ��ʽ ���루���������������루�������ǣ�����������*/
	expression = new OrExp(
		new AndExp(new ConstantExp(true), varX),
		new AndExp(varY, new NotExp(varX)));
	//�ڽ������н����ⲿ���ֺ�ֵ�Ĺ���
	context.Assign(varX, false);
	context.Assign(varY, true);
	//�ݹ�������ʽ��ֵ
	bool result = expression->Interpret(context);
	cout<<"result: "<<result<<endl;
	printf("Hello World!\n");
	return 0;
}

