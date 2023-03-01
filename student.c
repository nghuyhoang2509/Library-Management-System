void menuStudent()
{
    int select;
    printf("\n-----------Menu------------\n");
    printf("press 1 for list book\n");
    printf("press 2 for return book\n");
    printf("press 3 for issue book\n");
    printf("press 4 for list issued book\n");
    printf("------------------------\n");
    printf("Enter your select: ");
    scanf("%d", &select);
    switch (select)
    {
    case 1:
        listBook();
        break;

    case 2:
        returnBook();
        break;

    case 3:
        issueBook();
        break;

    case 4:
        listIssuedBook();
        break;

    default:
        printf("input vaild please type again");
        menuStudent();
        break;
    }
}

extern void student()
{
    menuStudent();
}