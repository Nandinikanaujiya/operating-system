#include <stdio.h>
#include <stdbool.h>

bool lock = false;

bool TestAndSet(bool *lock) {
    bool old = *lock;
    *lock = true;
    return old; 
}

void criticalSection(int i) {
    printf("Process P%d is in Critical Section\n", i);
}

void remainderSection(int i) {
    printf("Process P%d is in Remainder Section\n", i);
}

void process(int i) {
    while (TestAndSet(&lock))
        ;  

    criticalSection(i);

    lock = false;

    remainderSection(i);
}

int main() {
    int n = 5;

    for (int i = 0; i < n; i++) {
        process(i);
    }

    return 0;
}
