#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n < 0) {
        n = -n;
    }
    long long prod = 1;
    int digits[20];
    int count = 0;
    int temp = n;
    while (temp > 0) {
        int d = temp % 10;
        if (d % 2 != 0) {
            prod *= d;
            digits[count++] = d;
        }
        temp /= 10;
    }
    if (count == 0) {
        printf("1 (no odd digits, assume 1)\n");
    } else {
        printf("%lld (", prod);
        for (int i = count - 1; i >= 0; i--) {
            printf("%d", digits[i]);
            if (i > 0) {
                printf("*");
            }
        }
        printf(")\n");
    }
    return 0;
}
