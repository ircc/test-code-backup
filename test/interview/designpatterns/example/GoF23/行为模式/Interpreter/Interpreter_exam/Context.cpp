// Context.cpp: implementation of the Context class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Context.h"
#include "Expression.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Context::Context(){}
Context::~Context(){}

bool Context::Lookup(const char* name) const
{
	return m_varMap.find(name)->second;
}
//�γɱ����ڲ����ƺ�ֵ��ӳ��
void Context::Assign(VariableExp* ve,bool b)
{
	m_varMap.insert(str_bool(ve->m_name, b));
}