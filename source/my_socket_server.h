/**
 ******************************************************************************
 * @file    
 * @author  wind
 * @version
 * @date
 * @brief
 ******************************************************************************
 */

#ifndef __MY_SOCKET_SERVER_H
#define __MY_SOCKET_SERVER_H


#include "lwip/opt.h"
#include "lwip/arch.h"
#include "lwip/api.h"
#include "lwip/inet.h"
#include "lwip/sockets.h"
#include "fs.h"
#include "fsdata.h"
#include "string.h"
#include <stdio.h>
#include "cmsis_os.h"
#include  "lcd_log.h"

#define LED1_ON "led1 on"
#define LED1_OFF "led1 off"
#define LED2_ON "led2 on"
#define LED2_OFF "led2 off"

void my_server_init(void);

void my_server_thread(void *arg);

void my_server_echo(int connfd);


#endif/*__MY_SOCKET_SERVER_H*/