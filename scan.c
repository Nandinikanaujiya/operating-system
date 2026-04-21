#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, head, disk_size, direction;
    int req[100];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(int i=0;i<n;i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &direction);

    sort(req, n);

    int total_seek = 0;

    if(direction == 1) { 
        for(int i=0;i<n;i++) {
            if(req[i] >= head) {
                total_seek += abs(req[i] - head);
                head = req[i];
            }
        }
        total_seek += abs((disk_size - 1) - head);
        head = disk_size - 1;

        for(int i=n-1;i>=0;i--) {
            if(req[i] < head) {
                total_seek += abs(req[i] - head);
                head = req[i];
            }
        }
    } else { 
        for(int i=n-1;i>=0;i--) {
            if(req[i] <= head) {
                total_seek += abs(req[i] - head);
                head = req[i];
            }
        }
        total_seek += abs(head - 0);
        head = 0;

        for(int i=0;i<n;i++) {
            if(req[i] > head) {
                total_seek += abs(req[i] - head);
                head = req[i];
            }
        }
    }

    printf("Total Seek Time (SCAN) = %d\n", total_seek);

    return 0;
}