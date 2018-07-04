
#include "test.h"

int main()
{
#if 0 
    // virtual 测试    
    testA *p = new testB;
    p->Fun();
    cout << "Hello World!" << endl;
#endif

#if 1 
    // thread 测试    
    test_thread();
#endif
    return 0;
}

