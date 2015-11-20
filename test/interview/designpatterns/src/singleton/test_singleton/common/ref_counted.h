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

#include <Windows.h>
#include <crtdbg.h>

namespace COMMON
{
    class ref_counted
    {
    public:
        ref_counted(): _ref_count( 0 ) {}
        virtual ~ref_counted() {}

    public:
        unsigned int addref() { return InterlockedIncrement( &_ref_count );}

        unsigned int release()
        {
            long lcnt = InterlockedDecrement( &_ref_count );
            _ASSERT( lcnt >= 0 );
            //if ( lcnt == 0 )
            //    delete_this();
            return lcnt;
        }

        unsigned int get_refcount()
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
        long _ref_count;
    };
}

#endif // __REF_COUNTED_H__
