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
    int trans[cols][rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[j][i] = mat[i][j];
        }
    }
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", trans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
