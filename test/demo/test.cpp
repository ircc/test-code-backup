#include "test.h"

int testA::Add(int a, int b)
{
    return a + b;
}

int testA::Red(int a, int b)
{
    return a - b;
}

int testA::Mul(int a, int b)
{
    return a * b;
}

int testA::Dvi(int a, int b)
{
    if (0 == b)
    {
        return -1;
    }
    return a / b;
}

void testA::Fun()
{
    std::cout << "testA Running" << endl;
}

void testB::Fun()
{
    std::cout << "testB is Running" << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void *thread_function(void *arg)
{
    long my_number = reinterpret_cast<long>(arg);
    int rand_num;

    printf("thread_function is running. Argument was %ld\n", my_number);
    rand_num = 1 + (int)(9.0 * rand() / (RAND_MAX + 1.0));
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

void *semaphore_thread_function(void *)
{
    sem_wait(&sem);
    while (strncmp("end", buffer, 3) != 0)
    {
        printf("You input %lu characters\n", strlen(buffer));
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

    printf("\nWaiting for thread to finish...\n");

    res = pthread_join(a_thread, &thread_result);
    if (res != 0)
    {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }

    printf("Thread join\n");

    sem_destroy(&sem);

    exit(EXIT_SUCCESS);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int i = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; /*初始化互斥锁*/
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;    /*初始化条件变量*/

void *thread1(void *)
{
    for (i = 1; i <= 3; i++)
    {
        pthread_mutex_lock(&mutex); /*锁住互斥量*/
        if (i % 3 == 0)
            pthread_cond_signal(&cond); /*条件改变，发送信号，通知t_b进程*/
        else
            printf("thead1:%d\n", i);
        pthread_mutex_unlock(&mutex); /*解锁互斥量*/
        sleep(1);
    }
    pthread_exit(NULL);
}

void *thread2(void *)
{
    while (i < 9)
    {
        pthread_mutex_lock(&mutex);
        if (i % 3 != 0)
            pthread_cond_wait(&cond, &mutex); /*等待*/
        printf("thread2:%d\n", i);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}

int test_mutex(void)
{
    pthread_t t_a;
    pthread_t t_b;

    pthread_create(&t_a, NULL, thread2, (void *)NULL); /*创建进程t_a*/
    pthread_create(&t_b, NULL, thread1, (void *)NULL); /*创建进程t_b*/
    pthread_join(t_b, NULL);                           /*等待进程t_b结束*/
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
    if (semctl(sem_id, 0, SETVAL, sem_union) == -1)
        return 0;
    return 1;
}

static void del_semvalue()
{
    //删除信号量
    union semun sem_union;

    if (semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
        fprintf(stderr, "Failed to delete semaphore\n");
}

static int semaphore_p()
{
    //对信号量做减1操作，即等待P（sv）
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = -1; //P()
    sem_b.sem_flg = SEM_UNDO;
    if (semop(sem_id, &sem_b, 1) == -1)
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
    sem_b.sem_op = 1; //V()
    sem_b.sem_flg = SEM_UNDO;
    if (semop(sem_id, &sem_b, 1) == -1)
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
    if (!set_semvalue())
    {
        fprintf(stderr, "Failed to initialize semaphore\n");
        exit(EXIT_FAILURE);
    }
    //设置要输出到屏幕中的信息，即其参数的第一个字符

    for (i = 0; i < 10; ++i)
    {
        //进入临界区
        if (!semaphore_p())
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
        if (!semaphore_v())
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

    if (pipe(filedes) == 0)
    {
        //创建管道成功
        //通过调用fork创建子进程
        pid = fork();
        if (pid == -1)
        {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
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

int test_pipe()
{
    const char *fifo_name = "/tmp/my_fifo";
    int pipe_fd = -1;
    int data_fd = -1;
    int res = 0;
    const int open_mode = O_WRONLY;
    int bytes_sent = 0;
    char buffer[PIPE_BUF + 1] = "Hello World!";

    if (access(fifo_name, F_OK) == -1)
    {
        //管道文件不存在
        //创建命名管道
        res = mkfifo(fifo_name, 0777);
        if (res != 0)
        {
            fprintf(stderr, "Could not create fifo %s\n", fifo_name);
            exit(EXIT_FAILURE);
        }
    }

    printf("Process %d opening FIFO O_WRONLY\n", getpid());
    //以只写阻塞方式打开FIFO文件，以只读方式打开数据文件
    pipe_fd = open(fifo_name, open_mode);

    printf("Process %d result %d\n", getpid(), pipe_fd);

    if (pipe_fd != -1)
    {
        int bytes_read = 0;
        //向数据文件读取数据
        bytes_read = strlen(buffer);
        buffer[bytes_read] = '\0';
        while (bytes_read > 0)
        {
            //向FIFO文件写数据
            res = write(pipe_fd, buffer, bytes_read);
            if (res == -1)
            {
                fprintf(stderr, "Write error on pipe\n");
                exit(EXIT_FAILURE);
            }
            //累加写的字节数，并继续读取数据
            bytes_sent += res;
            bytes_read = read(data_fd, buffer, PIPE_BUF);
            buffer[bytes_read] = '\0';
        }
        close(pipe_fd);
        close(data_fd);
    }
    else
        exit(EXIT_FAILURE);

    printf("Process %d finished\n", getpid());
    exit(EXIT_SUCCESS);
}

int test_pipe2()
{
    const char *fifo_name = "/tmp/my_fifo";
    int pipe_fd = -1;
    int data_fd = -1;
    int res = 0;
    int open_mode = O_RDONLY;
    char buffer[PIPE_BUF + 1];
    int bytes_read = 0;
    int bytes_write = 0;
    //清空缓冲数组
    memset(buffer, '\0', sizeof(buffer));

    printf("Process %d opening FIFO O_RDONLY\n", getpid());
    //以只读阻塞方式打开管道文件，注意与fifowrite.c文件中的FIFO同名
    pipe_fd = open(fifo_name, open_mode);
    //以只写方式创建保存数据的文件
    data_fd = open("DataFormFIFO.txt", O_WRONLY | O_CREAT, 0644);
    printf("Process %d result %d\n", getpid(), pipe_fd);

    if (pipe_fd != -1)
    {
        do
        {
            //读取FIFO中的数据，并把它保存在文件DataFormFIFO.txt文件中
            res = read(pipe_fd, buffer, PIPE_BUF);
            bytes_write = write(data_fd, buffer, res);
            printf("%s\n", buffer);
            bytes_read += res;
        } while (res > 0);
        close(pipe_fd);
        close(data_fd);
    }
    else
        exit(EXIT_FAILURE);

    printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);
    exit(EXIT_SUCCESS);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int add(int a, int b)
{
    return a + b;
}

void test_add()
{
    int sum[10] =
        {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i;

    int array1[10] =
        {
            48, 56, 77, 33, 33, 11, 226, 544, 78, 90};
    int array2[10] =
        {
            85, 99, 66, 0x199, 393, 11, 1, 2, 3, 4};

    for (i = 0; i < 10; i++)
    {
        sum[i] = add(array1[i], array2[i]);
    }
}

int test_other()
{
    test_add();

    time_t timer = time(NULL);
    printf("ctime is %s\n", ctime(&timer)); //得到日历时间


    return 0;     
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int tmp;
void* thread(void *)
{
    cout << "thread id is " << pthread_self() << endl;
    pthread_mutex_lock(&mutex1);
    tmp = 12;
    cout << "Now a is " << tmp << endl;
    pthread_mutex_unlock(&mutex1);
    
    pthread_exit(NULL);
}

int test_thread_lock()
{
    pthread_t id;
    cout << "main thread id is " << pthread_self() << endl;
    tmp = 3;
    cout << "In main func tmp = " << tmp << endl;
    if (!pthread_create(&id, NULL, thread, NULL))
    {
        cout << "Create thread success!" << endl;
    }
    else
    {
        cout << "Create thread failed!" << endl;
    }
    pthread_join(id, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;

struct node
{
    int n_number;
    struct node *n_next;
}*head = NULL;

static void cleanup_handler(void *arg)
{
    printf("Cleanup handler of second thread.\n");
    free(arg);
    (void)pthread_mutex_unlock(&mtx);
}

static void *thread_func(void *)
{
    struct node *p = NULL;
    pthread_cleanup_push(cleanup_handler, p);
    while (1)
    {
        //这个mutex主要是用来保证pthread_cond_wait的并发性
        pthread_mutex_lock(&mtx);
        while (head == NULL)
        // if (head == NULL)
        {
            //这个while要特别说明一下，单个pthread_cond_wait功能很完善，为何
            //这里要有一个while (head == NULL)呢？因为pthread_cond_wait里的线
            //程可能会被意外唤醒，如果这个时候head != NULL，则不是我们想要的情况。
            //这个时候，应该让线程继续进入pthread_cond_wait
            // pthread_cond_wait会先解除之前的pthread_mutex_lock锁定的mtx，
            //然后阻塞在等待对列里休眠，直到再次被唤醒(大多数情况下是等待的条件成立
            //而被唤醒，唤醒后，该进程会先锁定先pthread_mutex_lock(&mtx);，再读取资源
            //用这个流程是比较清楚的
            pthread_cond_wait(&cond, &mtx);
            p = head;
            head = head->n_next;
            printf("Got %d from front of queue\n", p->n_number);
            free(p);
        }
        pthread_mutex_unlock(&mtx); //临界区数据操作完毕，释放互斥锁
    }
    pthread_cleanup_pop(0);
    return 0;
}

int test_thread_critical_sections(void)
{
    pthread_t tid;
    int i;
    struct node *p;
    //子线程会一直等待资源，类似生产者和消费者，但是这里的消费者可以是多个消费者，而
    //不仅仅支持普通的单个消费者，这个模型虽然简单，但是很强大
    pthread_create(&tid, NULL, thread_func, NULL);
    sleep(1);
    for (i = 0; i < 10; i++)
    {
        p = (struct node*)malloc(sizeof(struct node));
        p->n_number = i;
        pthread_mutex_lock(&mtx); //需要操作head这个临界资源，先加锁，
        p->n_next = head;
        head = p;
        pthread_cond_signal(&cond2);
        pthread_mutex_unlock(&mtx); //解锁
        sleep(1);
    }
    printf("thread 1 wanna end the line.So cancel thread 2.\n");
    //关于pthread_cancel，有一点额外的说明，它是从外部终止子线程，子线程会在最近的取消点，退出
    //线程，而在我们的代码里，最近的取消点肯定就是pthread_cond_wait()了。
    pthread_cancel(tid);
    pthread_join(tid, NULL);
    printf("All done -- exiting\n");
    return 0;
}
