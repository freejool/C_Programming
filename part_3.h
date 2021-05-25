#ifndef INC_9__PART_3
#define INC_9__PART_3
#include "head.h"

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
                    scanf("%5f", &stu[i].score[j]);
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

#endif