#include <stdio.h>

void mergeSortedArrays(int A[], int B[], int C[], int m, int n);
void displayArray(int arr[], int size);

int main() {
    int A[5], B[5], C[10];

    printf("Enter 5 elements for array A (sorted):\n");
    for (int i = 0; i < 5; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    printf("Enter 5 elements for array B (sorted):\n");
    for (int i = 0; i < 5; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    mergeSortedArrays(A, B, C, 5, 5);

    printf("\nArray A: ");
    displayArray(A, 5);

    printf("Array B: ");
    displayArray(B, 5);

    printf("Merged Array C: ");
    displayArray(C, 10);

    return 0;
}

void mergeSortedArrays(int A[], int B[], int C[], int m, int n) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (A[i] <= B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while (i < m)
        C[k++] = A[i++];

    while (j < n)
        C[k++] = B[j++];
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
