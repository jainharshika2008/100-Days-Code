#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    int bits[32];
    int idx = 0;
    unsigned int num = (unsigned int)n;
    while (num > 0) {
        bits[idx++] = num % 2;
        num /= 2;
    }
    for (int i = idx - 1; i >= 0; i--) {
        printf("%d", bits[i]);
    }
    printf("\n");
    return 0;
}
