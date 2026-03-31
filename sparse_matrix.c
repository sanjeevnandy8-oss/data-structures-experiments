#include <stdio.h>

#define N 4

typedef struct {
    int row;
    int col;
    int value;
} SparseElement;

void inputMatrix(int mat[][N], int n);
int isSparseMatrix(int mat[][N], int n);
void storeNonzeroElements(int mat[][N], int n, SparseElement alt[]);
void displaySparseElements(SparseElement alt[], int size);

int main() {
    int mat[N][N];
    SparseElement alt[N * N];

    printf("Enter elements for %dx%d matrix:\n", N, N);
    inputMatrix(mat, N);

    if (isSparseMatrix(mat, N)) {
        printf("\nMatrix is sparse!\n");
        storeNonzeroElements(mat, N, alt);
        printf("\nNon-zero elements stored in alternate matrix:\n");
        displaySparseElements(alt, N * N);
    } else {
        printf("\nMatrix is not sparse.\n");
    }

    return 0;
}

void inputMatrix(int mat[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

int isSparseMatrix(int mat[][N], int n) {
    int zeroCount = 0;
    int total = n * n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] == 0)
                zeroCount++;

    return (zeroCount > total / 2);
}

void storeNonzeroElements(int mat[][N], int n, SparseElement alt[]) {
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0) {
                alt[index].row = i;
                alt[index].col = j;
                alt[index].value = mat[i][j];
                index++;
            }
        }
    }

    for (int i = index; i < N * N; i++) {
        alt[i].row = -1;
        alt[i].col = -1;
        alt[i].value = 0;
    }
}

void displaySparseElements(SparseElement alt[], int size) {
    for (int i = 0; i < size; i++) {
        if (alt[i].row != -1) {
            printf("Element[%d]: Row=%d, Col=%d, Value=%d\n",
                   i, alt[i].row, alt[i].col, alt[i].value);
        }
    }
}
