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
    int target = 0;

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
        char *t_pos = strstr(bracket_close, "target");
        if (t_pos != NULL) {
            char *eq = strchr(t_pos, '=');
            if (eq != NULL) {
                target = (int)strtol(eq + 1, NULL, 10);
            }
        } else if (scanf(" target = %d", &target) != 1 && scanf(" %d", &target) != 1) {
            return 0;
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
        if (scanf("%d", &target) != 1) {
            return 0;
        }
    }

    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] == target) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }

    printf("%d,%d\n", first, last);
    return 0;
}
