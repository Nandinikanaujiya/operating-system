#include <stdio.h>
#include <stdbool.h>

bool lock = false;
bool waiting[10];

bool TestAndSet(bool *lock) {
    bool old = *lock;
    *lock = true;
    return old;
}

void process(int i, int n) {
    bool key;
    int j;

    do {
        waiting[i] = true;
        key = true;

        while (waiting[i] && key)
            key = TestAndSet(&lock);

        waiting[i] = false;

        printf("Process P%d in Critical Section\n", i);

        j = (i + 1) % n;

        while ((j != i) && !waiting[j])
            j = (j + 1) % n;

        if (j == i)
            lock = false;
        else
            waiting[j] = false;

        printf("Process P%d in Remainder Section\n", i);

        break;

    } while (true);
}

int main() {
    int n = 5;

    for (int i = 0; i < n; i++)
        waiting[i] = false;

    for (int i = 0; i < n; i++)
        process(i, n);

    return 0;
}

