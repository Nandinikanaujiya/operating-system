#include <stdio.h>

int buffer[5];
int in = 0;
int out = 0;
int item = 1;
int count = 0;

void producer()
{
    if (count == 5)
    {
        printf("Buffer is Full! Producer can't produce.\n");
    }
    else
    {
        buffer[in] = item;
        printf("Producer produced item: %d\n", item);

        item++;
        in = (in + 1) % 5;
        count++;
    }
}

void consumer()
{
    if (count == 0)
    {
        printf("Buffer is Empty! Consumer can't consume.\n");
    }
    else
    {
        int consumed = buffer[out];
        printf("Consumer consumed item: %d\n", consumed);

        out = (out + 1) % 5;
        count--;
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Producer Consumer Menu ---\n");
        printf("1. Produce\n");
        printf("2. Consume\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            producer();
        else if (choice == 2)
            consumer();
        else if (choice == 3)
            break;
        else
            printf("Invalid choice!\n");
    }

    return 0;
}
