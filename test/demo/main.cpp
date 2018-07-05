
#include "test.h"

int test_demo()
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

#if 0 
    // 子进程 测试    
    test_child_process();
#endif


#if 0 
    // 管道 测试    
    //test_pipe();
    test_pipe2();
#endif

#if 0
    test_other();
#endif

#if 0
    test_thread_lock();
#endif

#if 1
    test_thread_critical_sections();
#endif

    return 0;
}

#include "test_network.h"

int test_network()
{
#if 0 
    test_tcp_server();
#endif

#if 0 
    test_tcp_client();
#endif

#if 0 
    test_udp_server();
#endif

#if 1 
    test_udp_client();
#endif

    return 0;
}


int main()
{
#if 1 
    // demo 测试    
    test_demo();
#endif

#if 0 
    // network 测试    
    test_network();
#endif

    return 0;
}
