#ifndef TEST_H
#define TEST_H
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// virtual
class testA
{
public:
    testA(){};
    virtual ~testA(){};

public:
    int Add(int a,int b);
    int Red(int a,int b);
    int Mul(int a,int b);
    int Dvi(int a,int b);

    virtual void Fun() ;
};

class testB : public testA
{
public:
    testB(){};
    ~testB(){};

public:
    virtual void Fun();
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// thread
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

#define NUM 6

void* thread_function(void *arg);
int test_thread();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Semaphore
// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>
#include <string.h>
#include <semaphore.h>


void* semaphore_thread_function(void *arg);
int test_semaphore();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// mutex
// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include<unistd.h>

void* thread1(void *);
void* thread2(void *);

int test_mutex(void);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
#include <sys/sem.h>

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *arry;
};

static int set_semvalue();
static void del_semvalue();
static int semaphore_p();
static int semaphore_v();

int test_critical_sections();


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int test_child_process();


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // TEST_H
