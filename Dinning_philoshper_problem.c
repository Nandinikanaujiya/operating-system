#include <stdio.h>

#define N 5

int chopstick[N] = {1,1,1,1,1};

void dine(int i)
{
    printf("\nPhilosopher %d is thinking\n", i);

    if(chopstick[i] == 1 && chopstick[(i+1)%N] == 1)
    {
        chopstick[i] = 0;
        chopstick[(i+1)%N] = 0;

        printf("Philosopher %d picked chopsticks %d and %d\n", i, i, (i+1)%N);
        printf("Philosopher %d is eating\n", i);

        chopstick[i] = 1;
        chopstick[(i+1)%N] = 1;

        printf("Philosopher %d finished eating\n", i);
    }
    else
    {
        printf("Philosopher %d cannot eat (Chopsticks not available)\n", i);
    }
}

int main()
{
    int i;

    for(i = 0; i < N; i++)
    {
        dine(i);
    }

    return 0;
}