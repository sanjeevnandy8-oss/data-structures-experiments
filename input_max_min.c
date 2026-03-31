#include <stdio.h>

#define SIZE 10

void inputArray(int arr[], int size);
int MAX(int arr[], int size);
int MIN(int arr[], int size);

int main() {
    int numbers[SIZE];

    printf("Enter 10 numbers:\n");
    inputArray(numbers, SIZE);

    printf("\nMaximum number: %d\n", MAX(numbers, SIZE));
    printf("Minimum number: %d\n", MIN(numbers, SIZE));

    return 0;
}

void inputArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int MAX(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int MIN(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}
