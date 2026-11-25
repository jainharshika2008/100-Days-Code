#include <stdio.h>

int main() {
    int n;
    long long prod = 1;
    int first = 1;
    scanf("%d", &n);
    for (int i = 2; i <= n; i += 2) {
        prod *= i;
    }
    printf("%lld (", prod);
    for (int i = 2; i <= n; i += 2) {
        if (!first) {
            printf(" * ");
        }
        printf("%d", i);
        first = 0;
    }
    printf(")\n");
    return 0;
}
