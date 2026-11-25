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
    int x = 0;

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
        char *x_pos = strstr(bracket_close, "x");
        if (x_pos != NULL) {
            char *eq = strchr(x_pos, '=');
            if (eq != NULL) {
                x = (int)strtol(eq + 1, NULL, 10);
            }
        } else if (scanf(" x = %d", &x) != 1 && scanf(" %d", &x) != 1) {
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
        if (scanf("%d", &x) != 1) {
            return 0;
        }
    }

    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}
