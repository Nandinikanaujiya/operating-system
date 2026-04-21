#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

int main() {
    int n, i, j;
    struct Process p[20], temp;
    int total_wt = 0, total_tat = 0;


    printf("Enter number of processes: ");
    scanf("%d", &n);



    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].bt);
    }

    // Sort processes by Arrival Time
for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate Completion, Turnaround, and Waiting Times
    int current_time = 0;
    for (i = 0; i < n; i++) {
        if (current_time < p[i].at)
            current_time = p[i].at; // CPU idle until process arrives

        p[i].ct = current_time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        current_time = p[i].ct;

        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }


    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);


    // Print Gantt Chart
    printf("\nGantt Chart:\n");
    printf("--------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("|  P%d  ", p[i].pid);
    }
    printf("|\n");
    printf("--------------------------------------------------\n");

    // Print timeline
    printf("%d", p[0].at); // start time
    for (i = 0; i < n; i++) {
        printf("     %d", p[i].ct);
    }
    printf("\n");



return 0;
}

