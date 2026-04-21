#include <stdio.h>
#include <stdlib.h>

int main()
{
    int requests[100], visited[100];
    int n, head, i, j;
    int seek = 0, min, index, distance;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n; i++)
    {
        min = 9999;

        for(j = 0; j < n; j++)
        {
            if(!visited[j])
            {
                distance = abs(requests[j] - head);
                if(distance < min)
                {
                    min = distance;
                    index = j;
                }
            }
        }

        seek = seek + min;
        head = requests[index];
        visited[index] = 1;
    }

    printf("Total Seek Time = %d\n", seek);

    return 0;
}