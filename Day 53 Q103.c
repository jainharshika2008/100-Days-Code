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
                nums[n++] = (int)strtol(p, &p, 10);
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

    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += nums[i];
    }

    long long left_sum = 0;
    int pivot = -1;
    for (int i = 0; i < n; i++) {
        long long right_sum = total_sum - left_sum - nums[i];
        if (left_sum == right_sum) {
            pivot = i;
            break;
        }
        left_sum += nums[i];
    }

    printf("%d\n", pivot);
    return 0;
}.c
