#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[4096];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    int arr[1005];
    int n = 0;
    int k = 0;

    char *bracket_open = strchr(line, '[');
    char *bracket_close = strchr(line, ']');

    if (bracket_open != NULL && bracket_close != NULL) {
        char *p = bracket_open + 1;
        while (p < bracket_close) {
            while (p < bracket_close && (*p == ' ' || *p == ',' || *p == '\t')) {
                p++;
            }
            if (p < bracket_close) {
                arr[n++] = (int)strtol(p, &p, 10);
            }
        }
        char *k_pos = strstr(bracket_close, "k");
        if (k_pos != NULL) {
            char *eq = strchr(k_pos, '=');
            if (eq != NULL) {
                k = (int)strtol(eq + 1, NULL, 10);
            }
        } else if (scanf(" k = %d", &k) != 1 && scanf(" %d", &k) != 1) {
            return 0;
        }
    } else {
        n = (int)strtol(line, NULL, 10);
        if (n <= 0 || n > 1005) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &arr[i]) != 1) {
                return 0;
            }
        }
        if (scanf("%d", &k) != 1) {
            return 0;
        }
    }

    if (n <= 0 || k <= 0 || k > n) {
        printf("0\n");
        return 0;
    }

    long long window_sum = 0;
    for (int i = 0; i < k; i++) {
        window_sum += arr[i];
    }

    long long max_sum = window_sum;
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum) {
            max_sum = window_sum;
        }
    }

    printf("%lld\n", max_sum);
    return 0;
}
