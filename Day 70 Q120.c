#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

    int new_word = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)s[i];
        if (isspace(ch)) {
            new_word = 1;
        } else {
            if (new_word && isalpha(ch)) {
                s[i] = (char)toupper(ch);
            }
            new_word = 0;
        }
    }

    printf("%s\n", s);
    return 0;
}
