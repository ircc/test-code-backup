#pragma once

//---��ʱһ��ϵ�еĲ�Ʒ����
class Product
{
protected:
	Product(void);
public:
	virtual ~Product(void);
public:
	virtual void Function() = 0;
};
