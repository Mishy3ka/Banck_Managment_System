#include <stdio.h>
#include "sqlite3.h"

int insert_people(sqlite3* db, const char* name,const int age){
    char sql[256];
    char* errmsg = 0;

    snprintf(sql, sizeof(sql), "INSERT INTO people (name, age) VALUES ('%s', %d)", name, age);

    int rc =sqlite3_exec(db, sql, 0, 0, &errmsg);
    if(rc != SQLITE_OK){
        printf("SQL error: %s", errmsg);
        sqlite3_free(errmsg);
        return 1;
    }
    return 0;
}

int main(){

    sqlite3* db;
    char* err_msg = 0;
    int result = sqlite3_open("test.db", &db);
    printf("Connecting to the server...\n");
    if(result != SQLITE_OK){
    printf("The connection is failed!\n");
    sqlite3_close(db);
    return 1;
    }

    char* sql = "CREATE TABLE IF NOT EXISTS people (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER);";

    result = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if(result != SQLITE_OK) {
        printf("SQL erorr: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    if(insert_people(db, "Tom", 32) != 0){
        sqlite3_close(db);
        return 1;
    }else{
        printf("Line added successfully");
    }
    
    
    sqlite3_close(db);
    printf("Table created!\n");

    return 0;
}

