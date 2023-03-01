FILE *f;

typedef struct
{
    char bookID[20];
    char title[50];
    char author[50];
    char publication[50];
    char byStudentID[20];
} bookStr;

typedef struct
{
    char studentID[20];
    char name[20];
    char phone[10];
    bookStr bookBorrowed[10];
} studentStr;

extern char *studentIDGLobal;

extern void goBackMenu()
{
    int choice;
    choice = 0;
    while (choice != 1)
    {
        printf("\n\n--------------------------\nPress 1 go back to menu\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            menu();
            break;
        }
    }
}

extern void listBook()
{
    printf("\n-----------List Book-----------\n");
    f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//library.txt", "r");
    char dataFile[512];
    while (fgets(dataFile, 512, f) != NULL)
    {
        printf("%s", dataFile);
    }
    fclose(f);
    goBackMenu();
}

extern void listIssuedBook()
{
    printf("\n-----------Return Book-----------\n");
    printf("This is a list of your borrowed books: \n");
    f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//issueRecord.txt", "r+");
    char dataFile[512];
    char dataBook[500][512];
    char *studentIDFromDataFile;
    char *bookID;
    char *title;
    char *author;
    char *timeIssue;
    char *timeReturn;
    char *timeSecond;
    while (fgets(dataFile, 512, f) != NULL)
    {
        studentIDFromDataFile = strtok(dataFile, "\t");
        bookID = strtok(NULL, "\t");
        title = strtok(NULL, "\t");
        author = strtok(NULL, "\t");
        timeIssue = strtok(NULL, "\t");
        timeReturn = strtok(NULL, "\t");
        timeSecond = strtok(NULL, "\t");
        if (strstr(studentIDFromDataFile, studentIDGLobal) != NULL)
        {
            printf("%s\t%s\t\t\t%s\t%s\t%s\n", bookID, title, author, timeIssue, timeReturn);
        }
    }
    fclose(f);
    goBackMenu();
}

extern void returnBook()
{
    printf("\n-----------Return Book-----------\n");
    printf("\n1. Enter bookID to Return Book\n");
    printf("2. Go back to Menu\n");
    int choice;
    choice = 0;
    f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//issueRecord.txt", "r+");
    while (choice != 1 && choice != 2)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            char bookIDInput[20];
            char dataFile[512];
            char dataBook[500][512];
            printf("Enter BookID: ");
            scanf("%s", bookIDInput);
            char *studentIDFromDataFile;
            char *bookID;
            char *title;
            char *author;
            char *timeIssue;
            char *timeReturn;
            char *timeSecond;
            int count = 0;
            int i = 0;
            while (fgets(dataFile, 512, f) != NULL)
            {
                strcpy(dataBook[i], dataFile);
                i++;
            }
            fseek(f, 0, SEEK_SET);
            while (fgets(dataFile, 512, f) != NULL)
            {
                count++;
                studentIDFromDataFile = strtok(dataFile, "\t");
                bookID = strtok(NULL, "\t");
                title = strtok(NULL, "\t");
                author = strtok(NULL, "\t");
                timeIssue = strtok(NULL, "\t");
                timeReturn = strtok(NULL, "\t");
                timeSecond = strtok(NULL, "\t");
                if (strstr(studentIDFromDataFile, studentIDGLobal) != NULL)
                {
                    if (strstr(bookID, bookIDInput) != NULL)
                    {
                        fclose(f);
                        f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//issueRecord.txt", "w+");
                        for (int j = 0; i < j; j++)
                        {
                            if (j != count - 1)
                            {
                                fprintf(f, "%s", dataBook[j]);
                            }
                        }
                        fclose(f);
                        f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//library.txt", "r+");
                        char *publication;
                        char *status;
                        fseek(f, 0, SEEK_SET);
                        while (fgets(dataFile, 512, f) != NULL)
                        {
                            title = strtok(dataFile, "\t");
                            author = strtok(NULL, "\t");
                            publication = strtok(NULL, "\t");
                            bookID = strtok(NULL, "\t");
                            status = strtok(NULL, "\t");
                            if (strstr(bookID, bookIDInput) != NULL)
                            {
                                fseek(f, -11, SEEK_CUR);
                                fprintf(f, "%s", "Available");
                                break;
                            }
                        }
                        printf("%s", "Return book successful");
                        long long fine;
                        time_t today;
                        time(&today);
                        fine = (today - atoll(timeSecond)) / 86400 * 10000;
                        if (fine > 9999)
                        {
                            printf("You returned the book late. Fine: %lld", fine);
                        }
                        break;
                    }
                    else
                    {
                        printf("%s", "Wrong BookID");
                        menu();
                        break;
                    }
                }
            }
        }
        if (choice == 2)
        {
            menu();
            break;
        }
    }
    fclose(f);
    goBackMenu();
}

extern void issueBook()
{
    printf("\n-----------Issue Book-----------\n");
    printf("1. Enter bookID to Issue Book\n");
    printf("2. Go back to Menu\n");
    int choice;
    choice = 0;
    while (choice != 1 && choice != 2)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            char bookIDInput[20];
            printf("Enter BookID: ");
            scanf("%s", bookIDInput);
            char dataFile[512];
            f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//library.txt", "r+");
            char *title;
            char *author;
            char *publication;
            char *bookID;
            char *status;
            while (fgets(dataFile, 512, f) != NULL)
            {
                title = strtok(dataFile, "\t");
                author = strtok(NULL, "\t");
                publication = strtok(NULL, "\t");
                bookID = strtok(NULL, "\t");
                status = strtok(NULL, "\t");
                if (atoi(bookIDInput) == atoi(bookID))
                {
                    if (strstr(status, "Available") == NULL)
                    {
                        printf("The book is not available");
                        break;
                    }
                    printf("Title: %s\n", title);
                    printf("Author: %s\n", author);
                    printf("Publication: %s\n", publication);
                    printf("BookID: %s\n", bookID);
                    printf("Status: %s\n", status);
                    printf("--------------------\n");
                    int choice1;
                    printf("Do you want to borrow this book ? (Press 0 is Yes and 1 is No)");
                    scanf("%d", &choice1);
                    if (choice1 == 0)
                    {
                        fseek(f, -11, SEEK_CUR);
                        fprintf(f, "%s", "   Issued");
                        fclose(f);
                        time_t dateIssue;
                        time(&dateIssue);
                        time_t dateReturn = dateIssue + 864000;
                        char timeIssue[80];
                        char timeReturn[80];
                        strftime(timeIssue, 80, "%d/%m/%Y", localtime(&dateIssue));
                        strftime(timeReturn, 80, "%d/%m/%Y", localtime(&dateReturn));
                        f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//issueRecord.txt", "a+");
                        fprintf(f, "%s\t%s\t%s\t%s\t%s\t%s\t%lld\n", studentIDGLobal, bookID, title, author, timeIssue, timeReturn, dateIssue);
                        fclose(f);
                        printf("Issue successful this book\n");
                        printf("\nDate issue: %s\n", timeIssue);
                        printf("Date return: %s", timeReturn);
                    }
                    else
                    {
                        menu();
                    }
                    break;
                }
            }
            fclose(f);
            goBackMenu();
        }
        if (choice == 2)
        {
            menu();
            break;
        }
    }
}
extern void addBook()
{
    int n;
    srand(time(NULL));
    bookStr bookNew;
    printf("\n-----------Add Book-----------\n");
    f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//library.txt", "a+");
    if (f == NULL)
    {
        printf("File is not created\n");
        printf("Going back to menu");
    }
    else
    {

        printf("How many book do you want to add: ");
        scanf("%d", &n);
        char temp[10];
        for (int i = 0; i < n; i++)
        {
            gets(temp);
            printf("Enter title: ");
            gets(bookNew.title);
            fprintf(f, "%s\t\t\t", bookNew.title);
            printf("Enter author: ");
            gets(bookNew.author);
            fprintf(f, "%s\t\t", bookNew.author);
            printf("Enter publication: ");
            gets(bookNew.publication);
            fprintf(f, "%s\t", bookNew.publication);
            itoa(rand(), bookNew.bookID, 10);
            fprintf(f, "%s\t", bookNew.bookID);
            fprintf(f, "%s\n", "Available");
            printf("\nAdd book successful. Press enter to continue\n");
        }
    }
    fclose(f);
    goBackMenu();
}
extern void editBook()
{
    printf("\n-----------Edit Book-----------\n");
    printf("1. Enter bookID to edit\n");
    printf("2. Go back to menu\n");
    int choice;
    choice = 0;
    while (choice != 1 && choice != 2)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            char bookIDInput[20];
            printf("Enter BookID: ");
            scanf("%s", bookIDInput);
            char dataFile[512];
            f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//library.txt", "r+");
            char *title;
            char *author;
            char *publication;
            char *bookID;
            char *status;
            int count = 0;
            int deleteBook = 0;
            while (fgets(dataFile, 512, f) != NULL)
            {
                count++;
                int strLen = strlen(dataFile) + 1;
                title = strtok(dataFile, "\t");
                author = strtok(NULL, "\t");
                publication = strtok(NULL, "\t");
                bookID = strtok(NULL, "\t");
                status = strtok(NULL, "\t");
                if (atoi(bookIDInput) == atoi(bookID))
                {
                    printf("Title: %s\n", title);
                    printf("Author: %s\n", author);
                    printf("Publication: %s\n", publication);
                    printf("BookID: %s\n", bookID);
                    printf("Status: %s\n", status);
                    printf("--------------------\n");
                    int choice1;
                    int choice2;
                    printf("Press 1 to edit Title\nPress 2 to edit Author\nPress 3 to edit Publication\nPress 4 to Delete book\nEnter Choice: ");
                    scanf("%d", &choice1);
                    char content[100];
                    if (choice1 != 4)
                    {
                        printf("Please typing info: ");
                        scanf("%s", content);
                    }
                    printf("Are you sure? (0 is yes, 1 is no): ");
                    scanf("%d", &choice2);
                    if (choice2 == 0)
                    {
                        fseek(f, -strLen, SEEK_CUR);

                        if (choice1 == 1)
                        {
                            fprintf(f, "%s\t\t\t%s\t\t%s\t%s\t%s", content, author, publication, bookID, status);
                        }
                        else if (choice1 == 2)
                        {
                            fprintf(f, "%s\t\t%s\t\t%s\t%s\t%s", title, content, publication, bookID, status);
                        }
                        else if (choice1 == 3)
                        {
                            fprintf(f, "%s\t\t%s\t\t%s\t%s\t%s", title, author, content, bookID, status);
                        }
                        else
                        {
                            deleteBook = 1;
                        }
                    }

                    break;
                }
            }
            fclose(f);
            if (deleteBook == 1)
            {
                char dataBook[500][512];
                int i = 0;
                f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//library.txt", "r");
                while (fgets(dataFile, 512, f) != NULL)
                {
                    strcpy(dataBook[i], dataFile);
                    i++;
                }
                fclose(f);
                f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//library.txt", "w+");
                for (int j = 0; j < i; j++)
                {
                    if (j != count - 1)
                    {
                        fprintf(f, "%s", dataBook[j]);
                    }
                }
                fclose(f);
            }

            goBackMenu();
        }
        if (choice == 2)
        {
            menu();
        }
    }
}
extern void expriedBook()
{
    printf("\n-----------Expried Book-----------\n");
}
extern void addStudent()
{
    printf("\n-----------Add Student-----------\n");
    studentStr studentNew;
    srand(time(NULL));

    int checkRegister = 1;
    int choice = 2;
    while (checkRegister == 1)
    {
        itoa(rand(), studentNew.studentID, 10);
        printf("\nstudentID for you: %s\n", studentNew.studentID);
        printf("Type your phone: ");
        scanf("%s", studentNew.phone);
        printf("Type your name: ");
        scanf("%s", studentNew.name);
        printf("please confirm register acc\n1.Confirm\n2.Typing again\n3.Back to menu\nEnter Choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//students.txt", "r");
            if (f != NULL)
            {
                char accArr[50];
                while (fgets(accArr, 128, f) != NULL)
                {
                    if (strstr(accArr, studentNew.phone) != NULL)
                    {
                        printf("Phone registered, please again!\n");
                        choice = 2;
                        break;
                    }
                }
            }
            if (choice != 2)
            {
                checkRegister = 1;
                f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//students.txt", "a+");
                if (f == NULL)
                {
                    f = fopen("C://Users//nghuy//OneDrive//Desktop//Library Management System//students.txt", "w");
                }
                fprintf(f, "%s:%s:%s\n", studentNew.studentID, studentNew.phone, studentNew.name);
                fclose(f);

                printf("Register success please login with:\nstudentID: %s\nphone: %s", studentNew.studentID, studentNew.phone);
                menuManager();
            }
        }
        else if (choice == 3)
        {
            menuManager();
            break;
        }
    }
}
