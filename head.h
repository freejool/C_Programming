//
// Created by 沈星宇 on 2021/5/19.
//

#ifndef INC_10__HEAD_H
#define INC_10__HEAD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <winsock2.h>

#define INFO_NUM 10
#define POS_X1 35
#define POS_X2 40
#define POS_X3 50
#define POS_X4 65
#define POS_Y 3

typedef struct {
    char name[20];
    int sex; // 0:female, 1:male
    char ID[30]; // 身份证号
    time_t timestamp;
    char teleNum[50]; // 联系电话
    char company[50]; // 单位信息
    char carNum[50]; // 车牌号
    char reason[50]; // 进校事由
    char guarantor[50];    // 担保人
    char guarantorNum[50]; // 担保人电话
    int healthNum; // 健康码
    int ifComeToDangerousPlace; // 14天内是否去过疫区
    int ifFever; // 是否有咳嗽发热等症状
    time_t applyInTime; // 申请进入时间
    time_t applyOutTime; // 申请离开时间
    time_t factInTime; // 实际进入时间
    time_t factOutTime; // 实际离开时间
} INFO;
// 姓名、性别、联系电话、身份证号、单位信息、车牌号、进校事由、担保人、担保人电话、健康码、
// 14天内是否去过疫区、是否有咳嗽发热等症状、申请进入 时间、申请离开时间、实际进入时间、实际离开时间等信息

typedef enum {
    User = 0,
    Admin
} Privilege;

char timeBuf[50];
INFO info;

typedef struct {
    char IP[20];
    unsigned short port;
} Server;

int initConn();

int request(char *sendMessage, char *receiveMessage);

int sendData();

int getData(char ID[]);

int release();

//时间戳转日期 yyyy-MM-dd HH:mm:ss
void timeToDate(time_t mytime);

//日期转时间戳
time_t dateToTime(char *str_time);

void SetPosition(int x, int y);

int Menu();

int isDenied();

void Register();

void Arrival();

void departure();

void login();

void lookUp();

#endif //INC_10__HEAD_H
