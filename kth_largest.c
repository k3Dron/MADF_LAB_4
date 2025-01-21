#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
char* arr[MAX];
int k;
int n;
int pass;

void swap(int i, int j) {
    char* temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int start, int end) {
    char* pivot = arr[start];
    int i = start + 1;
    int j = end;
    while (1) {
        while (i <= end && strcmp(arr[i], pivot) < 0) i++;
        while (j >= start && strcmp(arr[j], pivot) > 0) j--;
        if (i >= j) break;
        swap(i, j);
    }
    swap(start, j);
    printf("At Pass %d: j = %d , element = %s\n", pass++, j, arr[j]);
    return j;
}

char* kthLargest(int start, int end) {
    printf("The time during which kth Largest function was called is %ld seconds\n", time(NULL));
    if (start <= end) {
        int j = partition(start, end);
        if (k == j + 1) {            
            printf("The time at which kth Largest function got completed is %ld seconds\n", time(NULL));
            return arr[j];
            }
        if (k < j + 1) return kthLargest(start, j - 1);
        else return kthLargest(j + 1, end);
    }
    return NULL;
}



void main() {
    pass = 1;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        arr[i] = (char*)malloc(MAX * sizeof(char));
        scanf("%s", arr[i]);
    }
    printf("Enter the position of the element (largest): ");
    scanf("%d", &k);
    char* largest = kthLargest(0, n - 1);
    printf("The %d-th largest element is %s\n", k, largest);
}
