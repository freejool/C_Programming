#ifndef INC_9__PART_1
#define INC_9__PART_1

#include "head.h"

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
        SetPosition(POS_X1, ++posy);
        for (j = 0; j < 55; j++) {
            printf("-");
        }
    }
    SetPosition(POS_X1, ++posy);
    printf("请选择你想要进行的操作[0~16]:[ ]\b\b");
    scanf("%d", &option);
    return option;
}

void InputRecord(STU stu[], int *n, int *m) {
    int i, j;
    int posy = 6;
    SetPosition(POS_X2, posy);
    printf("输入学生人数(n<%d):", STU_NUM);
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
        printf("输入第%d个学生信息: ", i + 1);
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
#endif
