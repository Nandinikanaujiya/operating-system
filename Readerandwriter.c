#include <stdio.h>

int mutex = 1;
int wrt = 1;
int read_count = 0;

void wait(int *s)
{
    while (*s <= 0);
    (*s)--;
}

void signal(int *s)
{
    (*s)++;
}

void reader()
{
    wait(&mutex);
    read_count++;
    if (read_count == 1)
        wait(&wrt);
    signal(&mutex);

    printf("Reader is reading\n");

    wait(&mutex);
    read_count--;
    if (read_count == 0)
        signal(&wrt);
    signal(&mutex);
}

void writer()
{
    wait(&wrt);

    printf("Writer is writing\n");

    signal(&wrt);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Reader\n2. Writer\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                reader();
                break;
            case 2:
                writer();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}