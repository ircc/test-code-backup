//file singleton.h
#ifndef __SINGLETON_H__
#define __SINGLETON_H__
/***************************************************************************************************
* 1、 File       ： singleton.h
* 2、 Version    ： 单实例模式模板类
* 3、 Description： 
* 4、 Author     ： ray 
* 5、 Created    ： 15/9/6 15:06:00
* 6、 History    ： 
* 7、 Remark     ： 单例模式是一种常用的软件设计模式。
*                   在它的核心结构中只包含一个被称为单例类的特殊类。
*                   通过单例模式可以保证系统中一个类只有一个实例而且该实例易于外界访问，从而方便对实例个数的控制并节约系统资源。
*                   如果希望在系统中某个类的对象只能存在一个，单例模式是最好的解决方案。
****************************************************************************************************/

namespace COMMON
{
    template <typename _Ty>
    class Singleton
    {
    public:
        Singleton() {}
        virtual ~Singleton() {}

    public:
        static _Ty* getInstance()
        {
            static _Ty t;
            return &t;
        }

    private:
        // explicit构造函数只能被显式调用 不能隐匿调用 explicit关键字只能用在类构造函数
        Singleton(_Ty const &);                                            // 禁用拷贝构造函数    explicit不需要因为拷贝构造未实现所以隐式的也不需要禁用了
        _Ty& operator=(_Ty const &) const;                                 // 重载＝运算符，以禁用＝赋值
    };
}

#endif // __SINGLETON_H__