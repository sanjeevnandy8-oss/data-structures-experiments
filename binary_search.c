#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target);

int main() {
    int arr[100], n, target, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements in sorted order:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &target);

    result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Element %d found at position %d\n", target, result + 1);
    else
        printf("Element %d not found in array\n", target);

    return 0;
}

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}
