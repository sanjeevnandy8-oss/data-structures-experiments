#include <stdio.h>

#define ROW1 3
#define COL1 3
#define ROW2 3
#define COL2 3

void inputMatrix(int mat[][COL1], int row, int col, char name);
void multiplyMatrices(int m1[][COL1], int m2[][COL2], int result[][COL2]);
void displayMatrix(int mat[][COL2], int row, int col);

int main() {
    int m1[ROW1][COL1], m2[ROW2][COL2], result[ROW1][COL2];

    printf("Matrix 1 (%dx%d):\n", ROW1, COL1);
    inputMatrix(m1, ROW1, COL1, 'A');

    printf("\nMatrix 2 (%dx%d):\n", ROW2, COL2);
    inputMatrix(m2, ROW2, COL2, 'B');

    multiplyMatrices(m1, m2, result);

    printf("\nMatrix A:\n");
    displayMatrix(m1, ROW1, COL1);

    printf("\nMatrix B:\n");
    displayMatrix(m2, ROW2, COL2);

    printf("\nProduct of matrices (A * B):\n");
    displayMatrix(result, ROW1, COL2);

    return 0;
}

void inputMatrix(int mat[][COL1], int row, int col, char name) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c[%d][%d]: ", name, i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void multiplyMatrices(int m1[][COL1], int m2[][COL2], int result[][COL2]) {
    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COL1; k++)
                result[i][j] += m1[i][k] * m2[k][j];
        }
    }
}

void displayMatrix(int mat[][COL2], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%5d ", mat[i][j]);
        printf("\n");
    }
}
