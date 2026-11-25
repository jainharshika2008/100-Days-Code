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
        printf("\n");
        return 0;
    }

    int neg_idx[1005];
    int front = 0, back = 0;
    int first_out = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            neg_idx[back++] = i;
        }
        while (front < back && neg_idx[front] <= i - k) {
            front++;
        }
        if (i >= k - 1) {
            if (!first_out) {
                printf(" ");
            }
            first_out = 0;
            if (front < back) {
                printf("%d", arr[neg_idx[front]]);
            } else {
                printf("0");
            }
        }
    }
    printf("\n");

    return 0;
}
