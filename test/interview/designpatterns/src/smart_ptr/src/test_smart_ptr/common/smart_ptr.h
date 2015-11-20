//file smart_ptr.h
#ifndef __SMART_PTR_H__
#define __SMART_PTR_H__
/***************************************************************************************************
* 1�� File       �� smart_ptr.h
* 2�� Version    �� *.*
* 3�� Description�� ����ָ����
* 4�� Author     �� ray 
* 5�� Created    �� 15/6/24 15:54:11
* 6�� History    �� 
* 7�� Remark     �� ��STL memory����ȡ���� ����һ���ֽӿ� ���������Ϊ���о����� �õ�ʱ��ֱ����memory��auto_ptr������
* ����ָ�� �ŵ�
* 1������ֻ��ʹ�ò���Ҫ�����ͷŵ�����
* 2����ȫ�����쳣
* û�д������ü���
****************************************************************************************************/

#define _COMMON_BEGIN	namespace common {
#define _COMMON_END		}

_COMMON_BEGIN

template<class _Ty>
class smart_ptr;

template<class _Ty>
struct smart_ptr_ref
{
    // explicit���캯��ֻ�ܱ���ʽ���� ����������� explicit�ؼ���ֻ�������๹�캯��
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

    // ���ָ�빹�캯��
    explicit smart_ptr(_Ty *_Ptr = 0) _THROW0()
        : _Myptr(_Ptr)
    {
        // construct from object pointer
    }

    // �������캯��
    smart_ptr(smart_ptr<_Ty>& _Right) _THROW0()
        : _Myptr(_Right.release())
    {
        // construct by assuming pointer from _Right smart_ptr
    }

    // ���smart_ptr_ref�Ĺ��캯��
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


    // ���ز�ͬ����ָ���=�ȺŲ�����
    template<class _Other>
    smart_ptr<_Ty>& operator=(smart_ptr<_Other>& _Right) _THROW0()
    {
        // assign compatible _Right (assume pointer)
        reset(_Right.release());
        return (*this);
    }

    // ��ͬ����ָ��Ĺ��캯��
    template<class _Other>
    smart_ptr(smart_ptr<_Other>& _Right) _THROW0()
        : _Myptr(_Right.release())
    {
        // construct by assuming pointer from _Right
    }

    // ���صȺŲ�����
    smart_ptr<_Ty>& operator=(smart_ptr<_Ty>& _Right) _THROW0()
    {
        // assign compatible _Right (assume pointer)
        reset(_Right.release());
        return (*this);
    }

    // ���ض���smart_ptr_ref���͵ĵȺŲ�����
    smart_ptr<_Ty>& operator=(smart_ptr_ref<_Ty> _Right) _THROW0()
    {
        // assign compatible _Right._Ref (assume pointer)
        _Ty *_Ptr = _Right._Ref;
        _Right._Ref = 0;	// release old
        reset(_Ptr);	// set new
        return (*this);
    }

    // �������� �˳�ʱ���ٶ���
    ~smart_ptr()
    {
        // destroy the object
        delete _Myptr;
    }

    // ����
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

    // ����->
    _Ty *operator->() const _THROW0()
    {
        // return pointer to class object

#if _HAS_ITERATOR_DEBUGGING
        if (_Myptr == 0)
            _DEBUG_ERROR("smart_ptr not dereferencable");
#endif /* _HAS_ITERATOR_DEBUGGING */

        return (get());
    }

    // ��ȡ�����õĶ���
    _Ty *get() const _THROW0()
    {
        // return wrapped pointer
        return (_Myptr);
    }

    // �ͷŶ������ö��������Ȩ �����������õĶ���
    _Ty *release() _THROW0()
    {
        // return wrapped pointer and give up ownership
        _Ty *_Tmp = _Myptr;
        _Myptr = 0;
        return (_Tmp);
    }

    // ����ָ������ʹ洢�µ�ָ��
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
