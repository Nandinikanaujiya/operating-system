#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, head, i, j, seek_time = 0;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the requests: ");
    for(i = 0; i < n; i++){
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    for(i = 0; i < n; i++){
        seek_time += abs(requests[i] - head);
        head = requests[i];
    }
    
    printf("Total seek time: %d\n", seek_time);
    
    return 0;
}