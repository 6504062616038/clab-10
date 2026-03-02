#include <stdio.h>
#include <string.h>

#define NUM_USERS 5

typedef struct {
    char loginname[64];
    char password[64];
} account;

typedef struct {
    char stdID[16];
    char nameSurname[25];
    account stdACC;
} hoststd;

int checkLogin(char *login, char *passwd, hoststd users[], int num_users) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(login, users[i].stdACC.loginname) == 0 && strcmp(passwd, users[i].stdACC.password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    hoststd cs[NUM_USERS] = {
        {"66-040626-2686-9", "MR.A", {"user1", "pass1"}},
        {"66-040626-2687-0", "MR.B", {"user2", "pass2"}},
        {"66-040626-2687-1", "MR.C", {"user3", "pass3"}},
        {"66-040626-2687-2", "MR.D", {"user4", "pass4"}},
        {"66-040626-2697-3", "MR.E", {"user5", "pass5"}}
    };
    
    char login[64], password[64];
    
    printf("Enter login: ");
    fgets(login, sizeof(login), stdin);
    login[strcspn(login, "\n")] = 0; 
    
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; 
    
    if (checkLogin(login, password, cs, NUM_USERS)) {
        printf("Welcome\n");
    } else {
        printf("Incorrect login or password\n");
    }
    
    return 0;
}


