#include <stdio.h>

int main() {
    int n;
    double sum = 0.0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int num = 2 * i;
        int den = 4 * i - 1;
        sum += (double)num / den;
    }
    printf("Approximate sum: %.2f\n", sum);
    return 0;
}
