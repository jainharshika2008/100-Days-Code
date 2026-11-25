#include <stdio.h>

int main() {
    int rows, cols, sum = 0;
    scanf("%d %d", &rows, &cols);
    int mat[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    int limit = rows < cols ? rows : cols;
    for (int i = 0; i < limit; i++) {
        sum += mat[i][i];
    }
    printf("%d\n", sum);
    return 0;
}
