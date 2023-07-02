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
        printf("�Ѿ���������¼�������Ժ�����.\n");
        return;
    }

    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;
    printf("ע��ռ�ռ�����޷�ע��.\n");
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

    printf("��Ч������û�����������.\n");
    return 0; 
}

void log_in()
{
    char choice;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
 
    printf("---------- ��¼����-----------\n");
    printf("|       1. ע��              |\n");          
    printf("|       2. ��¼              |\n");
    printf("-----------------------------\n");
    printf("     ѡ����Ҫ���еĲ���:     ");
    scanf(" %c", &choice);

    switch (choice)
    {
    case '1':
        printf("���������������� �û�ע�� ����������������\n");
        printf("|�����û���:   >>>>");
        scanf(" %s", username);
        printf("|�������� :    >>>>");
        scanf("%s", password);
        printf("����������������������������������������������������\n");

        registerUser(username, password);
        break;
    case '2':
        printf("���������������� �û���¼ ����������������\n");
        printf("|       �����û���:   >>>>");
        scanf("%s", username);
        printf("|        ��������:    >>>>");
        scanf("%s", password);
        printf("����������������������������������������������������\n");

        int isLoggedIn = loginUser(username, password);

        if (isLoggedIn)
        {
            // User is logged in, perform further actions
            printf("��ӭ��, %s!\n", username);
        }
        else
        {
            // Login failed, handle accordingly
            printf("��¼ʧ�ܣ�������XoX.\n");
        }
        break;
    }
}
