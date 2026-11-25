#include <stdio.h>

int main() {
    int counts[] = {1, 3, 5, 3, 1};
    int groups = 5;
    for (int g = 0; g < groups; g++) {
        for (int i = 0; i < counts[g]; i++) {
            printf("*\n");
        }
        if (g < groups - 1) {
            printf("\n");
        }
    }
    return 0;
}
