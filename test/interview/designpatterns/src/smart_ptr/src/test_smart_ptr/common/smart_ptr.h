//file smart_ptr.h
#ifndef __SMART_PTR_H__
#define __SMART_PTR_H__
/***************************************************************************************************
* 1、 File       ： smart_ptr.h
* 2、 Version    ： *.*
* 3、 Description： 智能指针类
* 4、 Author     ： ray 
* 5、 Created    ： 15/6/24 15:54:11
* 6、 History    ： 
* 7、 Remark     ： 从STL memory中提取出来 增加一部分接口 这个仅仅是为了研究而已 用的时候直接用memory的auto_ptr就是了
* 智能指针 优点
* 1、可以只管使用不需要处理释放的问题
* 2、安全处理异常
* 没有处理引用计数
****************************************************************************************************/

#define _COMMON_BEGIN	namespace common {
#define _COMMON_END		}

_COMMON_BEGIN

template<class _Ty>
class smart_ptr;

template<class _Ty>
struct smart_ptr_ref
{
    // explicit构造函数只能被显式调用 不能隐匿调用 explicit关键字只能用在类构造函数
    // proxy reference for smart_ptr copying
    explicit smart_ptr_ref(_Ty *_Right)
        : _Ref(_Right)
    {	// construct from generic pointer to smart_ptr ptr
    }

    _Ty *_Ref;	// generic pointer to smart_ptr ptr
};

template<class _Ty>
class smart_ptr
{
    // wrap an object pointer to ensure destruction
public:
    typedef _Ty element_type;

    // 针对指针构造函数
    explicit smart_ptr(_Ty *_Ptr = 0) _THROW0()
        : _Myptr(_Ptr)
    {
        // construct from object pointer
    }

    // 拷贝构造函数
    smart_ptr(smart_ptr<_Ty>& _Right) _THROW0()
        : _Myptr(_Right.release())
    {
        // construct by assuming pointer from _Right smart_ptr
    }

    // 针对smart_ptr_ref的构造函数
    smart_ptr(smart_ptr_ref<_Ty> _Right) _THROW0()
    {
        // construct by assuming pointer from _Right smart_ptr_ref
        _Ty *_Ptr = _Right._Ref;
        _Right._Ref = 0;	// release old
        _Myptr = _Ptr;	// reset this
    }

    template<class _Other>
    operator smart_ptr<_Other>() _THROW0()
    {
        // convert to compatible smart_ptr
        return (smart_ptr<_Other>(*this));
    }

    template<class _Other>
    operator smart_ptr_ref<_Other>() _THROW0()
    {
        // convert to compatible smart_ptr_ref
        _Other *_Cvtptr = _Myptr;	// test implicit conversion
        smart_ptr_ref<_Other> _Ans(_Cvtptr);
        _Myptr = 0;	// pass ownership to smart_ptr_ref
        return (_Ans);
    }


    // 重载不同类型指针的=等号操作符
    template<class _Other>
    smart_ptr<_Ty>& operator=(smart_ptr<_Other>& _Right) _THROW0()
    {
        // assign compatible _Right (assume pointer)
        reset(_Right.release());
        return (*this);
    }

    // 不同类型指针的构造函数
    template<class _Other>
    smart_ptr(smart_ptr<_Other>& _Right) _THROW0()
        : _Myptr(_Right.release())
    {
        // construct by assuming pointer from _Right
    }

    // 重载等号操作符
    smart_ptr<_Ty>& operator=(smart_ptr<_Ty>& _Right) _THROW0()
    {
        // assign compatible _Right (assume pointer)
        reset(_Right.release());
        return (*this);
    }

    // 重载对于smart_ptr_ref类型的等号操作符
    smart_ptr<_Ty>& operator=(smart_ptr_ref<_Ty> _Right) _THROW0()
    {
        // assign compatible _Right._Ref (assume pointer)
        _Ty *_Ptr = _Right._Ref;
        _Right._Ref = 0;	// release old
        reset(_Ptr);	// set new
        return (*this);
    }

    // 析构函数 退出时销毁对象
    ~smart_ptr()
    {
        // destroy the object
        delete _Myptr;
    }

    // 重载
    _Ty& operator*() const _THROW0()
    {
        // return designated value

#if _HAS_ITERATOR_DEBUGGING
        if (_Myptr == 0)
            _DEBUG_ERROR("smart_ptr not dereferencable");
#endif /* _HAS_ITERATOR_DEBUGGING */

        __analysis_assume(_Myptr);

        return (*get());
    }

    // 重载->
    _Ty *operator->() const _THROW0()
    {
        // return pointer to class object

#if _HAS_ITERATOR_DEBUGGING
        if (_Myptr == 0)
            _DEBUG_ERROR("smart_ptr not dereferencable");
#endif /* _HAS_ITERATOR_DEBUGGING */

        return (get());
    }

    // 获取所引用的对象
    _Ty *get() const _THROW0()
    {
        // return wrapped pointer
        return (_Myptr);
    }

    // 释放对所引用对象的所有权 并返回所引用的对象
    _Ty *release() _THROW0()
    {
        // return wrapped pointer and give up ownership
        _Ty *_Tmp = _Myptr;
        _Myptr = 0;
        return (_Tmp);
    }

    // 销毁指定对象和存储新的指针
    void reset(_Ty* _Ptr = 0)
    {
        // destroy designated object and store new pointer
        if (_Ptr != _Myptr)
            delete _Myptr;
        _Myptr = _Ptr;
    }

private:
    _Ty *_Myptr;	// the wrapped object pointer
};

_COMMON_END
#endif // __SMART_PTR_H__
