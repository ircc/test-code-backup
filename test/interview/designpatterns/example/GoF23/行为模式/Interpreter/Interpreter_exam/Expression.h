// Expression.h: interface for the Expression class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPRESSION_H__C5AE2FFA_1A76_4DFA_A3DE_9EB3F7EC9C33__INCLUDED_)
#define AFX_EXPRESSION_H__C5AE2FFA_1A76_4DFA_A3DE_9EB3F7EC9C33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Context;

//������ʽ��
class AbstractExpression  
{
public:
	AbstractExpression(){}
	virtual ~AbstractExpression(){}
	virtual bool Interpret(Context&)=0;
protected:
private:
};

//�ն˱��ʽ��������
class ConstantExp: public AbstractExpression
{
public:
	//���쳣��
	ConstantExp(bool b);
	virtual ~ConstantExp(){}
	//����ֱ�ӷ���ֵ
	bool Interpret(Context& aContext);
private:
	bool m_bConstant;
};

//����һ�����������ն˽���ʽ������ָ�������ڲ�����
class VariableExp:public AbstractExpression
{
public:
	VariableExp(const char* name);
	//���ڲ������� �������в�ֵ
	bool Interpret(Context& aContext);
	char* m_name;
};

//���ն˱��ʽ�� ������
class AndExp : public AbstractExpression
{
public:
	AndExp(AbstractExpression* op1, AbstractExpression* op2);
	virtual ~AndExp(){}
	bool Interpret(Context& aContext);
private:
	AbstractExpression* m_operand1;
	AbstractExpression* m_operand2;
};
//���ն˱��ʽ�� ������
class OrExp : public AbstractExpression
{
public:
	OrExp(AbstractExpression* op1, AbstractExpression* op2);
	virtual ~OrExp(){}
	bool Interpret(Context& aContext);
private:
	AbstractExpression* m_operand1;
	AbstractExpression* m_operand2;
};
//���ն˱��ʽ�� ������
class NotExp:public AbstractExpression
{
public:
	NotExp(AbstractExpression* op);
	virtual ~NotExp(){}
	bool Interpret(Context& aContext);
private:
	AbstractExpression* m_operand;
};

#endif // !defined(AFX_EXPRESSION_H__C5AE2FFA_1A76_4DFA_A3DE_9EB3F7EC9C33__INCLUDED_)
