#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[256];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    long long n = 0;
    char *eq = strchr(line, '=');
    if (eq != NULL) {
        n = strtoll(eq + 1, NULL, 10);
    } else {
        n = strtoll(line, NULL, 10);
    }

    if (n <= 0) {
        printf("-1\n");
        return 0;
    }

    long long total = n * (n + 1) / 2;
    long long left_sum = 0;
    long long ans = -1;

    for (long long x = 1; x <= n; x++) {
        left_sum += x;
        long long right_sum = total - left_sum + x;
        if (left_sum == right_sum) {
            ans = x;
            break;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
