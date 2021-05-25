#include <stdio.h>
#include "head.h"


int main() {
    // 1: new record, 2: login, 3: print table, 0: exit
    char c;
    init();
    while (1) {
        alert("1: new record, 2: login, 3: print table, 0: exit");
        while (!((c = getchar()) >= '0' && c <= '3'));

            switch (c) {
                case '1':
                    newInfo();
                    break;
                case '2':
                    login();
                    break;
                case '3':
                    printTable();
                    break;
                case '0':
                    freeResource();
                    return 0;
                case 10:
                    break;
                default:
                    alert("Wrong input!");
            }
    }
}
