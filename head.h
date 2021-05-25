//
// Created by 沈星宇 on 2021/5/19.
//

#ifndef INC_10__HEAD_H
#define INC_10__HEAD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sql.h"

typedef enum {
    Green,
    Yellow,
    Red
} healthCode;

typedef struct {
    char name[20];
    bool sex;
    char tel[20];
    char ID[30];
    char company[20];
    char carNum[20];
    char reason[100];
    char guarantor[20];
    char guarantorTel[20];
    healthCode healthCode;
    bool beenInInfectedAreaIn14Days;
    bool haveSymptoms;
    time_t AppliedEntryTime;
    time_t AppliedDepartureTime;
} Info;
// 姓名、性别、联系电话、身份证号、单位信息、车牌号、进校事由、担保人、担保人电话、健康码、
// 14天内是否去过疫区、是否有咳嗽发热等症状、申请进入 时间、申请离开时间、实际进入时间、实际离开时间等信息

typedef enum {
    User = 0,
    Admin
} Privilege;

Privilege privilege = User;
char scanStr[50];


void init() {
    connectMysql();
   // init_keyboard();

    //  TODO DRAW UI
} // 初始化：建立连接

void alert(char str[]) {
    printf("%s\n", str); // TODO
} // 提示信息

void scan() {
    scanf("%s", scanStr); // TODO
} // 用户输入

void newInfo() {
    Info info;
    char sql[100];
    alert("Input your name: ");
    scan();
    strcpy(info.name, scanStr);
    alert("Input your telephone number: ");
    scan();
    strcpy(info.tel, scanStr);
    alert("Input your ID number: ");
    scan();
    strcpy(info.ID, scanStr);
    sprintf(sql,"INSERT INTO info (name,tel,ID) VALUES('%s','%s','%s');",info.name,info.tel,info.ID);
    updateData(sql);
    alert("Done!");
} // 访客登记

void login() {
    FILE *f;
    char passwd[20];
    if ((f = fopen("passwd", "r")) == NULL) {
        alert("Fail to read 'passwd'!");
        return;
    }
    alert("Input password: ");
    fscanf(f, "%s", passwd);
    scan();
    if (strcmp(passwd, scanStr) == 0) {
        alert("Switched to Admin!");
        privilege = Admin;
    } else {
        alert("Wrong password!");
    }
    fclose(f);
} // 用户,管理员



void freeResource() {
    freeConnect();
}

void printTable(){
    if(privilege==User){
        alert("You have to be an Admin to print table!");
        return;
    }
    outMysql();
}

#endif //INC_10__HEAD_H
