// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class A
{


};


int _tmain(int argc, _TCHAR* argv[])
{
    A b;
    const A a = b;

    A* d = new A();
    const A* c1 = d;
    const A* c2 = new A();
    A f;
    const A& e1 = f;   // 这样作e只能访问声明为const的函数，而不能访问一般的成员函数；

    //[思考1]： 以下的这种赋值方法正确吗？
    const A* c3 = new A();
    //A* e2 = c3;    //“初始化”: 无法从“const A *”转换为“A *”

    //[思考2]： 以下的这种赋值方法正确吗？    
    A* const c4 = new A();
    //A* b = c4;    //“b”: “A *”与“A”的间接寻址级别不同


    // const <类型> *<指针变量名>
    // 该语句的作用是：定义指针变量所指数据值为常量，即：指针变量所指数据值不能改变，但指针变量值可以改变。例如:

    float x = 0, y = 0;
    const float *p = &x; //定义指针变量p所指数据值*p为常量
    //*p = 25;             //错误，p所指变量x数据值不能用*p形式进行改变
    p = &y;              //正确，可改指针变量p的值
    x = 25;              //正确，变量x的值可以改变  


    // <类型> * const <指针变量名>
    // 该语句的作用是：定义指针变量值为常量，即：指针变量值不能改变，但指针变量所指数据值可以改变。例如：

    float x1 = 0,y1 = 0;
    float * const p1 = &x1; //定义指针变量p的值为常量
    *p1 = 25;               //正确，p所指变量x数据值可以用*p形式进行改变
    //p1 = &y1;                //错误，指针变量p的值不能改变


    // const <类型> * const <指针变量名>
    // 该语句的作用是：定义指针变量值为常量，指针变量所指数据值为常量。即：指针变量值不能改变，指针变量所指数据值也不能改变。例如：

    float x2 = 0, y2 = 0;
    const float * const p2 = &x2; //定义指针变量p为常量
    //*p2 = 25;                    //错误，p所指变量x数据值不能用*p形式进行改变
    //p2 = &y2;                     //错误，不能改变指针变量p的值


	return 0;
}

