
#ifndef INC_9__HEAD_H
#define INC_9__HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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

int Ascending(float a, float b) { return a < b; }        // 升序排序
int Descending(float a, float b) { return a > b; }       // 降序排序
void StatisticAnalysis(STU stu[], int n, int m);         // 统计并输出各个分数段学生人数及占比
void PrintRecord(STU stu[], int n, int m);               // 打印学生成绩
void WriteToFile(STU stu[], int n, int m);               // 保存至文件
int ReadFromFile(STU stu[], int *n, int *m, int *first); // 读取学生信息

void SetPosition(int x, int y) {
    HANDLE hOut;
    COORD pos;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut, pos);
}

#endif //INC_9__HEAD_H
