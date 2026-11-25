#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int parse_bracket_array(const char *start, const char *end, int *arr, int max_len) {
    int count = 0;
    const char *p = start + 1;
    while (p < end && count < max_len) {
        while (p < end && (*p == ' ' || *p == ',' || *p == '\t')) {
            p++;
        }
        if (p < end) {
            char *next = NULL;
            arr[count++] = (int)strtol(p, &next, 10);
            if (next == p) {
                break;
            }
            p = next;
        }
    }
    return count;
}

int main() {
    char line[8192];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    int nums1[1005], nums2[1005];
    int m = 0, n = 0;

    const char *b1_open = strchr(line, '[');
    const char *b1_close = (b1_open != NULL) ? strchr(b1_open + 1, ']') : NULL;
    const char *b2_open = (b1_close != NULL) ? strchr(b1_close + 1, '[') : NULL;
    const char *b2_close = (b2_open != NULL) ? strchr(b2_open + 1, ']') : NULL;

    if (b1_open != NULL && b1_close != NULL && b2_open != NULL && b2_close != NULL) {
        m = parse_bracket_array(b1_open, b1_close, nums1, 1005);
        n = parse_bracket_array(b2_open, b2_close, nums2, 1005);
    } else {
        m = (int)strtol(line, NULL, 10);
        if (m < 0 || m > 1005 || scanf("%d", &n) != 1 || n < 0 || n > 1005) {
            return 0;
        }
        for (int i = 0; i < m; i++) {
            if (scanf("%d", &nums1[i]) != 1) {
                return 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &nums2[i]) != 1) {
                return 0;
            }
        }
    }

    int merged
