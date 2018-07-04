#include "test.h"

int testA::Add(int a, int b)
{
    return a + b;
}

int testA::Red(int a,int b)
{
    return a - b;
}

int testA::Mul(int a,int b)
{
    return a * b;
}

int testA::Dvi(int a, int b)
{
    if(0 == b)
    {
        return -1;
    }
    return a / b;
}

void testA::Fun()
{
    std::cout<< "testA Running" <<endl;
}

void testB::Fun()
{
    std::cout << "testB is Running"<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void *thread_function(void *arg)
{
    long my_number = reinterpret_cast<long>(arg);
    int rand_num;

    printf("thread_function is running. Argument was %ld\n", my_number);
    rand_num = 1 + (int)(9.0 * rand()/(RAND_MAX + 1.0));
    sleep(rand_num);
    printf("Bye from %ld\n", my_number);
    pthread_exit(NULL);
}

int test_thread()
{
    int res;
    pthread_t a_thread[NUM];
    void *thread_result;
    int index;

    for (index = 0; index < NUM; ++index)
    {
        res = pthread_create(&a_thread[index], NULL, thread_function, (void *)index);
        if (res != 0)
        {
            perror("Thread create failed!");
            exit(EXIT_FAILURE);
        }
        sleep(1);
    }

    printf("Waiting for threads to finished...\n");

    for (index = NUM - 1; index >= 0; --index)
    {
        res = pthread_join(a_thread[index], &thread_result);
        if (res == 0)
        {
            printf("Picked up a thread:%d\n", index + 1);
        }
        else
        {
            perror("pthread_join failed\n");
        }
    }

    printf("All done\n");

    exit(EXIT_SUCCESS);
}