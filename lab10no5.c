#include <stdio.h>
#include <string.h>

typedef struct {
    char stdID[16];
    char nameSurname[25];
    char username[64];
    char password[64];
} hoststd;

int main() {

    hoststd cs[5] = {
        {"66-040626-2686-9","MR.A","user1","passwd1"},
        {"66-040626-2687-0","MR.B","user2","passwd2"},
        {"66-040626-2688-1","MR.C","user3","passwd3"},
        {"66-040626-2689-2","MR.D","user4","passwd4"},
        {"66-040626-2690-3","MR.E","user5","passwd5"}
    };

    char username[64], password[64];
    int i, found = 0;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for(i = 0; i < 5; i++) {
        if(strcmp(username, cs[i].username) == 0 &&
           strcmp(password, cs[i].password) == 0) {

            printf("Welcome %s\n", cs[i].nameSurname);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Incorrect login or password\n");

    return 0;
}
