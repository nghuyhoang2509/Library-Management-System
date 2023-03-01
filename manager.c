void menuManager()

{
    int select;
    printf("\n-----------Menu------------\n");
    printf("press 1 for list book\n");
    printf("press 2 for add book\n");
    printf("press 3 for edit book\n");
    printf("press 4 for book expried\n");
    printf("press 5 for add student\n");
    printf("------------------------\n");
    printf("Enter your select: ");
    scanf("%d", &select);
    switch (select)
    {
    case 1:
        listBook();
        break;

    case 2:
        addBook();
        break;

    case 3:
        editBook();
        break;

    case 4:
        expriedBook();
        break;

    case 5:
        addStudent();
        break;

    default:
        printf("input vaild please type again");
        menuManager();
        break;
    }
}

extern void manager()
{
    menuManager();
}
