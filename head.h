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

Privilege privilege = User;
char timeBuf[50];
INFO info;


//void clearInfo(){
//    info.    name[20]=;
//    info.    sex; // 0:female, 1:male
//    info.    ID[30]; // 身份证号
//    info.   timestamp;
//    info.       teleNum[50]; // 联系电话
//    info.       company[50]; // 单位信息
//    info.       carNum[50]; // 车牌号
//    info.       reason[50]; // 进校事由
//    info.       guarantor[50];	// 担保人
//    info.       guarantorNum[50]; // 担保人电话
//    info.       healthNum; // 健康码
//    info.       ifComeToDangerousPlace; // 14天内是否去过疫区
//    info.       ifFever; // 是否有咳嗽发热等症状
//    info.applyInTime; // 申请进入时间
//    info.applyOutTime; // 申请离开时间
//    info.factInTime; // 实际进入时间
//    info.factOutTime; // 实际离开时间
//}


//void newInfo() {
//    char sql[100];
//    time_t time_t;
//    time_t = time(NULL);
//    struct tm *arrTm;
//    alert("Input your name: ");
//    scan();
//    strcpy(info.name, scanStr);
//    alert("Input your telephone number: ");
//    scan();
//    strcpy(info.teleNum, scanStr);
//    alert("Input your ID number: ");
//    scan();
//    strcpy(info.ID, scanStr);
//    alert("Input your Arrival time(eg.2021-5-22 16:50): ");
//    arrTm = localtime(&time_t);
//    scanf("%d-%d-%d %d:%d", &arrTm->tm_year, &arrTm->tm_mon, &arrTm->tm_mday,
//          &arrTm->tm_hour, &arrTm->tm_min);
//
//    sprintf(sql, "INSERT INTO info (name,teleNum,ID) VALUES('%s','%s','%s');", info.name, info.teleNum,
//            info.ID);
//   // updateData(sql);
//    alert("Done!");
//} // 访客登记


//时间戳转日期 yyyy-MM-dd HH:mm:ss
void timeToDate(time_t mytime) {
    struct tm *timeinfo;

    timeinfo = localtime(&mytime); //转换
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", timeinfo);
    // printf("%s\n", timeBuf); //日期存入buffer中
}

//日期转时间戳
time_t dateToTime(char *str_time) {
    struct tm stm;
    int iY, iM, iD, iH, iMin, iS;

    memset(&stm, 0, sizeof(stm));

    iY = atoi(str_time); //分裂读入的日期
    iM = atoi(str_time + 5);
    iD = atoi(str_time + 8);
    iH = atoi(str_time + 11);
    iMin = atoi(str_time + 14);
    iS = atoi(str_time + 17);

    stm.tm_year = iY - 1900;
    stm.tm_mon = iM - 1;
    stm.tm_mday = iD;
    stm.tm_hour = iH;
    stm.tm_min = iMin;
    stm.tm_sec = iS;

    /*printf("%d-%0d-%0d %0d:%0d:%0d\n", iY, iM, iD, iH, iMin, iS);*/
    return mktime(&stm);
}

void printRecord() {
    if (privilege == User) {
        printf("您还不是管理员!请先登录!");
    }
}

#endif //INC_10__HEAD_H
