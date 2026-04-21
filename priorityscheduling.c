#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], pr[n], ct[n], tat[n], wt[n];
    int temp;

    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Burst Time and Priority for Process P%d: ", pid[i]);
        scanf("%d %d", &bt[i], &pr[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(pr[i] > pr[j]) {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    ct[0] = bt[0];
    for(int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
    }

    for(int i = 0; i < n; i++) {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
    }

    float avgWT = 0, avgTAT = 0;
    for(int i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    printf("\nProcess\tBT\tPriority\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\t%d\n", pid[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    printf("\nGantt Chart:\n|");
    for(int i = 0; i < n; i++) {
        printf("  P%d  |", pid[i]);
    }

    printf("\n0");
    for(int i = 0; i < n; i++) {
        printf("     %d", ct[i]);
    }

    printf("\n");

    return 0;
}
