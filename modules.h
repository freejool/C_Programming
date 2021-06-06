//
// Created by Sxing on 06/02/2021.
//

#ifndef INC_10__MODULES_H
#define INC_10__MODULES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "head.h"
#include "conn.h"

#define INFO_NUM 10
#define POS_X1 35
#define POS_X2 40
#define POS_X3 50
#define POS_X4 65
#define POS_Y 3


void SetPosition(int x, int y) {
    HANDLE hOut;
    COORD pos;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut, pos);
}


int Menu() {
    system("cls");
    int option;
    int posy = 5;

    SetPosition(POS_X2, posy += 2);
    printf("校园外来人员进出监控与管理系统");

    SetPosition(POS_X2, posy += 2);
    printf("1、进出校园登记");

    SetPosition(POS_X2, posy += 2);
    printf("2、人员进入");

    SetPosition(POS_X2, posy += 2);
    printf("3、人员离开");

    SetPosition(POS_X2, posy += 2);
    printf("4、管理员登陆");

    SetPosition(POS_X2, posy += 2);
    printf("5、查找记录(管理员)");

    SetPosition(POS_X2, posy += 2);
    printf("0、退出系统");

    SetPosition(POS_X2, posy += 2);
    printf("选择的是:");
    scanf("%d", &option);
    return option;

}

int isDenied() {
    if (info.healthNum == 0 && info.ifComeToDangerousPlace == 0 && info.ifFever == 0) {
        return 0;
    } else {
        return 1;
    }
}

void Register() {
    system("cls");

    char inputTime[30] = "";
    char tmp[30];
    int posy = 6;
    int rt;
    time_t timeStamp;
    info.timestamp = time(NULL);
    info.factInTime = 0;
    info.factOutTime = 0;

    SetPosition(POS_X2, posy);
    printf("请输入个人信息");

    SetPosition(POS_X2, ++posy);
    printf("时间格式 yyyy-MM-dd HH:mm:ss");

    SetPosition(POS_X2, posy += 2);
    printf("姓名:\t\t");
    scanf("%s", info.name);

    SetPosition(POS_X2, posy += 2);
    printf("性别(男:0 女:1):");
    scanf("%d", &info.sex);

    SetPosition(POS_X2, posy += 2);
    printf("身份证号:\t");
    scanf("%s", info.ID);

    SetPosition(POS_X2, posy += 2);
    printf("联系电话:\t");
    scanf("%s", info.teleNum);

    SetPosition(POS_X2, posy += 2);
    printf("单位信息:\t");
    scanf("%s", info.company);

    SetPosition(POS_X2, posy += 2);
    printf("车牌号:\t\t");
    scanf("%s", info.carNum);

    SetPosition(POS_X2, posy += 2);
    printf("进校事由:\t");
    scanf("%s", info.reason);

    SetPosition(POS_X2, posy += 2);
    printf("担保人:\t\t");
    scanf("%s", info.guarantor);

    SetPosition(POS_X2, posy += 2);
    printf("担保人电话:\t");
    scanf("%s", info.guarantorNum);

    SetPosition(POS_X2, posy += 2);
    printf("健康码:\t\t"); // 0:绿 >1:其他
    scanf("%d", &info.healthNum);

    SetPosition(POS_X2, posy += 2);
    printf("14天内是否去过疫区:\t"); // 0:否 1:是
    scanf("%d", &info.ifComeToDangerousPlace);

    SetPosition(POS_X2, posy += 2);
    printf("是否有咳嗽发热等症状:\t"); // 0:否 1:是
    scanf("%d", &info.ifFever);

    SetPosition(POS_X2, posy += 2);
    printf("申请进入时间:\t");

    scanf("%s", tmp);
    strcat(inputTime, tmp);
    strcat(inputTime, " ");
    scanf("%s", tmp);
    strcat(inputTime, tmp);
    timeStamp = dateToTime(inputTime);
    info.applyInTime = timeStamp;
    memset(inputTime, 0, 30 * sizeof(char));

    SetPosition(POS_X2, posy += 2);
    printf("申请离开时间:\t");

    scanf("%s", tmp);
    strcat(inputTime, tmp);
    strcat(inputTime, " ");
    scanf("%s", tmp);
    strcat(inputTime, tmp);
    timeStamp = dateToTime(inputTime);
    info.applyOutTime = timeStamp;
    memset(inputTime, 0, strlen(inputTime) * sizeof(char));

    info.factInTime = 0;
    info.factOutTime = 0;

    SetPosition(POS_X2, posy += 2);
    if (isDenied()) {
        printf("申请失败! 健康码不是绿码或发烧或到过高风险区域");
    } else if (info.applyInTime > info.applyOutTime) {
        printf("进入时间不能超过离开时间");
//    } else if (info.applyInTime <= info.timestamp) {
//        printf("请输入将来的时刻");
    } else {
        printf("申请成功!");
        SetPosition(POS_X2, posy += 2);
        rt = sendData();
        if (rt == 0) {
            printf("记录已保存!");
        } else {
            printf("记录保存失败,错误%d", rt);
        }
    }


    SetPosition(POS_X2, posy += 2);
    system("pause");

//	SetPosition(POS_X2, posy += 2);
//	printf("姓名 %s 电话 %s 性别 %d",info.guarantor,info.teleNum,info.sex);//测试

}

void Arrival() {
    system("cls");
    int posy = 5;
    int rt;
    char id[50];
    time_t timeNow = time(NULL);


    SetPosition(POS_X2, posy += 2);
    printf("请输入您的身份证号:");
    scanf("%s", id);
    rt = getData(id);
    SetPosition(POS_X2, posy += 2);
    if (rt < 0) {
        printf("记录获取失败,错误 %d", rt);
    } else if (rt == 0) {
        printf("未登记!");
    } else {
        /*sprintf(str,"timestamp=%lld"
                     "&ID=%s"
                     "&name=%s"
                     "&sex=%d"
                     "&telephoneNum=%s"
                     "&company=%s"
                     "&carNum=%s"
                     "&reason=%s"
                     "&guarantor=%s"
                     "&guarantorTelNum=%s"
                     "&healthNum=%d"
                     "&ifComeToDangerousPlace=%d"
                     "&ifFever=%d"
                     "&applyInTime=%lld"
                     "&applyOutTime=%lld",
                info.timestamp,
                info.ID,
                info.name,
                info.sex,
                info.teleNum,
                info.company,
                info.carNum,
                info.reason,
                info.guarantor,
                info.guarantorTelNum,
                info.healthNum,
                info.ifComeToDangerousPlace,
                info.ifFever,
                info.applyInTime,
                info.applyOutTime);*/

        printf("您共有 %d 条记录", rt);
        SetPosition(POS_X2, posy += 2);
        printf("姓名: %s", info.name);

        SetPosition(POS_X2, posy += 2);
        timeToDate(info.applyInTime);
        printf("申请进入时间: %s", timeBuf);

        SetPosition(POS_X2, posy += 2);
        timeToDate(info.applyOutTime);
        printf("申请离开时间: %s", timeBuf);

        SetPosition(POS_X2, posy += 2);
        if (isDenied()) {
            printf("健康码不是绿码或发烧或到过高风险区域");
        } else if (timeNow < info.applyInTime || timeNow > info.applyOutTime) {
            printf("现在不在申请的时间内");
        } else {
            printf("请进!");
            info.timestamp = timeNow;
            info.factInTime = timeNow;
            rt = sendData();
            SetPosition(POS_X2, posy += 2);
            if (rt == 0) {
                printf("记录已保存");
            } else {
                printf("服务器连接失败,记录保存失败,错误%d", rt);
            }
        }
    }
    SetPosition(POS_X2, posy += 2);
    system("pause");
}

void departure() {
    system("cls");
    int posy = 5;
    int rt;
    char id[50];
    time_t timeNow = time(NULL);


    SetPosition(POS_X2, posy += 2);
    printf("请输入您的身份证号:");
    scanf("%s", id);
    rt = getData(id);
    SetPosition(POS_X2, posy += 2);
    if (rt < 0) {
        printf("获取记录失败,错误 %d", rt);
    } else if (rt == 0) {
        printf("未登记");
    } else {
        printf("您共有 %d 条记录", rt);
        SetPosition(POS_X2, posy += 2);
        printf("姓名: %s", info.name);

        SetPosition(POS_X2, posy += 2);
        timeToDate(info.applyInTime);
        printf("申请进入时间: %s", timeBuf);

        SetPosition(POS_X2, posy += 2);
        timeToDate(info.applyOutTime);
        printf("申请离开时间: %s", timeBuf);

        if (timeNow > info.applyOutTime) {
            SetPosition(POS_X2, posy += 2);
            printf("请在申请的离开时间前离开");
        }
        SetPosition(POS_X2, posy += 2);
        printf("欢迎下次再来!");
        info.timestamp = timeNow;
        info.factOutTime = timeNow;
        rt = sendData();
        SetPosition(POS_X2, posy += 2);
        if (rt == 0) {
            printf("记录已保存");
        } else {
            printf("服务器连接失败,记录保存失败,错误%d", rt);
        }

    }
    SetPosition(POS_X2, posy += 2);
    system("pause");
}

void login() {
    system("cls");
    FILE *f;
    char str[20];
    char passwd[20];
    SetPosition(POS_X2, 5);
    if (privilege == Admin) {
        printf("您已经是管理员了!");
    }
    if ((f = fopen("C:\\Users\\Sxing\\OneDrive\\2020_2\\C\\10#\\passwd", "r")) == NULL) {
        printf("无法读取 'passwd'!");
    } else {
        int posy = 5;
        SetPosition(POS_X2, 7);
        printf("请输入管理员密码:");

        fscanf(f, "%s", passwd);
        scanf("%s", str);
        SetPosition(POS_X2, 9);
        if (strcmp(passwd, str) == 0) {
            printf("登陆成功!");
            privilege = Admin;
        } else {
            printf("密码错误!");
        }
        fclose(f);
    }
    SetPosition(POS_X2, 11);
    system("pause");
} // 用户,管理员

void lookUp() {
    int y = 5;
    char ID[50];
    int rt;
    char str[1024];
    system("cls");
    SetPosition(POS_X1, y += 2);
    if (privilege == User) {
        printf("请以管理员身份登录!");
        SetPosition(POS_X1, y += 2);
    } else {
        printf("请输入身份证号:");
        scanf("%s", ID);
        rt = getData(ID);
        SetPosition(POS_X1, y += 2);
        if (rt < 0) {
            printf("记录获取失败,错误%d", rt);
        } else if (rt == 0) {
            printf("未找到记录!");
        } else {
            printf("共有%d条记录", rt);
            SetPosition(POS_X1, y += 2);//隔开
            printf("最新的一条记录是:");
//          姓名、性别、联系电话、身份证号、单位信息、车牌号、进校事由、担保人、担保人电话、健康码、
// 			14天内是否去过疫区、是否有咳嗽发热等症状、申请进入 时间、申请离开时间、实际进入时间、实际离开时间等信息
//            sprintf(str, "更新时间: %lld\n"
//                         "身份证号:\t%s\n"
//                         "姓名:\t\t%s\n"
//                         "性别:\t\t%d\n"
//                         "联系电话:\t%s\n"
//                         "单位:\t\t%s\n"
//                         "车牌号:\t\t%s\n"
//                         "进校事由:\t%s\n"
//                         "担保人:\t\t%s\n"
//                         "担保人电话:\t%s\n"
//                         "健康码:\t%d\n"
//                         "去过疫区:\t%d\n"
//                         "咳嗽发热:\t%d\n"
//                         "申请进入时间:\t%lld\n"
//                         "申请离开时间:\t%lld\n"
//                         "实际进入时间:\t%lld\n"
//                         "实际离开时间:\t%lld\n",
//                    info.timestamp,
//                    info.ID,
//                    info.name,
//                    info.sex,
//                    info.teleNum,
//                    info.company,
//                    info.carNum,
//                    info.reason,
//                    info.guarantor,
//                    info.guarantorTelNum,
//                    info.healthNum,
//                    info.ifComeToDangerousPlace,
//                    info.ifFever,
//                    info.applyInTime,
//                    info.applyOutTime,
//                    info.factInTime,
//                    info.factOutTime);
//            SetPosition(POS_X2, y += 2);
//            printf("%s", str);
            SetPosition(POS_X1, y += 2);
            timeToDate(info.timestamp);
            printf("更新时间:\t%s", timeBuf);
            SetPosition(POS_X1, y += 2);
            printf("身份证号:\t%s", info.ID);
            SetPosition(POS_X1, y += 2);
            printf("姓名:\t%s", info.name);
            SetPosition(POS_X1, y += 2);
            printf("性别:\t%d", info.sex);
            SetPosition(POS_X1, y += 2);
            printf("联系电话:\t%s", info.teleNum);
            SetPosition(POS_X1, y += 2);
            printf("单位:\t%s", info.company);
            SetPosition(POS_X1, y += 2);
            printf("车牌号:\t%s", info.carNum);
            SetPosition(POS_X1, y += 2);
            printf("进校事由:\t%s", info.reason);
            SetPosition(POS_X1, y += 2);
            printf("担保人:\t%s", info.guarantor);
            SetPosition(POS_X1, y += 2);
            printf("担保人电话:\t%s", info.guarantorNum);
            SetPosition(POS_X1, y += 2);
            printf("健康码:\t%d", info.healthNum);
            SetPosition(POS_X1, y += 2);
            printf("去过疫区:\t%d", info.ifComeToDangerousPlace);
            SetPosition(POS_X1, y += 2);
            printf("咳嗽发热:\t%d", info.ifFever);

            SetPosition(POS_X1, y += 2);
            timeToDate(info.applyInTime);
            printf("申请进入时间:\t%s", timeBuf);

            SetPosition(POS_X1, y += 2);
            timeToDate(info.applyOutTime);
            printf("申请离开时间:\t%s", timeBuf);

            SetPosition(POS_X1, y += 2);
            timeToDate(info.factInTime);
            printf("实际进入时间:\t%s", timeBuf);

            SetPosition(POS_X1, y += 2);
            timeToDate(info.factOutTime);
            printf("实际离开时间:\t%s", timeBuf);

        }
        SetPosition(POS_X2, y += 2);
    }

    system("pause");
}

#endif //INC_10__MODULES_H

