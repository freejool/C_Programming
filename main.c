#include <stdio.h>
#include "head.h"
#include "conn.h"
#include "modules.h"

int main() {
    setbuf(stdout, NULL);
    int c;
    char str[20];


    while (1) {
        //alert("1: new record, 2: login, 3: print table, 0: exit");
        c = Menu();

        switch (c) {
            case 1:
                Register(); // 提前录入信息，判断是否符合出入要求
                break;
            case 2:
                Arrival();  // 来访，判断能否进入(判断时间和健康码)，警告
                break;
            case 3:
                departure(); // 离开，判断时间，警告
                break;
            case 4:
                login(); // 管理员登录
                break;
            case 5:
                lookUp(); // 查询信息 要求管理员
                break;
            case 0:
                release();
                return 0;
            default:
                system("cls");
                SetPosition(POS_X2, 5);
                printf("非法输入:%d", c);
                SetPosition(POS_X2, 7);
                system("pause");
        }
    }
}