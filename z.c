#include <stdio.h>
#include "sqlite3.h"

int main(){

    sqlite3* db;
    int result = sqlite3_open("test_db", &db);
    printf("Connecting to the server...\n");
    if(result == 0) printf("The connection is successful!\n");
    sqlite3_close(db);
    printf("Disconnecting from the database is successful!\n");

    return 0;
}