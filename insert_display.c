#include <stdio.h>

#define MAX_SIZE 100

void insert(int arr[], int *size, int position, int value);
void display(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    int pos, val;
    printf("\nEnter position to insert (0-based): ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &val);

    insert(arr, &size, pos, val);
    printf("\nArray after insertion:\n");
    display(arr, size);

    return 0;
}

void insert(int arr[], int *size, int position, int value) {
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *size; i > position; i--)
        arr[i] = arr[i - 1];

    arr[position] = value;
    (*size)++;
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
