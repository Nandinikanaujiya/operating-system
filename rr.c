#include <stdio.h>

int main() {
    int n, tq, time = 0, completed = 0;
    int at[20], bt[20], rt[20], ct[20], tat[20], wt[20];
    int gantt[100], g = 0;
    float avgTAT = 0, avgWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival time and Burst time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    /* -------- Round Robin Scheduling -------- */
    while (completed < n) {
        int idle = 1;

        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                idle = 0;
                gantt[g++] = i + 1;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    completed++;
                }
            }
        }

        if (idle)
            time++;
    }
    printf("\nGantt Chart:\n|");
    for (int i = 0; i < g; i++) {
        printf(" P%d |", gantt[i]);
    }
    printf("\n");

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgTAT += tat[i];
        avgWT += wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", avgTAT / n);
    printf("\nAverage Waiting Time: %.2f\n", avgWT / n);

    return 0;
}
