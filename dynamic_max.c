#include <stdio.h>
#include <stdlib.h>

void findLargest(int *arr, int size, int *max);
void inputDynamicArray(int **arr, int *size);

int main() {
    int *numbers = NULL;
    int size, max;

    inputDynamicArray(&numbers, &size);
    findLargest(numbers, size, &max);

    printf("\nLargest element: %d\n", max);

    free(numbers);
    return 0;
}

void inputDynamicArray(int **arr, int *size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);

    *arr = (int *)malloc((*size) * sizeof(int));

    if (*arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter %d numbers:\n", *size);
    for (int i = 0; i < *size; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", (*arr + i));
    }
}

void findLargest(int *arr, int size, int *max) {
    *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max)
            *max = arr[i];
    }
}
