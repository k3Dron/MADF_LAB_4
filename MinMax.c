#include <stdio.h>

char *arr[100];
int n ;

void MinMax(int i, int j, char **min, char **max) {
    if (i == j) {
        *min = *max = arr[i];
    } else if (i == j - 1) {
        if (strcmp(arr[i], arr[j]) > 0) {
            *min = arr[j];
            *max = arr[i];
        } else {
            *min = arr[i];
            *max = arr[j];
        }
    } else {
        int mid = (i + j) / 2;
        char *min1, *max1;
        MinMax(i, mid, &min1, &max1);
        MinMax(mid + 1, j, min, max);
        if (strcmp(min1, *min) < 0) *min = min1;
        if (strcmp(max1, *max) > 0) *max = max1;
    }
}

int main() {
    printf("Enter the number of strings in the array : ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(100 * sizeof(char));
        printf("Enter the %d'th string : ", i+1);
        scanf("%s", arr[i]);
    }
    char *min, *max;
    MinMax(0, n - 1, &min, &max);
    
    printf("Minimum: %s\n", min);
    printf("Maximum: %s\n", max);
    
    return 0;
}
