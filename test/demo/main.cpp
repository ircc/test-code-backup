
#include "test.h"

int main()
{
#if 0 
    // virtual 测试    
    testA *p = new testB;
    p->Fun();
    cout << "Hello World!" << endl;
#endif

#if 0 
    // thread 测试    
    test_thread();
#endif


#if 1 
    // semaphore 测试    
    test_semaphore();
#endif

    return 0;
}

