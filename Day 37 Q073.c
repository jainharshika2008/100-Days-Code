#include <stdio.h>

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int mat[rows][cols];
    int rowSum[rows];
    for (int i = 0; i < rows; i++) {
        rowSum[i] = 0;
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
            rowSum[i] += mat[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", rowSum[i]);
    }
    printf("\n");
    return 0;
}
