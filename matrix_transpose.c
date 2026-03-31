#include <stdio.h>

#define SIZE 4

void inputMatrix(int mat[][SIZE], int n);
void transposeMatrix(int mat[][SIZE], int trans[][SIZE], int n);
void displayMatrix(int mat[][SIZE], int n);

int main() {
    int mat[SIZE][SIZE], trans[SIZE][SIZE];

    printf("Enter elements for %dx%d matrix:\n", SIZE, SIZE);
    inputMatrix(mat, SIZE);

    transposeMatrix(mat, trans, SIZE);

    printf("\nOriginal Matrix:\n");
    displayMatrix(mat, SIZE);

    printf("\nTranspose Matrix:\n");
    displayMatrix(trans, SIZE);

    return 0;
}

void inputMatrix(int mat[][SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void transposeMatrix(int mat[][SIZE], int trans[][SIZE], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            trans[j][i] = mat[i][j];
}

void displayMatrix(int mat[][SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d ", mat[i][j]);
        printf("\n");
    }
}
