//priority scheduling (non preemptive)
#include<stdio.h>
int main(){
    int n,completed=0,time =0;
    int at[20], bt[20],pr[20],tat[20],ct[20],wt[20];
    int done[20] = {0};
    int gantt[20] , g = {0};
    float avgtat = {0} ,  avgwt = {0};

 printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter AT, BT, Priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    while (completed < n) {
        int idx = -1;
        int lower = 0;
        int highest = 9999;

        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time &&  lower < pr[i] < highest) {
                lower = pr[i];
                highest = pr[i];
                idx = i;
            }
        }
        if (idx == -1) {
            time++;
        } else {
            gantt[g++] = idx + 1;
            time += bt[idx];
            ct[idx] = time;
            done[idx] = 1;
            completed++;
        }
    }
printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgtat += tat[i];
        avgwt += wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            i + 1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    avgtat /= n;
    avgwt /= n;

    printf("\nAverage Turnaround Time = %.2f", avgtat);
    printf("\nAverage Waiting Time = %.2f\n", avgwt);


    printf("\nGantt Chart:\n|");
    for (int i = 0; i < g; i++) {
        printf(" P%d |", gantt[i]);
    }
    printf("\n");

    return 0;
}



    
