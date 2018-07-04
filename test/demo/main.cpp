
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


#if 0
    // semaphore 测试    
    test_semaphore();
#endif

#if 0
    // mutex 测试    
    test_mutex();
#endif

#if 0
    // 临界区critical sections 测试    
    test_critical_sections();
#endif

#if 1 
    // 子进程 测试    
    test_child_process();
#endif

    return 0;
}

