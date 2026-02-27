#include <stdio.h>

int main() {
    int rows, cols, i, j;
    int matrix[10][10];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Row sums
    for(i = 0; i < rows; i++) {
        int rowSum = 0;
        for(j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        printf("Sum of row %d = %d\n", i + 1, rowSum);
    }

    // Column sums
    for(j = 0; j < cols; j++) {
        int colSum = 0;
        for(i = 0; i < rows; i++) {
            colSum += matrix[i][j];
        }
        printf("Sum of column %d = %d\n", j + 1, colSum);
    }

    return 0;
}
