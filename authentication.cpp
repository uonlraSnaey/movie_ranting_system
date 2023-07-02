#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct
{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

void registerUser(const char *username, const char *password)
{
    if (userCount >= MAX_USERS)
    {
        printf("已经到达最大登录数，请稍后再试.\n");
        return;
    }

    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;
    printf("注册空间占满，无法注册.\n");
}

int loginUser(const char *username, const char *password)
{
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            printf("Login successful.\n");
            return 1; 
        }
    }

    printf("无效密码或用户名，请重试.\n");
    return 0; 
}

void log_in()
{
    char choice;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
 
    printf("---------- 登录界面-----------\n");
    printf("|       1. 注册              |\n");          
    printf("|       2. 登录              |\n");
    printf("-----------------------------\n");
    printf("     选择你要进行的操作:     ");
    scanf(" %c", &choice);

    switch (choice)
    {
    case '1':
        printf("———————— 用户注册 ————————\n");
        printf("|输入用户名:   >>>>");
        scanf(" %s", username);
        printf("|输入密码 :    >>>>");
        scanf("%s", password);
        printf("——————————————————————————\n");

        registerUser(username, password);
        break;
    case '2':
        printf("———————— 用户登录 ————————\n");
        printf("|       输入用户名:   >>>>");
        scanf("%s", username);
        printf("|        输入密码:    >>>>");
        scanf("%s", password);
        printf("——————————————————————————\n");

        int isLoggedIn = loginUser(username, password);

        if (isLoggedIn)
        {
            // User is logged in, perform further actions
            printf("欢迎！, %s!\n", username);
        }
        else
        {
            // Login failed, handle accordingly
            printf("登录失败，请重试XoX.\n");
        }
        break;
    }
}
