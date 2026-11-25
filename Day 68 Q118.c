#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[4096];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    int nums[1005];
    int n = 0;

    char *bracket_open = strchr(line, '[');
    char *bracket_close = strchr(line, ']');

    if (bracket_open != NULL && bracket_close != NULL) {
        char *p = bracket_open + 1;
        while (p < bracket_close) {
            while (p < bracket_close && (*p == ' ' || *p == ',' || *p == '\t')) {
                p++;
            }
            if (p < bracket_close) {
                char *next = NULL;
                nums[n++] = (int)strtol(p, &next, 10);
                if (next == p) {
                    break;
                }
                p = next;
            }
        }
    } else {
        n = (int)strtol(line, NULL, 10);
        if (n <= 0 || n > 1005) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &nums[i]) != 1) {
                return 0;
            }
        }
    }

    long long expected_sum = (long long)n * (n + 1) / 2;
    long long actual_sum = 0;
    for (int i = 0; i < n; i++) {
        actual_sum += nums[i];
    }

    long long missing = expected_sum - actual_sum;
    printf("%lld\n", missing);

    return 0;
}
