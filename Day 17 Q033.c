#include <stdio.h>
#include <math.h>

int main() {
    int n, original, temp, digits = 0;
    long long sum = 0;
    scanf("%d", &n);
    if (n < 0) {
        printf("Not Armstrong\n");
        return 0;
    }
    original = n;
    temp = n;
    if (temp == 0) {
        digits = 1;
    } else {
        while (temp > 0) {
            digits++;
            temp /= 10;
        }
    }
    temp = n;
    while (temp > 0) {
        int rem = temp % 10;
        long long power = 1;
        for (int i = 0; i < digits; i++) {
            power *= rem;
        }
        sum += power;
        temp /= 10;
    }
    if (sum == original) {
        printf("Armstrong\n");
    } else {
        printf("Not Armstrong\n");
    }
    return 0;
}
