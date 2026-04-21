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
    int n, head, disk_size;
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

    sort(req, n);

    int total_seek = 0;


    for(int i=0;i<n;i++) {
        if(req[i] >= head) {
            total_seek += abs(req[i] - head);
            head = req[i];
        }
    }
    total_seek += abs((disk_size - 1) - head);
    head = disk_size - 1;

    total_seek += (disk_size - 1);
    head = 0;


    for(int i=0;i<n;i++) {
        if(req[i] < head) {
            total_seek += abs(req[i] - head);
            head = req[i];
        }
    }

    printf("Total Seek Time (C-SCAN) = %d\n", total_seek);

    return 0;
}