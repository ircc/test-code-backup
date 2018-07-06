# static_cast、dynamic_cast、reinterpret_cast、const_cast以及C强制类型转换的区别

## static_cast

1. 基础类型之间互转。如：float转成int、int转成unsigned int等

2. 指针与void*之间互转。如：float*转成void*、CBase*转成void*、函数指针转成void*、void*转成CBase*等

3. 派生类指针【引用】转成基类指针【引用】。如：Derive*转成Base*、Derive&转成Base&等

4. 非virtual继承时，可将基类指针【引用】转成派生类指针【引用】（多继承时，会做偏移处理）。如：Base*转成Derive*、Base&转成Derive&等

## dynamic_cast

专门用于处理多态机制，对继承体系内的对象（类中必须含有至少一个虚函数）的指针【引用】进行转换，转换时会进行类型检查；vc在编译时要带上/EHsc /GR

如果能转换会返回对应的指针【引用】；不能转换时，指针会返回空，引用则抛出std::bad_cast异常（const std::bad_cast& e）

注：由于std::bad_cast类型定义在typeinfo头文件中，固需要#include<typeinfo>

另外，对于菱形非virtual继承、非public继承，转换引用时也会抛出std::bad_cast异常

## reinterpret_cast  

对指针【引用】进行原始转换，不做任何偏移处理（当然：多继承时，也不会做偏移处理）

1. 将指针【引用】转换成整型。如：float*转成int、CBase*转成int、float&转成int、CBase&转成int等

float f1 = 1.0f; CBase o1;
int n1 = reinterpret_cast<int>(&f1);
int n2 = reinterpret_cast<int>(&o1);
int n3 = reinterpret_cast<int&>(f1);
int n4 = reinterpret_cast<int&>(o1);

2. 指针【引用】之间互转。如：float*转成int*、CBase&转成int&、CBase*转成CBase2*、CBase&转成CBase2&等

float f1 = 1.0f;  CBase1 o1;
int* n1 = reinterpret_cast<int*>(&f1);
int& n2 = reinterpret_cast<int&>(o1);
CBase2* o21 = reinterpret_cast<CBase2*>(&o1);
CBase2& o22 = reinterpret_cast<CBase2&>(o1);

## const_cast   

去掉或增加const、volatile特性

## C类型强制转换   形式：(type)object或type(object)

最好是使用type(object)；原因是：在某些编译器下，(type)object不会调用构造函数，而type(object)下则肯定会调用构造函数

C类型强制转换会按照以下顺序进行尝试转换：

a. const_cast
b. static_cast
c. static_cast, then const_cast
d. reinterpret_cast
f. reinterpret_cast, then const_cast


## static_cast，const_cast，dynamic_cast，reinterpret_cast区别

### static_cast

用法：static_cast<type-id>(exdivssion) 

该运算符把exdivssion转换为type-id类型，但没有运行时类型检查来保证转换的安全性。它主要有如下几种用法：

* 用于类层次结构中基类和子类之间指针或引用的转换。

　　进行上行转换（把子类的指针或引用转换成基类表示）是安全的；

　　进行下行转换（把基类指针或引用转换成子类表示）时，由于没有动态类型检查，所以是不安全的。

* 用于基本数据类型之间的转换，如把int转换成char，把int转换成enum。这种转换的安全性也要开发人员来保证。

* 把空指针转换成目标类型的空指针。

* 把任何类型的表达式转换成void类型。

注意:static_cast 不能转换掉 exdivssion 的const、volitale、或者__unaligned属性。

msdn官方解释：http://msdn.microsoft.com/en-us/library/c36yw7x9(v=vs.80).aspx


### const_cast 

用法：const_cast<type-id> (exdivssion)

该运算符用来修改类型的const、volatile、__unaligned属性。除了const 、volatile、__unaligned修饰之外， type_id和exdivssion的类型是一样的。

常量指针被转化成非常量指针，并且仍然指向原来的对象；

常量引用被转换成非常量引用，并且仍然指向原来的对象；常量对象被转换成非常量对象。

msdn官方解释：http://msdn.microsoft.com/en-us/library/bz6at95h(v=vs.80).aspx


### dynamic_cast

用法:dynamic_cast<type-id>(exdivssion)

该运算符把exdivssion转换成type-id类型的对象。Type-id必须是类的指针、类的引用或者void*；

如果type-id是类指针类型，那么exdivssion也必须是一个指针，如果type-id是一个引用，那么exdivssion也必须是一个引用。

dynamic_cast主要用于类层次间的上行转换和下行转换，还可以用于类之间的交叉转换。

在类层次间进行上行转换时，dynamic_cast和static_cast 的效果是一样的；

在进行下行转换时，dynamic_cast具有类型检查的功能，比static_cast 更安全。

msdn官方解释：http://msdn.microsoft.com/en-us/library/cby9kycs(v=vs.80).aspx


### reinterpret_cast

用法：reinterpret_cast<type-id>(exdivssion)

reinterpret_cast运算符是用来处理无关类型之间的转换；它会产生一个新的值，这个值会有与原始参数（expressoin）有完全相同的比特位。按照reinterpret的字面意思“重新解释”，即对数据的比特位重新解释。

IBM的C++指南 里明确告诉了我们reinterpret_cast可以，或者说应该在什么地方用来作为转换运算符：

    从指针类型到一个足够大的整数类型
    从整数类型或者枚举类型到指针类型
    从一个指向函数的指针到另一个不同类型的指向函数的指针
    从一个指向对象的指针到另一个不同类型的指向对象的指针
    从一个指向类函数成员的指针到另一个指向不同类型的函数成员的指针
    从一个指向类数据成员的指针到另一个指向不同类型的数据成员的指针

总结来说：reinterpret_cast用在任意指针（或引用）类型之间的转换；以及指针与足够大的整数类型之间的转换；从整数类型（包括枚举类型）到指针类型，无视大小。

注意：static_cast 不能转换掉exdivssion的const、volitale、或者__unaligned属性。

msdn官方解释：http://msdn.microsoft.com/en-us/library/e0w9f63b(v=vs.80).aspx