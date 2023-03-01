#include <stdio.h>
#include <stdlib.h>

int Logined = 0;
int typeLogin = 0; /* 0 is student and 1 is admin */
char *studentIDGLobal;

extern void Login()
{
    system("cls");
    FILE *f;
    f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//students.txt", "r");
    if (f == NULL)
    {
        printf("No students yet");
    }
    int checkLogin = 1;
    int choice = 2;
    char accArr[128];
    char studentID[50];
    char phone[50];
    while (checkLogin == 1)
    {
        printf("Please login\n");
        printf("studentID: ");
        scanf("%s", studentID);
        printf("phone: ");
        scanf("%s", phone);
        printf("Please confirm \n1.login\n2.typing again\nEnter Choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int check = 0;
            char accInput[50];
            strcpy(accInput, studentID);
            strcat(accInput, ":");
            strcat(accInput, phone);
            strcat(accInput, ":");
            if (strstr("admin:admin:", accInput) != NULL)
            {
                check = 1;
                typeLogin = 1;
            }
            else
            {

                while (fgets(accArr, 128, f) != NULL)
                {
                    if (strstr(accArr, accInput) != NULL)
                    {
                        studentIDGLobal = studentID;
                        check = 1;
                        typeLogin = 0;
                        break;
                    }
                }
            }
            if (check == 1)
            {
                Logined = 1;
                checkLogin = 0;
                menu();
                break;
            }
        }
        else
        {
            Login();
            break;
        }
    }
    fclose(f);
}
