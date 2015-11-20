#pragma once

//---这时一个系列的产品基类
class Product
{
protected:
	Product(void);
public:
	virtual ~Product(void);
public:
	virtual void Function() = 0;
};
