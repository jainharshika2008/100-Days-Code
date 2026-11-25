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
    int limit = rows < cols ? rows : cols;
    int distinct = 1;
    for (int i = 0; i < limit; i++) {
        for (int j = i + 1; j < limit; j++) {
            if (mat[i][i] == mat[j][j]) {
                distinct = 0;
                break;
            }
        }
        if (!distinct) {
            break;
        }
    }
    if (distinct) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}
