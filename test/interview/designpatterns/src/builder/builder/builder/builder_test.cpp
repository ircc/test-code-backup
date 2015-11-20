// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}


#include "builder.h"
#include "builder2.h"
#include "builder3.h"
#include <iostream>

using namespace std;

//builder.h
int main1()
{
    Director* pDirector = new Director(new ConcreteBuilder1());
    pDirector->Construct();

    Director* pDirector1 = new Director(new ConcreteBuilder2());
    pDirector1->Construct();

    return 0;
}

//builder2
int main2()
{
    FoodManager *p = new FoodManager();
    char ch;
    //客户到来，输入需要哪种套餐
    for(int i=0;i<5;i++)
    {
        cin>>ch;
        p->FoodInfo(ch)->show();
        cout<<endl;
    }
    system("pause");
    return 0;
}


//builder3
int main()
{
    Director3* pclsdirector = new Director3();
    Product3* pclsproduct1 = pclsdirector->getAProduct();
    pclsproduct1->showProduct();

    Product3* pclsproduct2 = pclsdirector->getBProduct();
    pclsproduct2->showProduct();
 
    return 0;
}
