#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT   9999 
#define BACKLOG 1

#define MAX_BUF_SIZE	64 
#define RECVMAX 64
#define IP_ADDR "192.168.1.10"
//#define IP_ADDR "127.0.0.1"

char recvbuf[RECVMAX];
int recv_num = 0;
char sendbuf[] = "test\n";
int main(int argc,char *argv[])
{	
	int sockfd,num;
	struct sockaddr_in server;
	char *ip = (char *)IP_ADDR;
	int port = PORT;
    if (argc == 2) 
	{  
		ip = argv[1];	
    } 
	else if(argc == 3)
	{
		ip = argv[1];
		port = atoi(argv[2]);
	}

	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
	{  
       printf("socket()error\n");  
       exit(1);  
    }  
	
	memset(&server,0,sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr(ip);

	if(connect(sockfd,(struct sockaddr *)&server,sizeof(server)) == -1)
	{  
       printf("connect() error\n");  
       exit(1);  
    }	
	else
	{
		printf("Connect success!\n");
		printf("Please enter command:\n");
	}
	while(1)
	{
		fgets(sendbuf,MAX_BUF_SIZE,stdin);	
		write(sockfd,sendbuf,strlen(sendbuf));	
		if(sendbuf[0] == 'q')
		{
			break;
		}
		if((recv_num = read(sockfd,recvbuf,RECVMAX)) == -1)
		{  
       		printf("recv() error\n");  
       		exit(1);  
    	} 
		recvbuf[recv_num] = '\0';
		printf("%s\n",recvbuf);
		
	}

	close(sockfd);
	return 0;

} 
