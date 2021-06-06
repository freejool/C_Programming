//
// Created by Sxing on 06/01/2021.
//

#ifndef INC_10__CONN_H
#define INC_10__CONN_H

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string.h>
#include "head.h"

#pragma comment (lib, "ws2_32.lib")

char tmp[1024];

typedef struct {
    char IP[20];
    unsigned short port;
} Server;

Server host = {"47.118.51.124", 8080};

/* send data example:
 * http://47.118.51.124:8080/CarService2/SendData?timestamp=123&ID=12314&name=John&sex=1&telephoneNum=123123123&company=HDU&carNum=12312312&reason=asdasd&
 *
 * fetch data example:
 * http://47.118.51.124:8080/CarService2/GetData?ID=12314
 * */

WSADATA wsa;
SOCKET s;
struct sockaddr_in server;
char server_reply[2000];
int recv_size;

int initConn() {
    // initialize connection, printing errors, return 1 when failed, 0 when succeed.
    // printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WinSock initializing Failed. Error Code : %d", WSAGetLastError());
        return 1;
    }

    // printf("Initialised.\n");

    // Create a socket
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d", WSAGetLastError());
        return 1;
    }

    // printf("Socket created.\n");
    server.sin_addr.s_addr = inet_addr(host.IP); // address of http server
    server.sin_family = AF_INET; // TCP/IP v4
    server.sin_port = htons(host.port); // port 8080

    //Connect to remote server
    if (connect(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
        puts("connect error");
        return 1;
    }

    // puts("Connected");
    return 0;
}

int request(char *sendMessage, char *receiveMessage) {
    initConn();
    // send a request to host
    // char *sendMessage: GET request.
    // char receiveMessage[2000]): received message from host.

    //Send some data发送请求
    //"GET /example.html HTTP/1.1\r\n"
    //"Host: www.example.com\r\n"
    //"\r\n"
    //    http://47.118.51.124:8080/CarService2/GetData?ID=12314
    // char * sendMessage = "GET /CarService2/GetData?ID=12314 HTTP/1.1\r\nHost: 47.118.51.124:8080\r\n\r\n";
    if (send(s, sendMessage, strlen(sendMessage), 0) < 0) {
        puts("Send failed");
        // return 1;
    }
    // puts("Data Send\n");

    //Receive a reply from the server接收html文档
    if ((recv_size = recv(s, server_reply, 2000, 0)) == SOCKET_ERROR) {
        puts("recv failed");
        return -1;
    }

    // puts("Reply received\n");

    //Add a NULL terminating character to make it a proper string before printing
    server_reply[recv_size] = '\0';
    strcpy(receiveMessage, server_reply);
    WSACleanup();
    if (receiveMessage[9] == '5') {
        return -500;
    }
    return 0;
}

int sendData() { // 返回负值是错误代码，0是成功
    char str[1024];
    char recv[1024];
    int rt; // return of request
    sprintf(str, "GET /CarService2/SendData?"
                 "timestamp=%lld"
                 "&ID=%s"
                 "&name=%s"
                 "&sex=%d"
                 "&telephoneNum=%s"
                 "&company=%s"
                 "&carNum=%s"
                 "&reason=%s"
                 "&guarantor=%s"
                 "&guarantorNum=%s"
                 "&healthNum=%d"
                 "&ifComeToDangerousPlace=%d"
                 "&ifFever=%d"
                 "&applyInTime=%lld"
                 "&applyOutTime=%lld"
                 "&factInTime=%lld"
                 "&factOutTime=%lld"
                 " HTTP/1.1\r\nHost: %s:%d\r\n\r\n",
            info.timestamp,
            info.ID,
            info.name,
            info.sex,
            info.teleNum,
            info.company,
            info.carNum,
            info.reason,
            info.guarantor,
            info.guarantorNum,
            info.healthNum,
            info.ifComeToDangerousPlace,
            info.ifFever,
            info.applyInTime,
            info.applyOutTime,
            info.factInTime,
            info.factOutTime,
            host.IP,
            host.port);
    rt = request(str, recv); // http request

    return rt;
}

int getData(char ID[]) {
    char str[2048];
    char recv[2048];
    char *token;
    int num;
    int rt;
    int i = 0;
    int startPos[20] = {0}; // 每行行首在recv的索引
    int count_n = 0;
    char *ptr;
    INFO infoT; // info存最近一条信息,infoT存tmp
    time_t timeTmp = 0; //
    sprintf(str, "GET /CarService2/GetData?"
                 "ID=%s"
                 " HTTP/1.1\r\nHost: %s:%d\r\n\r\n",
            ID,
            host.IP,
            host.port);
    rt = request(str, recv);
    if (rt < 0) return rt;


    while (count_n < 6) {
        if (recv[i] == '\n') {
            count_n++;
            startPos[count_n] = i + 1;
        }
        i++;
    }


    strncpy(tmp, recv + startPos[4], startPos[5] - startPos[4]);
    num = strtol(tmp, &ptr, 10);
    if (num != 0) {
        strcpy(tmp, recv + startPos[5]); // 从第一条记录的第一位开始赋值给tmp

        token = strtok(tmp, ",");
        strcpy(info.name, token);

        token = strtok(NULL, ",");//strtok字符串分割
        if (strcmp(token, "null") == 0) info.sex = -1;
        else info.sex = token[0] - '0';

        token = strtok(NULL, ",");
        strcpy(info.ID, token);

        token = strtok(NULL, ",");
        if (strcmp(token, "null") == 0) info.timestamp = -1;
        else info.timestamp = strtol(token, &ptr, 10);

        token = strtok(NULL, ",");
        strcpy(info.teleNum, token);

        token = strtok(NULL, ",");
        strcpy(info.company, token);

        token = strtok(NULL, ",");
        strcpy(info.carNum, token);

        token = strtok(NULL, ",");
        strcpy(info.reason, token);

        token = strtok(NULL, ",");
        strcpy(info.guarantor, token);

        token = strtok(NULL, ",");
        strcpy(info.guarantorNum, token);

        token = strtok(NULL, ",");
        if (strcmp(token, "null") == 0) info.healthNum = -1;
        else info.healthNum = token[0] - '0';

        token = strtok(NULL, ",");
        if (strcmp(token, "null") == 0) info.ifComeToDangerousPlace = -1;
        else info.ifComeToDangerousPlace = token[0] - '0';

        token = strtok(NULL, ",");
        if (strcmp(token, "null") == 0) info.ifFever = -1;
        else info.ifFever = token[0] - '0';

        token = strtok(NULL, ",");
        if (strcmp(token, "null") == 0) info.applyInTime = -1;
        else info.applyInTime = strtol(token, &ptr, 10);

        token = strtok(NULL, ",");
        if (strcmp(token, "null") == 0) info.applyOutTime = -1;
        else info.applyOutTime = strtol(token, &ptr, 10);

        token = strtok(NULL, ",");
        if (strcmp(token, "null") == 0) info.applyInTime = -1;
        else info.factInTime = strtol(token, &ptr, 10);

        token = strtok(NULL, ",");
        if (strcmp(token, "null") == 0) info.applyInTime = -1;
        else info.factOutTime = strtol(token, &ptr, 10);
    }

    return num;
// 此时info中存着最新的记录
}

int release() {
    WSACleanup();
    system("cls");
    return 0;
}

#endif //INC_10__CONN_H

