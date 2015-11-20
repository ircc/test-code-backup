// Bridge_exam2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Coffee.h"
#include "CoffeeImp.h"

int main(int argc, char* argv[])
{
	//���ü�ţ��
	CoffeeImpSingleton::getCoffeeImpSingleton()->setCoffeeImp(new MilkCoffeeImp());
	//�����б�����
	MediumCoffee mediumCoffee1;SuperSizeCoffee superSizeCoffee1;
	mediumCoffee1.pourCoffee();superSizeCoffee1.pourCoffee();
    //���ò���ţ��
	CoffeeImpSingleton::getCoffeeImpSingleton()->setCoffeeImp(new FragrantCoffeeImp());
	//�����б�����
	MediumCoffee mediumCoffee2;SuperSizeCoffee superSizeCoffee2;
	mediumCoffee2.pourCoffee();superSizeCoffee2.pourCoffee();
	return 0;
}

