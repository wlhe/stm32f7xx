/**
 ******************************************************************************
 * @file
 * @author  wind
 * @version
 * @date
 * @brief
 ******************************************************************************
 */

#include "my_socket_server.h"

#define PORT 9999
#define BACKLOG 5
#define MAX_BUFF_SIZE   64
char sendbuf[MAX_BUFF_SIZE];
char recvbuf[MAX_BUFF_SIZE];

void my_server_init(void)
{
    sys_thread_new("MY_SERVER", my_server_thread, NULL, DEFAULT_THREAD_STACKSIZE * 2, TCPIP_THREAD_PRIO);
}

void my_server_thread(void *arg)
{
    int listenfd,connectfd;
    struct sockaddr_in server,client;
    socklen_t addrlen;

    if((listenfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
    {
        return ;
    }


    int opt = SO_REUSEADDR;
    setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    memset(&server,0,sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(listenfd,(struct sockaddr *)&server,sizeof(server)) == -1)
    {
        return;
    }
    if(listen(listenfd,BACKLOG) == -1)
    {
        return;
    }
    addrlen = sizeof(client);



    while(1)
    {
        LCD_UsrLog("Waiting for connect...\n");
        connectfd = accept(listenfd,(struct sockaddr*)&client,&addrlen);

        if(connectfd == -1)
        {
            continue;
        }
        LCD_UsrLog("A client is connected, ip: %s\tport:%d\n",inet_ntoa(client.sin_addr),htons(client.sin_port));


        my_server_echo(connectfd);
    }

    close(listenfd);
}

void my_server_echo(int connfd)
{
    int rxsize;
    
    BSP_LED_On(LED1);
    BSP_LED_Off(LED2);

    while(1)
    {
        if((rxsize = read(connfd, recvbuf, MAX_BUFF_SIZE)) == -1)
        {
            continue;
        }
        else if(rxsize == 0)
        {
          break;
        }
        else
        {
        	if(recvbuf[0] == 'q')
              	break;
          	recvbuf[rxsize - 1] = '\0';
		
		if(strncmp(recvbuf,LED1_ON,sizeof(LED1_ON)) == 0)
			BSP_LED_On(LED1);
		else if(strncmp(recvbuf,LED1_OFF,sizeof(LED1_OFF)) == 0)
			BSP_LED_Off(LED1);
		else if(strncmp(recvbuf,LED2_ON,sizeof(LED2_ON)) == 0)
			BSP_LED_On(LED2);
		else if(strncmp(recvbuf,LED2_OFF,sizeof(LED2_OFF)) == 0)
			BSP_LED_Off(LED2);

        	LCD_UsrLog("%s\n",recvbuf);
        	write(connfd, recvbuf, rxsize);
        }
        osDelay(10);
    }

    close(connfd);
}
