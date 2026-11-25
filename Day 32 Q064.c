#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    if (n < 0) {
        n = -n;
    }
    int freq[10] = {0};
    if (n == 0) {
        freq[0] = 1;
    } else {
        while (n > 0) {
            int d = n % 10;
            freq[d]++;
            n /= 10;
        }
    }
    int max_count = freq[0];
    int ans = 0;
    for (int d = 1; d < 10; d++) {
        if (freq[d] > max_count) {
            max_count = freq[d];
            ans = d;
        }
    }
    printf("%d\n", ans);
    return 0;
}
