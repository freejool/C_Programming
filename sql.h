//
// Created by 沈星宇 on 2021/5/23.
// 已弃用
//

#ifndef INC_10__SQL_H
#define INC_10__SQL_H

#include <stdio.h>
#include <mysql/mysql.h>

void testMysql();//测试方法
bool connectMysql();//连接数据库
bool queryDatabase(char sql[]);//查询并输出结果
int outMysql();//输出查询结果
bool updateData(char sql[]);//插入删除修改操作
void freeConnect();//释放资源

MYSQL mysql;
MYSQL_RES *res; // 这个结构代表返回行的一个查询结果集
MYSQL_ROW row; // 一个行数据的类型安全(type-safe)的表示


//连接数据库
bool connectMysql() {
    mysql_init(&mysql);//初始化mysql
    if (!(mysql_real_connect(&mysql,
                             "hankstragic.site",//主机
                             "Sxing",//用户名
                             "4568",//密码
                             "java_test",//数据库名 必须是已经存在的 我的mysql大小写不敏感
                             3306,//端口号 默认的0或者3306
                             NULL, 0//最后两个参数的常用写法 几乎都是这两个
    ))) {
        printf("Error connecting to database: %s\n", mysql_error(&mysql));
        return false;
    } else {
        printf("Connected...\n");
        return true;
    }
}

//所有的数据库操作都是先写个sql语句
//然后用mysql_query(&mysql,query)来完成
//包括创建数据库或表 增删改查
bool updateData(char sql[]) {
    mysql_query(&mysql, "set names utf8");//设置编码格式 否则mysql里中文乱码
    // 执行SQL语句
    // 0 执行成功
    // 1 执行失败
    if (mysql_query(&mysql, sql)) {//mysql_query第二个参数只接受const cahr* 需要将string类型转化
        printf("Update failed ( %s )\n", mysql_error(&mysql));
        return false;
    } else {
        printf("Update success...\n");
        return true;
    }
}

//查询并输出
bool queryDatabase(char sql[]) {
//    mysql_query(&mysql, "set names gbk");//设置编码格式 否则cmd下中文乱码
    // 执行SQL语句
    // 0 执行成功
    // 1 执行失败
    if (mysql_query(&mysql, sql)) {//mysql_query第二个参数只接受const cahr* 需要将string类型转化
        printf("Query failed ( %s )\n", mysql_error(&mysql));
        return false;
    } else {
        printf("query success\n");
    }

    //获得结果集 MYSQL_RES *res;
    if (!(res = mysql_store_result(&mysql))) {
        printf("Couldn't get result from %s\n", mysql_error(&mysql));
        return false;
    }
    outMysql();//打印结果
    return true;
}

//输出结果
int outMysql() {
    char query[] = "select * from info";
    int rc = mysql_real_query(&mysql, query, strlen(query));
    if (0 != rc) {
        printf("mysql_real_query(): %s\n", mysql_error(&mysql));
        return -1;
    }
    res = mysql_store_result(&mysql);
    if (NULL == res) {
        printf("mysql_restore_result(): %s\n", mysql_error(&mysql));
        return -1;
    }
    int rows = mysql_num_rows(res);
    printf("The total rows is: %d\n", rows);
    int fields = mysql_num_fields(res);
    printf("The total fields is: %d\n", fields);
    while ((row = mysql_fetch_row(res))) {
        for (int i = 0; i < fields; i++) {
            printf("%s\t", row[i]);
        }
        printf("\n");
    }
    mysql_close(&mysql);
    return 0;
}

//释放资源
void freeConnect() {
    mysql_free_result(res);
    mysql_close(&mysql);
}


#endif //INC_10__SQL_H
