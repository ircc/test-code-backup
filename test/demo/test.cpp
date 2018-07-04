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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static int sem_id = 0;

static int set_semvalue()
{
    //用于初始化信号量，在使用信号量前必须这样做
    union semun sem_union;

    sem_union.val = 1;
    if(semctl(sem_id, 0, SETVAL, sem_union) == -1)
        return 0;
    return 1;
}

static void del_semvalue()
{
    //删除信号量
    union semun sem_union;

    if(semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
        fprintf(stderr, "Failed to delete semaphore\n");
}

static int semaphore_p()
{
    //对信号量做减1操作，即等待P（sv）
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = -1;//P()
    sem_b.sem_flg = SEM_UNDO;
    if(semop(sem_id, &sem_b, 1) == -1)
    {
        fprintf(stderr, "semaphore_p failed\n");
        return 0;
    }
    return 1;
}

static int semaphore_v()
{
    //这是一个释放操作，它使信号量变为可用，即发送信号V（sv）
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = 1;//V()
    sem_b.sem_flg = SEM_UNDO;
    if(semop(sem_id, &sem_b, 1) == -1)
    {
        fprintf(stderr, "semaphore_v failed\n");
        return 0;
    }
    return 1;
}

int test_critical_sections()
{
    char message = 'X';
    int i = 0;

    //创建信号量
    sem_id = semget((key_t)1234, 1, 0666 | IPC_CREAT);


        //程序第一次被调用，初始化信号量
        if(!set_semvalue())
        {
            fprintf(stderr, "Failed to initialize semaphore\n");
            exit(EXIT_FAILURE);
        }
        //设置要输出到屏幕中的信息，即其参数的第一个字符


    for(i = 0; i < 10; ++i)
    {
        //进入临界区
        if(!semaphore_p())
            exit(EXIT_FAILURE);
        //向屏幕中输出数据
        printf("%c\n", message);
        //清理缓冲区，然后休眠随机时间
        fflush(stdout);
        sleep(rand() % 3);
        //离开临界区前再一次向屏幕输出数据
        printf("%c\n", message);
        fflush(stdout);
        //离开临界区，休眠随机时间后继续循环
        if(!semaphore_v())
            exit(EXIT_FAILURE);
        sleep(rand() % 2);
    }

    sleep(10);
    printf("\n%d - finished\n", getpid());


        //如果程序是第一次被调用，则在退出前删除信号量
        sleep(3);
        del_semvalue();

    exit(EXIT_SUCCESS);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int test_child_process()
{
    int data_processed = 0;
    int filedes[2];
    const char data[] = "Hello pipe!";
    char buffer[BUFSIZ + 1];
    pid_t pid;
    //清空缓冲区
    memset(buffer, '\0', sizeof(buffer));

    if(pipe(filedes) == 0)
    {
        //创建管道成功
        //通过调用fork创建子进程
        pid = fork();
        if(pid == -1)
        {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }
        if(pid == 0)
        {
            //子进程中
            //读取数据
            data_processed = read(filedes[0], buffer, BUFSIZ);
            printf("Read %d bytes: %s\n", data_processed, buffer);
            exit(EXIT_SUCCESS);
        }
        else
        {
            //父进程中
            //写数据
            data_processed = write(filedes[1], data, strlen(data));
            printf("Wrote %d bytes: %s\n", data_processed, data);
            //休眠2秒，主要是为了等子进程先结束，这样做也只是纯粹为了输出好看而已
            //父进程其实没有必要等等子进程结束
            sleep(2);
            exit(EXIT_SUCCESS);
        }
    }
    exit(EXIT_FAILURE);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////