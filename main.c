#include "head.h"
#include "part_1.h"
#include "part_2.h"
#include "part_3.h"

int main()
{
    int n = 0;
    int m = 0;
    int i, j;
    char ch;
    int first = 1;
    STU stu[STU_NUM];

    system("mode con cols=130 lines=60");
    system("color 0E");
    while (1)
    {
        system("cls");
        ch = Menu();
        switch (ch)
        {
        case 1:
            system("cls");
            InputRecord(stu, &n, &m);
            first = 0;
            break;
        case 2:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息,请先输入!\n");
                system("pause");
                break;
            }
            AppendRecord(stu, &n, m);
            system("pause");
            break;
        case 3:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息,请先输入!\n");
                system("pause");
                break;
            }
            DeleteRecord(stu, &n, m);
            system("pause");
            break;
        case 4:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息,请先输入!\n");
                system("pause");
                break;
            }
            SearchByNum(stu, n, m);
            system("pause");
            break;
        case 5:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息,请先输入!\n");
                system("pause");
                break;
            }
            SearchByName(stu, n, m);
            system("pause");
            break;
        case 6:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息,请先输入!\n");
                system("pause");
                break;
            }
            ModifyRecord(stu, n, m);
            system("pause");
            break;
        case 7:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息,请先输入!\n");
                system("pause");
                break;
            }
            CalculateScoreOfStudent(stu, n, m);
            system("pause");
            break;
        case 8:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息,请先输入!\n");
                system("pause");
                break;
            }
            CalculateScoreOfCourse(stu, n, m);
            getch();
            break;
        case 9:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息,请先输入!\n");
                getch();
                break;
            }
            SortByNum(stu, n, m);
            getch();
            break;
        case 10:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息,请先输入!\n");
                getch();
                break;
            }
            SortByName(stu, n, m);
            getch();
            break;
        case 11:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息,请先输入!\n");
                getch();
                break;
            }
            SortByScore(stu, n, m, Descending);
            getch();
            break;
        case 12:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息,请先输入!\n");
                getch();
                break;
            }
            SortByScore(stu, n, m, Ascending);
            getch();
            break;
        case 13:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息,请先输入!\n");
                getch();
                break;
            }
            StatisticAnalysis(stu, n, m);
            getch();
            break;
        case 14:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息,请先输入!\n");
                getch();
                break;
            }
            PrintRecord(stu, n, m);
            getch();
            break;
        case 15:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息,请先输入!\n");
                getch();
                break;
            }
            WriteToFile(stu, n, m);
            getch();
            break;
        case 16:
            system("cls");
            if (ReadFromFile(stu, &n, &m, &first) || first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息或文件打开失败,请先检查!\n");
                getch();
                break;
            }
            getch();
            break;
        case 0:
            system("cls");
            printf("退出系统\n");
            exit(0);
        default:
            printf("输入出错，请重新选择操作!\n");
            system("pause");
        }
    }
    return 0;
}