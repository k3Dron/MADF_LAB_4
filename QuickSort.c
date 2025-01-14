#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    char name[MAX];
    char roll_no[MAX];
    int age;
};

int partition(struct Student students[], int low, int high) {
    int pivot = students[low].age;
    int i = low;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (i <= high && students[i].age <= pivot);

        do {
            j--;
        } while (students[j].age > pivot);

        if (i >= j) break;

        struct Student temp = students[i];
        students[i] = students[j];
        students[j] = temp;
    }

    struct Student temp = students[low];
    students[low] = students[j];
    students[j] = temp;
    return j;
}

void quicksort(struct Student students[], int low, int high) {
    if (low < high) {
        int j = partition(students, low, high);
        quicksort(students, low, j - 1);
        quicksort(students, j + 1, high);
    }
}

int main() {
    int n;
    struct Student students[100];

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter the name of the %d'st student: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter the roll number of %s: ", students[i].name);
        scanf("%s", students[i].roll_no);
        printf("Enter the age of %s: ", students[i].name);
        scanf("%d", &students[i].age);
    }

    quicksort(students, 0, n - 1);

    printf("Sorted array by age:\n");
    printf("Name Roll Number\n");
    for (int i = 0; i < n; i++) {
        printf("%3s %3s %3d\n", students[i].name, students[i].roll_no, students[i].age);
    }

    return 0;
}
