#include <stdio.h>

int main() {
    int n, completed = 0, time = 0;
    int at[10], bt[10], pr[10], ct[10], tat[10], wt[10];
    int done[10] = {0};
    int gantt[10], g = 0;//g index counter
    float avgTAT = 0, avgWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter AT, BT, Priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    while (completed < n) {
        int idx = -1;
        int highest = 9999;

        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time && pr[i] < highest) {
                highest = pr[i];
                idx = i;
            }
        }

        if (idx == -1) {
            time++; // CPU idle
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

        avgTAT += tat[i];
        avgWT += wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            i + 1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    avgTAT /= n;
    avgWT /= n;

    printf("\nAverage Turnaround Time = %.2f", avgTAT);
    printf("\nAverage Waiting Time = %.2f\n", avgWT);

    printf("\nGantt Chart:\n|");
    for (int i = 0; i < g; i++) {
        printf(" P%d |", gantt[i]);
    }
    printf("\n");

    return 0;
}
