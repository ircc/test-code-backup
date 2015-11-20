// Expression.cpp: implementation of the Expression class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Expression.h"
#include "string"
#include "Context.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//�ն˱��ʽ��������
ConstantExp::ConstantExp(bool b)
{
	m_bConstant = b;
}
     //����ֱ�ӷ���ֵ
bool ConstantExp::Interpret(Context& aContext)
{
	return m_bConstant;
}

//����һ�����������ն˽���ʽ������ָ�������ڲ�����
VariableExp::VariableExp(const char* name)
{
	m_name = strdup(name);
}
     //���ڲ������� �������в�ֵ
bool VariableExp::Interpret(Context& aContext)
{
	return aContext.Lookup(m_name);
}

//���ն˱��ʽ�� ������
AndExp::AndExp(AbstractExpression* op1, AbstractExpression* op2)
{
	m_operand1 = op1;
	m_operand2 = op2;
}
   //�������ʽ�ֱ���㣬�������
bool AndExp::Interpret(Context& aContext)
{
	return m_operand1->Interpret(aContext) && m_operand2->Interpret(aContext);
}

//���ն˱��ʽ�� ������
OrExp::OrExp(AbstractExpression* op1, AbstractExpression* op2)
{
	m_operand1 = op1;
	m_operand2 = op2;
}
   //�������ʽ�ֱ���㣬������
bool OrExp::Interpret(Context& aContext)
{
	return m_operand1->Interpret(aContext) || m_operand2->Interpret(aContext);
}

//���ն˱��ʽ�� ������
NotExp::NotExp(AbstractExpression* op)
{
	this->m_operand = op;
}
   //�������ʽ�ֱ���㣬������
bool NotExp::Interpret(Context& aContext)
{
	return !m_operand->Interpret(aContext);
}

