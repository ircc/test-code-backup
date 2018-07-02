# [C++基础]034_C++模板编程里的主版本模板类、全特化、偏特化（C++ Type Traits）
============================================================================================

http://www.cnblogs.com/alephsoul-alephsoul/archive/2012/10/18/2728753.html

## 1.  主版本模板类

首先我们来看一段初学者都能看懂，应用了模板的程序：

	#include <iostream>
	using namespace std;
	
	template<class T1, class T2>
	class A{
	public:
		void function(T1 value1, T2 value2){
			cout<<"value1 = "<<value1<<endl;
			cout<<"value2 = "<<value2<<endl;
		}
	};
	int main(){
		A<int, char> a;
		a.function(12, 'b');
	
		system("pause");
		return 0;
	}

程序很简单，一个模板类A，它有一个打印两个参数的函数。我们在main函数里创建了以int，char为类型的类A的对象，调用函数后，得到了我们要的结果：

	value1 = 12
	value2 = b
	请按任意键继续. . .

上面的模板类A，我们通常称作是主版本模板类，它的主要特点是：模板类中所有的类型都是模板类型。


## 2. 全特化

首先我们需要了解一个概念，什么叫特化。特化其实就是特殊化的意思，在模板类里，所有的类型都是模板（template<class T>），而一旦我们将所有的模板类型T都明确化，并且写了一个类名与主模板类名相同的类，那么这个类就叫做全特化类。下面的代码就是全特化的一个演示：

	#include <iostream>
	using namespace std;
	
	template<class T1, class T2>
	class A{
	public:
		void function(T1 value1, T2 value2){
			cout<<"value1 = "<<value1<<endl;
			cout<<"value2 = "<<value2<<endl;
		}
	};
	
	template<>
	class A<int, double>{ // 类型明确化，是个全特化类
		public:
		void function(int value1, double value2){
			cout<<"int value1 = "<<value1<<endl;
			cout<<"double value2 = "<<value2<<endl;
		}
	};

	int main(){
		A<int, double> a;
		a.function(12, 12.21);

		system("pause");
		return 0;
	}

上面代码中着色的部分就是经过全特化的类A，可以看到主版本模板类中的T1和T2已经全部明确化为int和double。接着在main里用“A<int, double> a;”实例化对象时，程序会去调用这个全特化的类。一个类被称为全特化类的条件：1.必须有一个主模板类   2.模板类型被全部明确化。


## 3. 偏特化

上面对主版本模板类和全特化类进行了定义，那么偏特化就是介于二者之间的模板类，它的类名与主版本模板类相同，但是它的模板类型中，有被明确化的部分和没有被明确化的部分。下面就是一段偏特化的演示代码：

	#include <iostream>
	using namespace std;
	
	template<class T1, class T2>
	class A{
	public:
		void function(T1 value1, T2 value2){
		cout<<"value1 = "<<value1<<endl;
		cout<<"value2 = "<<value2<<endl;
		}
	};

	template<class T>
	class A<int, T>{ // 类型部分明确化，是个偏特化类
	public:
		void function(int value1, T value2){
			cout<<"int value1 = "<<value1<<endl;
			cout<<"double value2 = "<<value2<<endl;
		}
	};

	int main(){
		A<int, char> a;
		a.function(12, 'a');
	
		system("pause");
		return 0;
	}

上面代码着色部分就是一个偏特化的模板类，可以看到主版本模板类中的T1和T2中的T1被明确化为int。接着在main里用“A<int, char> a;”实例化对象时，程序会去调用这个偏特化的。一个类被称为偏特化类的条件：1.必须有一个主模板类   2.模板类型被部分明确化。


## 4. 模板类调用优先级

对主版本模板类、全特化类、偏特化类的调用优先级从高到低进行排序是：全特化类>偏特化类>主版本模板类。这样的优先级顺序对性能也是最好的。


## 5. 其他特化类型

在特化的时候，我们将主版本模板类中的模板类型进行特化，按照特化为的类型，我们可以进行一下分类：

	①．绝对类型特化
	
    ②．引用/指针类型特化

    ③．转化为另外一个类模板

下面我们来一个一个研究一下这三种特化：

    ①．绝对类型特化
        所谓绝对类型特化，就是将模板类型T特化为制定的普通数据类型或自定义数据类型。代码如下：

	class MyType{ // 自定义类型
	public:
		char ch;
		MyType(char _ch):ch(_ch){}
	};

	template<class T1, class T2>
	class A{
	public:
		void function(T1 value1, T2 value2){
			cout<<"value1 = "<<value1<<endl;
			cout<<"value2 = "<<value2<<endl;
		}
	};

	template<>
	class A<int, MyType>{ //绝对类型特化，两个模板类型被特化为一个普通类型和一个自定义的数据类型
	public:
		void function(int value1, MyType value2){
			cout<<"int value1 = "<<value1<<endl;
			cout<<"double value2 = "<<value2.ch<<endl;
		}
	};

    ②．引用/指针类型特化
	
	template<class T1, class T2>
	class A{
	public:
		void function(T1 value1, T2 value2){
			cout<<"value1 = "<<value1<<endl;
			cout<<"value2 = "<<value2<<endl;
		}
	};

	template<class T1, class T2>
	class A<T1*, T2*>{ // 指针类型特化
	public:
		void function(T1* pValue1, T2* pValue2){
			cout<<"int value1 = "<<*pValue1<<endl;
			cout<<"double value2 = "<<*pValue2<<endl;
		}
	};
	
	template<class T1, class T2>
	class A<T1&, T2&>{ // 引用类型特化
	public:
		void function(T1& pValue1, T2& pValue2){
			cout<<"int value1 = "<<pValue1<<endl;
			cout<<"double value2 = "<<pValue2<<endl;
		}
	};

    ③．转化为另外一个类模板
	
	template<class T>
	class Number{
	public:
		T value;
		Number(T v):value(v){}
	};

	template<class T1, class T2>
	class A{
	public:
		void function(T1 value1, T2 value2){
			cout<<"value1 = "<<value1<<endl;
			cout<<"value2 = "<<value2<<endl;
		}
	};
	
	template<class T1, class T2>
	class A<Number<T1>, Number<T2>>{ // 模板类型变成另外一个模板类
	public:
		void function(Number<T1> n1, Number<T2> n2){
			cout<<"int value1 = "<<n1.value<<endl;
			cout<<"double value2 = "<<n2.value<<endl;
		}
	};

	
## 6. 结语

当然，本文只是粗浅的让读者理解什么是模板的特化，就深度而言，本文也只是触及皮毛，模板的精妙技巧本文并未涉及，敬请期待。
