#include <stdio.h>
#include "head.h"
#include "conn.h"
#include "modules.h"


//num 4
int main() {
    char str[]="GET /CarService2/GetData?ID=12314 HTTP/1.1\r\nHost: 47.118.51.124:8080\r\n\r\n";
    char recv[65536];
    request(str, recv);
    if(recv[9]=='5') printf("HTTP Status 500 - Internal Server Error\n");
   // printf("%s",recv);

    return 0;
}