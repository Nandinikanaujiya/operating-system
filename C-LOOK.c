#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, head, direction, seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter requests:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (1 = Right, 0 = Left): ");
    scanf("%d", &direction);

    sort(arr, n);

    int index;
    for(index = 0; index < n; index++) {
        if(arr[index] >= head)
            break;
    }

    if(direction == 1) {
        for(int i = index; i < n; i++) {
            seek += abs(head - arr[i]);
            head = arr[i];
        }
        if(index > 0) {
            seek += abs(head - arr[0]);
            head = arr[0];
        }
        for(int i = 1; i < index; i++) {
            seek += abs(head - arr[i]);
            head = arr[i];
        }
    } else {
        for(int i = index - 1; i >= 0; i--) {
            seek += abs(head - arr[i]);
            head = arr[i];
        }
        if(index < n) {
            seek += abs(head - arr[n - 1]);
            head = arr[n - 1];
        }
        for(int i = n - 2; i >= index; i--) {
            seek += abs(head - arr[i]);
            head = arr[i];
        }
    }

    printf("Total Seek Time (C-LOOK): %d\n", seek);

    return 0;
}