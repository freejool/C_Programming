#ifndef INC_9__PART_2
#define INC_9__PART_2
#include "head.h"

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
    fscanf(fp, "%10d%10d", n, m);
    for (i = 0; i < *n; i++) {
        fscanf(fp, "%10ld", &stu[i].num);
        fscanf(fp, "%10s", stu[i].name);
        for (j = 0; j < *m; j++) {
            fscanf(fp, "%10f", &stu[i].score[j]);
        }
        fscanf(fp, "%10f%10f", &stu[i].sum, &stu[i].aver);
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
            scanf("%f", &stu[i].score[j]);
        }
    }
    *n = *n + num_record;
    printf("添加完毕!\n");
}

void SearchByNum(STU stu[], int n, int m) {
    long id;
    int i, j;
    printf("请输入你要查找的学生的学号:");
    scanf("%ld", &id);
    for (i = 0; i < n; i++) {
        if (stu[i].num == id) {
            printf("找到了,该学号对应的学生信息为:\n");
            printf("学号\t\t姓名\t\t");
            for (j = 0; j < m; j++) {
                printf("课程%d\t\t", j + 1);
            }
            printf("总分\t\t平均分\n");

            printf("%-16ld%-16s", stu[i].num, stu[i].name);
            for (j = 0; j < m; j++) {
                printf("%-16.1lf", stu[i].score[j]);
            }
            printf("%-16.1lf%-16.1lf\n", stu[i].sum, stu[i].aver);
            //            printf("%10ld%15s",stu[i].num,stu[i].name);
            //            for(j=0;j<m;j++){
            //                printf("%10.2f",stu[i].score[j]);
            //            }
            //            printf("%10.2f%10.2f",stu[i].sum,stu[i].aver);
            return;
        }
    }
    printf("未找到这个学号对应的学生记录\n");
}

void SearchByName(STU stu[], int n, int m) {
    int flag = 1;
    int i, j;
    int k = 0;
    char name[NAME_LEN];
    printf("请输入你要查找的学生的姓名:");
    scanf("%s", name);
    for (i = 0; i < n; i++) {
        if (strcmp(stu[i].name, name) == 0) {
            printf("找到了，第%d学生信息为:\n", ++k);
            printf("学号\t\t姓名\t\t");
            for (j = 0; j < m; j++) {
                printf("课程%d\t\t", j + 1);
            }
            printf("总分\t\t平均分\n");

            printf("%-16ld%-16s", stu[i].num, stu[i].name);
            for (j = 0; j < m; j++) {
                printf("%-16.1lf", stu[i].score[j]);
            }
            printf("%-16.1lf%-16.1lf\n", stu[i].sum, stu[i].aver);
            flag = 0;
        }
    }
    if (flag) {
        printf("未找到这个姓名对应的学生记录\n");
    }
}

void PrintRecord(STU stu[], int n, int m) {
    int i, j;
    printf("学号\t\t姓名\t\t");
    for (j = 0; j < m; j++) {
        printf("课程%d\t\t", j + 1);
    }
    printf("总分\t\t平均分\n");
    for (i = 0; i < n; i++) {
        printf("%-16ld%-16s", stu[i].num, stu[i].name);
        for (j = 0; j < m; j++) {
            printf("%-16.1lf", stu[i].score[j]);
        }
        printf("%-16.1lf%-16.1lf\n", stu[i].sum, stu[i].aver);
    }
}

#endif