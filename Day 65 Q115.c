#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void extract_quoted_or_token(const char *src, char *dest, size_t dest_size) {
    const char *q1 = strchr(src, '"');
    if (q1 != NULL) {
        const char *q2 = strchr(q1 + 1, '"');
        if (q2 != NULL) {
            size_t len = (size_t)(q2 - q1 - 1);
            if (len >= dest_size) {
                len = dest_size - 1;
            }
            memcpy(dest, q1 + 1, len);
            dest[len] = '\0';
            return;
        }
    }
    while (*src == ' ' || *src == '\t' || *src == ',' || *src == '=') {
        src++;
    }
    size_t i = 0;
    while (src[i] != '\0' && src[i] != ' ' && src[i] != '\t' && src[i] != ',' && src[i] != '\r' && src[i] != '\n' && i + 1 < dest_size) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    char line[4096];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    char s[2048] = {0};
    char t[2048] = {0};

    const char *s_pos = strstr(line, "s");
    const char *t_pos = strstr(line, "t");

    if (s_pos != NULL && t_pos != NULL) {
        const char *s_eq = strchr(s_pos, '=');
        const char *t_eq = strchr(t_pos, '=');
        if (s_eq != NULL && t_eq != NULL) {
            extract_quoted_or_token(s_eq + 1, s, sizeof(s));
            extract_quoted_or_token(t_eq + 1, t, sizeof(t));
        }
    } else {
        extract_quoted_or_token(line, s, sizeof(s));
        const char *first_q2 = NULL;
        const char *q1 = strchr(line, '"');
        if (q1 != NULL) {
            first_q2 = strchr(q1 + 1, '"');
        }
        if (first_q2 != NULL) {
            extract_quoted_or_token(first_q2 + 1, t, sizeof(t));
        } else {
            char second_line[2048];
            if (fgets(second_line, sizeof(second_line), stdin) != NULL) {
                extract_quoted_or_token(second_line, t, sizeof(t));
            }
        }
    }

    int len_s = (int)strlen(s);
    int len_t = (int)strlen(t);

    if (len_s != len_t) {
        printf("Not Anagram\n");
        return 0;
    }

    int freq[26] = {0};
    for (int i = 0; i < len_s; i++) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            printf("Not Anagram\n");
            return 0;
        }
    }

    printf("Anagram\n");
    return 0;
}
