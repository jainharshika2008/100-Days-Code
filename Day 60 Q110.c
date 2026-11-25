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

    int dq[1005];
    int front = 0, back = 0;
    int first_out = 1;

    for (int i = 0; i < n; i++) {
        while (front < back && dq[front] <= i - k) {
            front++;
        }
        while (front < back && arr[dq[back - 1]] <= arr[i]) {
            back--;
        }
        dq[back++] = i;

        if (i >= k - 1) {
            if (!first_out) {
                printf(" ");
            }
            first_out = 0;
            printf("%d", arr[dq[front]]);
        }
    }
    printf("\n");

    return 0;
}
