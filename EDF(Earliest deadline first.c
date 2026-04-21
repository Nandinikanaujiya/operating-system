#include <stdio.h>

#define MAX 10

typedef struct {
    int id;
    int period;
    int execution;
    int remaining;
    int next_release;
    int deadline;
} Task;

int main() {
    int n, time_limit;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    Task t[MAX];

    for (int i = 0; i < n; i++) {
        t[i].id = i + 1;
        printf("\nTask %d:\n", i + 1);
        printf("Execution time: ");
        scanf("%d", &t[i].execution);
        printf("Period: ");
        scanf("%d", &t[i].period);

        t[i].remaining = 0;
        t[i].next_release = 0;
        t[i].deadline = t[i].period;
    }

    printf("\nEnter total simulation time: ");
    scanf("%d", &time_limit);

    int schedule[100];

    printf("\n--- EDF Scheduling ---\n");

    for (int time = 0; time < time_limit; time++) {

        // Release tasks
        for (int i = 0; i < n; i++) {
            if (time == t[i].next_release) {
                t[i].remaining = t[i].execution;
                t[i].deadline = time + t[i].period;
                t[i].next_release += t[i].period;
            }
        }

        int selected = -1;
        int earliest_deadline = 9999;

        for (int i = 0; i < n; i++) {
            if (t[i].remaining > 0 && t[i].deadline < earliest_deadline) {
                earliest_deadline = t[i].deadline;
                selected = i;
            }
        }

        if (selected != -1) {
            printf("Time %d: Task %d\n", time, t[selected].id);
            t[selected].remaining--;
            schedule[time] = t[selected].id;
        } else {
            printf("Time %d: Idle\n", time);
            schedule[time] = 0;
        }
    }

    printf("\n\nGantt Chart:\n|");
    for (int i = 0; i < time_limit; i++) {
        if (schedule[i] == 0)
            printf(" Idle |");
        else
            printf(" T%d |", schedule[i]);
    }

    printf("\n0");
    for (int i = 1; i <= time_limit; i++) {
        printf("    %d", i);
    }

    printf("\n");

    return 0;
}