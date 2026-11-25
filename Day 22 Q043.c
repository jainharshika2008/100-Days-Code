#include <stdio.h>

int main() {
    int n, original, sum = 0;
    scanf("%d", &n);
    original = n;
    if (n <= 0) {
        printf("Not strong number\n");
        return 0;
    }
    while (n > 0) {
        int digit = n % 10;
        int fact = 1;
        for (int i = 1; i <= digit; i++) {
            fact *= i;
        }
        sum += fact;
        n /= 10;
    }
    if (sum == original) {
        printf("Strong number\n");
    } else {
        printf("Not strong number\n");
    }
    return 0;
}
