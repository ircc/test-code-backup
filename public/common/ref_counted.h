//file ref_counted.h
#ifndef __REF_COUNTED_H__
#define __REF_COUNTED_H__

/***************************************************************************************************
1、 Function Name ： ref_counted
2、 Description   ： 原子级引用计数
3、 Parameters    ： 
4、 Return Value  ： 
5、 Dynamic memory： 
6、 Author        ：  ray 
7、 Created       ： 15/9/6 14:56:59
8、 Remark        ： 
****************************************************************************************************/

class ref_counted
{
public:
    ref_counted(): _ref_count( 0 ) {}
    virtual ~ref_counted() {}

public:
    UINT addref() { return InterlockedIncrement( &_ref_count );}

    UINT release()
    {
        LONG cnt = InterlockedDecrement( &_ref_count );
        _ASSERT( cnt >= 0 );
        //if ( cnt == 0 )
        //    delete_this();
        return cnt;
    }

    UINT get_refcount()
    {
        InterlockedIncrement( &_ref_count );
        return InterlockedDecrement( &_ref_count );
    }

//protected:
//    virtual void delete_this()
//    {
//        delete this;
//    }

private:
    LONG _ref_count;
};

#endif // __REF_COUNTED_H__
