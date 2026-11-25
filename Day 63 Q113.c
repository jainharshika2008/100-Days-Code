#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int compare_ints(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

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
        return 0;
    }

    qsort(arr, (size_t)n, sizeof(int), compare_ints);
    printf("%d\n", arr[k - 1]);
    return 0;
}
