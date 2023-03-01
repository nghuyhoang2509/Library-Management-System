#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menuManager();
void menu();

#include "feature.c"
#include "auth.c"
#include "manager.c"
#include "student.c"

extern void Login();
extern void manager();
extern void student();
extern int Logined;
extern int typeLogin;
extern char *studentIDGlobal;

extern void menu()
{
    if (Logined == 1)
    {
        if (typeLogin == 1)
        {
            manager();
        }
        else
        {
            student();
        }
    }
    else
    {
        Login();
    }
}

int main()
{
    // Login();
    menu();
}
