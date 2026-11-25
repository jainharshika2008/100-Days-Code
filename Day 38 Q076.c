#include <stdio.h>

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int mat[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    if (rows != cols) {
        printf("False\n");
        return 0;
    }
    int symmetric = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            if (mat[i][j] != mat[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (!symmetric) {
            break;
        }
    }
    if (symmetric) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}
