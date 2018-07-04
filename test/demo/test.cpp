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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void* thread_function(void *arg)
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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define SIZE 1024

char buffer[SIZE];
sem_t sem;

void* semaphore_thread_function(void*)
{
    sem_wait(&sem);
    while (strncmp("end", buffer, 3) != 0)
    {
        printf("You input %u characters\n", strlen(buffer));
        sem_wait(&sem);
    }
    pthread_exit(NULL);
}

int test_semaphore()
{
    int res;
    pthread_t a_thread;
    void *thread_result;

    res = sem_init(&sem, 0, 0);
    if (res != 0)
    {
        perror("Sem init failed");
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&a_thread, NULL, semaphore_thread_function, NULL);
    if (res != 0)
    {
        perror("Thread create failed");
        exit(EXIT_FAILURE);
    }

    printf("Input some text. Enter 'end' to finish\n");

    while (scanf("%s", buffer))
    {
        sem_post(&sem);
        if (strncmp("end", buffer, 3) == 0)
            break;
    }

    printf ("\nWaiting for thread to finish...\n");

    res = pthread_join(a_thread, &thread_result);
    if (res != 0)
    {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }

    printf ("Thread join\n");

    sem_destroy(&sem);

    exit(EXIT_SUCCESS);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int i=1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; /*初始化互斥锁*/
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;    /*初始化条件变量*/

void *thread1(void*)
{
    for(i=1;i<=3;i++)
    {
        pthread_mutex_lock(&mutex);/*锁住互斥量*/
        if(i%3==0)
            pthread_cond_signal(&cond);/*条件改变，发送信号，通知t_b进程*/
        else
            printf("thead1:%d\n",i);
        pthread_mutex_unlock(&mutex);/*解锁互斥量*/
        sleep(1);
    }
}

void *thread2(void*)
{
    while(i<9)
    {
        pthread_mutex_lock(&mutex);
        if(i%3!=0)
            pthread_cond_wait(&cond,&mutex);/*等待*/
        printf("thread2:%d\n",i);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int test_mutex(void)
{
    pthread_t t_a;
    pthread_t t_b;

    pthread_create(&t_a,NULL,thread2,(void *)NULL);/*创建进程t_a*/
    pthread_create(&t_b,NULL,thread1,(void *)NULL); /*创建进程t_b*/
    pthread_join(t_b, NULL);/*等待进程t_b结束*/
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    exit(0);
}