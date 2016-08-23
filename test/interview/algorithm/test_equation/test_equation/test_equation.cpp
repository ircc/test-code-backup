// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}

#include<iostream>
#include<math.h>
using namespace std;

void main()
{
    double a,b,c,d,e,x1,x2;
    cout<<"请输入要求解的一元二次方程："<<endl;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    cout<<"c: ";
    cin>>c;
    cout<<a<<"*x*x"<<"+"<<b<<"*x"<<"+"<<c<<"=0"<<endl;

    // 解题过程
    // 1. ax²+bx+c=0左右两边同时乘以4a，得出
    //    4a²x²+4abx+4ac = 0
    // 2. 左右两边同时加上b²，得出
    //    4a²x²+4abx+b²+4ac = b²
    // 3. 得出
    //    （2ax+b）² = b²-4ac 
    // 4. 由于平方值肯定是正的，所以b²-4ac>=0，得出
    //    2ax+b = sqrt(b²-4ac)
    // 5. 得出
    //    x=[sqrt(b²-4ac)-b]/2a
    
    d=b*b-4*a*c;

    // b²-4ac 小于零是无解的
    if(d<0)
    {
        cout<<"There is no x."<<endl;
    }

    // b²-4ac 等于零说明只有一个解
    if(d==0)
    {
        cout<<"There is only x."<<endl;
        x1=x2=(-b)/(2*a);
        cout<<"x1=x2="<<x1<<endl;
    }

    // b²-4ac大于零说明有两个解， 开平方根值有正负两个，而sqrt得出的只有正解
    if(d>0)
    {
        e=sqrt(d);
        x1=(-b+e)/(2*a);
        x2=(-b-e)/(2*a);
        cout<<"x1="<<x1<<endl;
        cout<<"x2="<<x2<<endl;
    }
}


//
//#include<iostream>
//#include<math.h>
//using namespace std;
//
//class funtion
//{
//public:
//    ~funtion(){cout<<"求解完毕"<<endl;}
//    void set_value(); //输入函数
//    void display(); //求解函数
//    void show_value();//输出函数
//private:
//    float a;
//    float b;
//    float c;
//    float x1;
//    float x2;
//    float r;
//    float i;
//    float pd;
//};
//
//void funtion::set_value ()
//{
//    cout<<"输入 a b c 的值且 a b c 不可全为零"<<endl;
//    cin>>a;
//    cin>>b;
//    cin>>c;
//}
//
//void funtion::display ()
//{
//    pd=b*b-4*a*c;
//    if(pd>0)
//    {
//        x1=-b/(2*a)+sqrt(pd)/(2*a);
//        x2=-b/(2*a)-sqrt(pd)/(2*a);
//    }
//    else if(pd==0)
//    {
//        x1=-b/(2*a);
//        x2=-b/(2*a);
//    }
//    else
//    {
//        r=-b/(2*a);
//        i=sqrt(-pd)/(2*a);
//    }
//}
//
//void funtion::show_value ()
//{
//
//    if(pd>0)
//        cout<<"x1="<<x1<<" "<<"x2="<<x2<<endl;
//    else if(pd==0)
//        cout<<"x1="<<x1<<" "<<"x2="<<x2<<endl;
//    else
//        cout<<"x1="<<r<<'+'<<i<<"i"<<" "<<"x2="<<r<<'+'<<i<<"i"<<endl;
//}
//
//int main()
//{
//    funtion f;
//    f.set_value ();
//    f.display ();
//    f.show_value ();
//    return 0;
//}
//
//#include<iostream>
//#include<math.h>
//#include<iomanip.h>
//
//void main()
//{
//    float a,b,c;
//    double x1,x2;
//    cout<<"请输入a，b，c："<<endl;
//    cin>>a>>b>>c;
//    if(a!=0)
//    {
//        if((b*b-4*a*c)>=0)
//        {
//            x1=(-b+sqrt(b*b-4*a*c))/(2*a);
//            x2=(-b-sqrt(b*b-4*a*c))/(2*a);
//            cout<<"x1="<<x1<<setw(5)<<"x2="<<x2<<endl;
//        }
//        else
//            cout<<"无解"<<endl;
//
//    }
//    else
//    {
//        if(b==0)//2个=是判断相等，一个是赋值。
//        {
//            if(c==0)//这里也是一样的。
//                cout<<"x为任意解"<<endl;
//            else
//                cout<<"无解"<<endl;
//        }
//        else
//        { x1=-c/b;
//        x2=-c/b;}
//        cout<<"x1="<<x1<<setw(5)<<"x2="<<x2<<endl;
//
//    }
//
//} 