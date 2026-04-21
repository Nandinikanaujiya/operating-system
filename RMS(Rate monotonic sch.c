#include <stdio.h>

#define MAX 10

typedef struct {
    int id;
    int period;
    int execution;
    int remaining;
    int next_release;
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
    }

    printf("\nEnter total simulation time: ");
    scanf("%d", &time_limit);

    printf("\n--- RMS Scheduling ---\n");

    for (int time = 0; time < time_limit; time++) {

        for (int i = 0; i < n; i++) {
            if (time == t[i].next_release) {
                t[i].remaining = t[i].execution;
                t[i].next_release += t[i].period;
            }
        }

        int selected = -1;
        int min_period = 9999;

        for (int i = 0; i < n; i++) {
            if (t[i].remaining > 0 && t[i].period < min_period) {
                min_period = t[i].period;
                selected = i;
            }
        }

        if (selected != -1) {
            printf("Time %d: Task %d\n", time, t[selected].id);
            t[selected].remaining--;
        } else {
            printf("Time %d: Idle\n", time);
        }
    }

    return 0;
}