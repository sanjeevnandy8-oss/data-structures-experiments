#include <stdio.h>

#define MAX_SIZE 100

int delete(int arr[], int *size, int position);
void display(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    int pos;
    printf("\nEnter position to delete (0-based): ");
    scanf("%d", &pos);

    if (delete(arr, &size, pos)) {
        printf("\nArray after deletion:\n");
        display(arr, size);
    } else {
        printf("Deletion failed!\n");
    }

    return 0;
}

int delete(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return 0;
    }

    for (int i = position; i < *size - 1; i++)
        arr[i] = arr[i + 1];

    (*size)--;
    return 1;
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
