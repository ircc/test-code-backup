// Context.h: interface for the Context class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTEXT_H__337390AD_A5A0_4417_A130_C067567C168D__INCLUDED_)
#define AFX_CONTEXT_H__337390AD_A5A0_4417_A130_C067567C168D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class State; /** * **/ 

class Context
{
public:
	Context();
	Context(State* state);
	~Context();
	//�˷�������״̬���ܵ����л���һ��
	void OprationInterface();
	//�˷�������״̬�����л���һ������
	void OperationChangStateLarge();
    //�˷�������״̬�����л���һ����С��
    void OperationChangStateSmall();
protected:
private:
	friend class State; //������State���п��Է���Context���private�ֶ�
	bool ChangeState(State* state);//��������״̬
private:
	State* _state;
};

#endif // !defined(AFX_CONTEXT_H__337390AD_A5A0_4417_A130_C067567C168D__INCLUDED_)
