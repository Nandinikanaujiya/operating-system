#include <stdio.h>

#define MAX 10

int main()
{
    int n, m;
    int i, j, k;

    int allocation[MAX][MAX];
    int max[MAX][MAX];
    int need[MAX][MAX];
    int available[MAX];
    int finish[MAX] = {0};
    int safeSequence[MAX];
    int work[MAX];
    int count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Max Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    for(i = 0; i < m; i++)
    {
        work[i] = available[i];
    }

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                        break;
                }

                if(j == m)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                    }

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            printf("\nSystem is NOT in Safe State.\n");
            return 0;
        }
    }

    printf("\nSystem is in Safe State.\nSafe Sequence: ");
    for(i = 0; i < n; i++)
    {
        printf("P%d ", safeSequence[i]);
    }

    printf("\n");
    return 0;
}