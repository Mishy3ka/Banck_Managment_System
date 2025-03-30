#include <stdio.h>
#include "sqlite3.h"

int main(){

    sqlite3* db;
    int result = sqlite3_open("test_db", &db);
    printf("result = %d\n", result);
    sqlite3_close(db);

    return 0;
}