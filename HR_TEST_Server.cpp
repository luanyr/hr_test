#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <pthread.h>
#include <fcntl.h>
#include<sys/ioctl.h>
#include<net/if.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#define port (6666)
//test git diff
typedef int type_socket;
int server_log(char * log_buf);
void get_time(char* time_buf);
static void* hanle_request(void* argv)
{
    type_socket client_fd = *((type_socket *)argv);
    int n;
    char rec_buf[128];
    char send_buf[128];
	char time[64];
    while(1)
    {
        memset(rec_buf, 0, sizeof(rec_buf));
        n = recv(client_fd, rec_buf, sizeof(rec_buf), 0);
        if( n > 0 )
        {
            if( strcmp(rec_buf, "FFT") == 0)
            {
                write(client_fd, "FFT TEST PASSED", sizeof("FFT TEST PASSED"));
            } else if (strcmp(rec_buf, "CDMA") == 0)
            {
                write(client_fd, "CDMA TEST PASSED", sizeof("CDMA TEST PASSED"));
            } else if (strcmp(rec_buf, "SRIO") == 0)
            {
                write(client_fd, "SRIO TEST PASSED", sizeof("SRIO TEST PASSED"));
            } else if (strcmp(rec_buf, "BASE") == 0)
            {
                write(client_fd, "BASE TEST PASSED" , sizeof("BASE TEST PASSED"));
            } else if (strcmp(rec_buf, "ALL") == 0)
            {
                write(client_fd, "ALL TEST PASSED", sizeof("BASE TEST PASSED"));
            } else if (strcmp(rec_buf, "tempture") == 0)
			{
				 write(client_fd, "temp:30", sizeof("temp:30"));
			} else if (strcmp(rec_buf, "version") == 0)
			{
				write(client_fd, "ver:hr_test_0430", sizeof("ver:hr_test_0430"));
			}
			get_time(time);
			server_log(rec_buf);
        }
        
    }

    //close(client_fd);
}
void get_time(char* time_buf)
{
	time_t nseconds;
	tm *ptm;
	time(&nseconds);
	ptm = localtime(&nseconds);
	sprintf(time_buf, "02d:%02d:%02d", ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
	cout << time_buf;
}
int startup(char *ip_buf)
{
    sockaddr_in server_addr;
    sockaddr_in *ip_addr;
    ifreq temp;

    int ret = -1;
    strcpy(temp.ifr_name, "eth1");//centos eth1 ip addr
    type_socket sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1)
    {
        perror("socket");
        return 0;
    }
    ret = ioctl(sock_fd, SIOCGIFADDR, &temp);
    if(ret)
    {
        perror("ioctl");
        return -1;
    } else {
        ip_addr = (struct sockaddr_in *)&(temp.ifr_addr);
        stpcpy(ip_buf, inet_ntoa(ip_addr -> sin_addr));
    }
    int on = 1;  
    if((setsockopt(sock_fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)))<0)
    {  
        perror("setsockopt");
        return -1; 
    }  
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bzero(&(server_addr.sin_zero), 8);
    if(bind(sock_fd, (sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("bind");
        return -1;
    }
    if(listen(sock_fd, 5) < 0) 
    {
        perror("listen");
        return -1;
    }
    return (sock_fd);
}

int server_log(char * log_buf)
{
    int file_fd;
	int n;
	char time[32];
	char buf[64];
    file_fd = open("/root/Desktop/server/0427/server_log2.txt", O_RDWR| O_CREAT| O_APPEND);
    if(file_fd < 0)
    {
        perror("open");
        return -1;
    }
	get_time(time);
	sprintf(buf, "%s:%s\r\n\0", time, log_buf);
    n = write(file_fd, buf, strlen(buf));
	close(file_fd);
}
int main()
{
    int n;
    time_t now;
    socklen_t addr_length;
    sockaddr_in client_addr;
    pthread_t thread_do;
    char ip_buf[64];
    type_socket server_fd;
    server_fd = startup(ip_buf);
    if(server_fd != -1)
    {
        cout << "Server IP Addr:" << ip_buf << "," << "Port:" << port << endl;
    } else {
        cout << "Start up failed" << endl;
        return -1;
    }
    addr_length = sizeof(struct sockaddr_in);
	
    while (true)
    {
        type_socket client_fd = accept(server_fd, (sockaddr *)&client_addr, &addr_length);
        if (client_fd == -1)
        {
            perror("accept");
            return -1;
        } else {
            cout << inet_ntoa(client_addr.sin_addr) << "," << htons(client_addr.sin_port) << "登录" << endl;
			char *client_ip = inet_ntoa(client_addr.sin_addr);
			server_log(client_ip);
        }
        if(pthread_create(&thread_do, NULL, hanle_request, &client_fd) != 0)
        {
            perror("pthread_creat");
        }
    }
    close(server_fd);
    return 0;
}
