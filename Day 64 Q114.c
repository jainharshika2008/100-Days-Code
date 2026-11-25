#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[4096];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    char s[4096];
    char *q1 = strchr(line, '"');
    char *q2 = (q1 != NULL) ? strrchr(line, '"') : NULL;

    if (q1 != NULL && q2 != NULL && q2 > q1) {
        size_t len = (size_t)(q2 - q1 - 1);
        if (len >= sizeof(s)) {
            len = sizeof(s) - 1;
        }
        memcpy(s, q1 + 1, len);
        s[len] = '\0';
    } else {
        line[strcspn(line, "\r\n")] = '\0';
        char *eq = strchr(line, '=');
        const char *src = (eq != NULL) ? (eq + 1) : line;
        while (*src == ' ' || *src == '\t') {
            src++;
        }
        snprintf(s, sizeof(s), "%s", src);
    }

    int last_idx[256];
    for (int i = 0; i < 256; i++) {
        last_idx[i] = -1;
    }

    int n = (int)strlen(s);
    int left = 0;
    int max_len = 0;

    for (int right = 0; right < n; right++) {
        unsigned char ch = (unsigned char)s[right];
        if (last_idx[ch] >= left) {
            left = last_idx[ch] + 1;
        }
        last_idx[ch] = right;
        int cur_len = right - left + 1;
        if (cur_len > max_len) {
            max_len = cur_len;
        }
    }

    printf("%d\n", max_len);
    return 0;
}
