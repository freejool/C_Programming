//
// Created by 沈星宇 on 2021/5/19.
//

#ifndef INC_9__HEAD_H
#define INC_9__HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define STU_NUM 50
#define COURSE_NUM 10
#define NAME_LEN 10
#define POS_X1 35
#define POS_X2 40
#define POS_X3 50
#define POS_X4 65
#define POS_Y 3

typedef struct student {
    long num;
    char name[NAME_LEN];
    float score[COURSE_NUM]; // 各门课程
    float sum;
    float aver; // 各门课程平均分
} STU;

typedef struct _COORD {
    SHORT x;
    SHORT y;
} COORD, *PCOORD;

int Menu(); // 操作菜单
void SetPosition(int x, int y);

void InputRecord(STU stu[], int *n, int *m);                                 // 输入学生信息
void AppendRecord(STU stu[], int *n, int m);                                 // 增加学生信息
void DeleteRecord(STU stu[], int *n, int m);                                 // 删除学生记录
void SearchByNum(STU stu[], int n, int m);                                   // 按学号查询学生信息
void SearchByName(STU stu[], int n, int m);                                  // 按姓名查询
void ModifyRecord(STU stu[], int n, int m);                                  // 修改学生信息
void CalculateScoreOfStudent(STU stu[], int n, int m);                       // 计算学生的总分和平均分
void CalculateScoreOfCourse(STU stu[], int n, int m);                        // 计算某门课程的总分和平均分
void SortByNum(STU stu[], int n, int m);                                     // 按学号排序
void SortByName(STU stu[], int n, int m);                                    // 按姓名排序
void SortByScore(STU stu[], int n, int m, int (*compare)(float a, float b)); // 按每个学生平均分进行排序

int Ascending(float a, float b) { return a < b; }                           // 升序排序
int Descending(float a, float b) { return a > b; }                           // 降序排序
void StatisticAnalysis(STU stu[], int n, int m);            // 统计并输出各个分数段学生人数及占比
void PrintRecord(STU stu[], int n, int m);                  // 打印学生成绩
void WriteToFile(STU stu[], int n, int m);               // 保存至文件
int ReadFromFile(STU stu[], int *n, int *m, int *first); // 读取学生信息

void SetPosition(int x, int y) {
    HANDLE hOut;
    COORD pos;
    hOut - GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPodition(hOut, pos);
}

int Menu() {
    int posy = 5;
    int option;
    int i, j;
    SetPosition(POS_X3, posy);
    printf("学生成绩管理系统\n");
    for (i = 0; i < 2; i++) {
        SetPosition(POS_X1, ++posy);
        for (j = 0; j < 55; j++) {
            printf("-");
        }
    }
    SetPosition(POS_X1, ++posy);
    printf("1.输入学生信息");
    SetPosition(POS_X4, posy);
    printf("2.增加学生成绩");
    SetPosition(POS_X1, posy += 2);
    printf("3.删除学生信息");
    SetPosition(POS_X4, posy);
    printf("4.按学号查找记录");
    SetPosition(POS_X1, posy += 2);
    printf("5.按姓名查找记录");
    SetPosition(POS_X4, posy);
    printf("6.修改学生信息");
    SetPosition(POS_X1, posy += 2);
    printf("7.计算学生成绩");
    SetPosition(POS_X4, posy);
    printf("8.计算课程成绩");
    SetPosition(POS_X1, posy += 2);
    printf("9.按学号排序");
    SetPosition(POS_X4, posy);
    printf("10.按姓名排序");
    SetPosition(POS_X1, posy += 2);
    printf("11.按总成绩降序排序");
    SetPosition(POS_X4, posy);
    printf("12.按总成绩升序排序");
    SetPosition(POS_X1, posy += 2);
    printf("13.学生成绩统计");
    SetPosition(POS_X4, posy);
    printf("14.打印学生记录");
    SetPosition(POS_X1, posy += 2);
    printf("15.学生记录存盘");
    SetPosition(POS_X4, posy);
    printf("16.从磁盘读取学生记录");
    SetPosition(POS_X1, posy += 2);
    printf("0.退出");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 55; j++) {
            printf("-");
        }
    }
    SetPosition(POS_X1, ++posy);
    printf("请选择你想要进行的操作[0~16]:[ ]\b\b\b");
    scanf("%d", &option);
    return option;
}

void InputRecord(STU stu[], int *n, int *m) {
    int i, j;
    int posy = 6;
    SetPosition(POS_X2, posy);
    printf("输入学生人数(n<%d)", STU_NUM);
    scanf("%d", n);
    SetPosition(POS_X2, posy += 2);
    printf("输入课程门数(m<%d):", COURSE_NUM);
    scanf("%d", m);
    for (i = 0; i < 2; i++) {
        SetPosition(POS_X1, ++posy);
        for (j = 0; j < 55; j++) {
            printf("-");
        }
    }
    SetPosition(POS_X2, ++posy);
    for (j = 0; j < 55; j++) {
        printf("-");
    }
    SetPosition(POS_X2, ++posy);
    printf("输入学生的学号、姓名和各门课程成绩:");
    for (i = 0; i < *n; ++i) {
        SetPosition(POS_X2, ++posy);
        printf("输入第%d个学生信息:\t", i + 1);
        scanf("%ld%s", &stu[i].num, stu[i].name);
        for (j = 0; j < *m; j++) {
            scanf("%f", &stu[i].score[j]);
        }
    }
}

void DeleteRecord(STU stu[], int *n, int m) {
    int i, j;
    long id;
    char ch;
    printf("请输入你要删除学生信息对应的学号:");
    scanf("%ld", &id);
    for (i = 0; i < *n; i++) {
        if (stu[i].num == id) {
            printf("%10ld%15s", stu[i].num, stu[i].name);
            for (j = 0; j < m; j++) {
                printf("%10.2f", stu[i].score[j]);
            }
            printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);
            printf("请确认是否需要删除这条记录?(Y/y或N/n):");
            getchar();
            scanf("%c", &ch);
            if (ch == 'Y' || ch == 'y') {
                for (j = 0; j < *n - 1; j++) {
                    stu[j] = stu[j + 1];
                }
                (*n)--;
                printf("删除完毕\n");
                return;
            } else if (ch == 'N' || ch == 'n') {
                printf("找到了该学生记录,但不删除\n");
                return;
            } else {
                printf("输入出错!\n");
                return;
            }
        }
    }
    printf("未找到该生记录!\n");
    return;
}

void CalculateScoreOfStudent(STU stu[], int n, int m) {
    int i, j;
    printf("每个学生各门课程的总分的平均分为:\n");
    for (i = 0; i < n; i++) {
        stu[i].sum = 0;
        for (j = 0; j < m; j++) {
            stu[i].sum += stu[i].score[j];
        }
        stu[i].aver = stu[i].sum / m;
        printf("第%d个学生:总分=%.2f,平均分=%.2f\n", i + 1, stu[i].sum, stu[i].aver);
    }
}

void CalculateScoreOfCourse(STU stu[], int n, int m) {
    int i, j;
    float sum[COURSE_NUM], aver[COURSE_NUM];
    int posy = 7;
    SetPosition(POS_X1, posy);
    printf("各门课程的总分和平均分的计算结果为:");
    for (j = 0; j < m; j++) {
        sum[j] = 0;
        for (i = 0; i < n; i++)
            sum[j] += stu[i].score[j];
        aver[j] = sum[j] / n;
        SetPosition(POS_X1, ++posy);
        printf("第%d门课程:总分=%2f,平均分=%.2f\n", j + 1, sum[j], aver[j]);
    }
}

void WriteToFile(STU stu[], int n, int m) {
    int i, j;
    FILE *fp;
    if ((fp = fopen("student.txt", "w")) == NULL) {
        printf("文件student.txt无法打开");
        exit(0);
    }
    fprintf(fp, "%10d%10d\n", n, m);
    for (i = 0; i < n; i++) {
        fprintf(fp, "%10ld%10s\n", stu[i].num, stu[i].name);
        for (j = 0; j < m; j++) {
            fprintf(fp, "%10.lf", stu[i].score[j]);
        }
        fprintf(fp, "%10.lf%10.lf\n", stu[i].sum, stu[i].aver);
    }
    fclose(fp);
    printf("存盘完毕!\n");
}

int ReadFromFile(STU stu[], int *n, int *m, int *first) {
    FILE *fp;
    int i, j;
    int posy = 8;
    SetPosition(POS_X1, posy);
    if ((fp = fopen("student.txt", "r")) == NULL) {
        printf("磁盘文件student.txt无法打开");
        return 1;
    }
    fscanf(fp, "%10d10d", n, m);
    for (i = 0; i < *n; i++) {
        fscanf(fp, "%10ld", &stu[i].num);
        fscanf(fp, "%10s", stu[i].name);
        for (j = 0; j < *m; j++) {
            fscanf(fp, "%10f", &stu[i].score[j]);
        }
        fscanf(fp, "%10f%10f", &stu[i], sum, &stu[i].aver);
        *first = 0;
        fclose(fp);
        printf("数据从磁盘读取完毕!");
        return 0;
    }
}

void AppendRecord(STU stu[], int *n, int m) {
    int i, j;
    int num_record;
    printf("请输入需要增加的学生记录条数:");
    scanf("%d", &num_record);
    while (*n + num_record > STU_NUM) {
        printf("要增加的记录条数太多,请重新输入");
        scanf("%d", &num_record);
    }
    for (i = *n; i < *n + num_record; i++) {
        printf("输入第%d个学生信息:\t", i + 1);
        scanf("%ld%s", &stu[i].num, stu[i].name);
        for (j = 0; j < m; j++) {
            scanf("%f" & stu[i].score[j]);
        }
    }
    *n=*n+num_record;
    printf("添加完毕!\n");
    return;
}

void SearchByNum(STU stu[], int n, int m){
    long id;
    int i,j;
    printf("请输入你要查找的学生的学号:");
    scanf("%ld",&id);
    for(i=0;i<n;i++){
        if(stu[i].num==id){
            printf("找到了,该学号对应的学生信息为:\n");
            printf("%10ld%15s",stu[i].num,stu[i].name);
            for(j=0;j<m;j++){
                printf("%10.2f",stu[i].score[j]);
            }
            printf("%10.2f%10.2f",stu[i].sum,stu[i].aver);
            return;
        }
    }
    printf("未找到这个学号对应的学生记录\n");
    return;
}

void SearchByName(STU stu[], int n, int m){
    int flag=1;
    int i,j;
    int k=0;
    char name[NAME_LEN];
    printf("请输入你要查找的学生的姓名:");
    scanf("%s",name);
    for (i = 0; i <n ; i++) {
        if(strcmp(stu[i].name,name)==0){
            printf("找到了，第%d学生信息为:\n",++k);
            printf("%10ld%15s",stu[i].num,stu[i].name);
            for(j=0;j<m;j++){
                printf("%10.2f",stu[i].score[j]);
            }
            printf("%10.2f%10.2f\n",stu[i].sum,stu[i].aver);
            flag=0;
        }
    }
    if(flag){
        printf("未找到这个姓名对应的学生记录\n");
    }
    return;
}

void PrintRecord(STU stu[], int n, int m){
    int i,j;
    printf("学号\t\t姓名\t\t");
    for(j=0;j<m;j++){
        printf("课程%d\t\t",j+1);
    }
    printf("总分\t\t平均分\n");
    for(i=0;i<n;i++){
        printf("%-16ld%-16s",stu[i].num,stu[i].name);
        for(j=0;j<m;j++){
            printf("%-16.1lf",stu[i].score[j]);
        }
        printf("%-16.1lf%-16.1lf\n",stu[i].sum,stu[i].aver);
    }
    return;
}


void ModifyRecord(STU stu[], int n, int m) {
    int i, j;
    long id;
    char ch;

    printf("请输入需要修改信息对应的学号:");
    scanf("%ld", &id);

    for (i = 0; i < n; i++) {
        if (stu[i].num == id) {
            printf("找到了该生记录,信息为:\n");
            printf("%10ld%15s", stu[i].num, stu[i].name);
            for (j = 0; j < m; j++) {
                printf("%10.2f", stu[i].score[j]);
            }
            printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);
            printf("请确认是否需要修改(Y/y或N/n):");
            getchar();
            scanf("%c", &ch);
            if (ch == 'Y' || ch == 'y') {
                printf("请输入要修改的学生信息:");
                scanf("%ld%s", &stu[i].num, stu[i].name);
                stu[i].sum = 0;
                for (j = 0; j < m; j++) {
                    scanf("5f", &stu[i].score[j]);
                    stu[i].sum += stu[i].score[j];
                }
                stu[i].aver = stu[i].sum / m;
                printf("修改完毕\n");
                return;
            } else if (ch == 'N' || ch == 'n') {
                printf("找到了该生记录,但不修改\n");
                return;
            } else {
                printf("输入出错!\n");
                return;
            }
        }
    }
    printf("未找到该生记录!\n");
    return;
}

void SortByName(STU stu[], int n, int m) {
    int i, j;
    STU temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(stu[i].name, stu[j + 1].name) > 0) {
                temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    printf("按姓名字典对学生记录排序完毕");
    return;
}

void SortByNum(STU *stu, int n, int m) {
    int i, j;
    int k;
    STU temp;

    for (i = 0; i < n; i++) {
        k = i;
        for (j = 0; j < n; j++) {
            if (stu[j].num < stu[k].num)
                k = j;
        }
        if (k != i) {
            temp = stu[k];
            stu[k] = stu[i];
            stu[i] = temp;
        }
    }
    printf("按学号从小到大对学生记录排序完毕");
    return;
}

void SortByScore(STU *stu, int n, int m, int (*compare)(float a, float b)) {
    int i, j;
    int k;
    STU temp;
    for (i = 0; i < n; ++i) {
        k = i;
        for (j = i + 1; j < n; j++) {
            if ((*compare)(stu[j].sum, stu[k].sum))
                k = j;
        }
        if (k != i) {
            temp = stu[k];
            stu[k] = stu[i];
            stu[i] = temp;
        }
    }
    printf("按总分对学生记录升序排序完毕");
}

void StatisticAnalysis(STU *stu, int n, int m) {
    int i, j, t[6];
    for (j = 0; j < m; j++) {
        printf("\n课程%d成绩统计结果为:\n", j + 1);
        printf("分数段\t人数\t占比\n");

        memset(t, 0, sizeof(t));
        for (i = 0; i < n; i++) {
            if (stu[i].score[j] >= 0 && stu[i].score[j] < 60)
                t[0]++;
            else if (stu[i].score[j] < 70)
                t[1]++;
            else if (stu[i].score[j] < 80)
                t[2]++;
            else if (stu[i].score[j] < 90)
                t[3]++;
            else if (stu[i].score[j] < 100)
                t[4]++;
            else if (stu[i].score[j] == 100)
                t[5]++;
        }
        for (i = 0; i < 6; i++) {
            if (i == 0)
                printf("<60\t%d\t%.2f%%\n", t[i], (float) t[i] / n * 100);
            else if (i == 5)
                printf("100\t%d\t%.2f%%\n", t[i], (float) t[i] / n * 100);
            else
                printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float) t[i] / n * 100);
        }
    }
    printf("\n学生成绩平均分统计结果为:\n");
    printf("分数段\t人数\t占比\n");
    memset(t, 0, sizeof(t));
    for (i = 0; i < n; i++) {
        if (stu[i].aver >= 0 && stu[i].aver < 60)
            t[0]++;
        else if (stu[i].aver < 70)
            t[1]++;
        else if (stu[i].aver < 80)
            t[2]++;
        else if (stu[i].aver < 90)
            t[3]++;
        else if (stu[i].aver < 100)
            t[4]++;
        else if (stu[i].aver == 100)
            t[5]++;
    }
    for (i = 0; i < 6; i++) {
        if (i == 0)
            printf("<60\t%d\t%.2f%%\n", t[i], (float) t[i] / n * 100);
        else if (i == 5)
            printf("100\t%d\t%.2f%%\n", t[i], (float) t[i] / n * 100);
        else
            printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float) t[i] / n * 100);

    }
}

#endif //INC_9__HEAD_H
