#include "test_network.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int test_tcp_server()
{
    int server_sockfd = -1;
    int client_sockfd = -1;
    int client_len = 0;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    //创建流套接字
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    //设置服务器接收的连接地址和监听的端口
    server_addr.sin_family = AF_INET;//指定网络套接字
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//接受所有IP地址的连接
    server_addr.sin_port = htons(9736);//绑定到9736端口
    //绑定（命名）套接字
    bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    //创建套接字队列，监听套接字
    listen(server_sockfd, 5);
    //忽略子进程停止或退出信号
    signal(SIGCHLD, SIG_IGN);

    while(1)
    {
        char ch = '\0';
        client_len = sizeof(client_addr);
        printf("Server waiting\n");
        //接受连接，创建新的套接字
        client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_addr, (socklen_t*)&client_len);

        if(fork() == 0)
        {
            //子进程中，读取客户端发过来的信息，处理信息，再发送给客户端
            read(client_sockfd, &ch, 1);
            printf("char form server = %c\n", ch);
            sleep(5);
            ch++;
            write(client_sockfd, &ch, 1);
            close(client_sockfd);
            exit(0);
        }
        else
        {
            //父进程中，关闭套接字
            close(client_sockfd);
        }
    }
}

int test_tcp_client()
{
    int sockfd = -1;
    int len = 0;
    struct sockaddr_in address;
    int result;
    char ch = 'A';
    //创建流套接字
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    //设置要连接的服务器的信息
    address.sin_family = AF_INET;//使用网络套接字
    address.sin_addr.s_addr = inet_addr("127.0.0.1");//服务器地址
    address.sin_port = htons(9736);//服务器所监听的端口
    len = sizeof(address);
    //连接到服务器
    result = connect(sockfd, (struct sockaddr*)&address, len);

    if(result == -1)
    {
        perror("ops:client\n");
        exit(1);
    }
    //发送请求给服务器
    write(sockfd, &ch, 1);
    //从服务器获取数据
    read(sockfd, &ch, 1);
    printf("char form server = %c\n", ch);
    close(sockfd);
    exit(0);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int test_udp_server()
{
    int server_sockfd = -1;
    int server_len = 0;
    int client_len = 0;
    char buffer[512];
    int result = 0;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    //创建数据报套接字
    server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    //设置监听IP端口
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(9739);
    server_len = sizeof(server_addr);
    //绑定（命名）套接字
    bind(server_sockfd, (struct sockaddr*)&server_addr, server_len);
    //忽略子进程停止或退出信号
    signal(SIGCHLD, SIG_IGN);


    while(1)
    {
        //接收数据，用client_addr来储存数据来源程序的IP端口
        result = recvfrom(server_sockfd, buffer, sizeof(buffer), 0,
                (struct sockaddr*)&client_addr, (socklen_t*)&client_len);
        //if(fork() == 0)
      //  {
            //利用子进程来处理数据
            //buffer[0] += 'a' - 'A';
            sleep(5);
            //发送处理后的数据
         printf("%c\n", buffer[0]);
            int n = sendto(server_sockfd, buffer,result,0 ,
                (struct sockaddr*)&client_addr, client_len);
            printf("n:%d, buffer:%c\n", n, buffer[0]);
            break;
            //注意，一定要关闭子进程，否则程序运行会不正常
          //  exit(0);
      //  }
   }
    //关闭套接字
    close(server_sockfd);
    exit(0);
}

int test_udp_client(/* int agrc, char *argv[] */)
{
    struct sockaddr_in server_addr;
    int server_len = 0;
    int sockfd = -1;
     char c = 'A';
    // //取第一个参数的第一个字符
    // if(agrc > 1)
    //     c = argv[1][0];
    //创建数据报套接字
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    //设置服务器IP端口
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(9739);
    server_len = sizeof(server_addr);
    //向服务器发送数据
    int n = sendto(sockfd, &c, sizeof(char), 0,
        (struct sockaddr*)&server_addr, server_len);
    //接收服务器处理后发送过来的数据，由于不关心数据来源，所以把后两个参数设为0
    n = recvfrom(sockfd, &c, sizeof(char), 0, 0, 0);
    printf("char from server = %c\n", c);
    //关闭套接字
    close(sockfd);
    exit(0);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////